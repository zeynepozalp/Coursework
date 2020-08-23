#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ext2_fs/ext2.h"
#include "vfs/fs.h"

#define TOKENSIZE 64

int cat_func(char **argv, int argc);
int stat_func(char **argv, int argc);
int readlink_func(char **argv, int argc);
int help_func(char **argv, int argc);
int exit_func(char **argv, int argc);
int ls_func(char **argv, int argc);

char *cmd_str[] = {"cat", "ls", "stat", "readlink", "help", "exit"};

int (*cmd_func[])(char **, int) = {&cat_func,      &ls_func,   &stat_func,
                                   &readlink_func, &help_func, &exit_func};

char is_running = 1;

char *readline() {
  char *line = NULL;
  size_t bufsize = 0;
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(0); // We recieved an EOF
    } else {
      perror("readline");
      exit(1);
    }
  }
  return line;
}

char **splitline(char *line, int *argc) {
  int bufsize = TOKENSIZE;
  int position = 0;
  char *token;
  char **tokens = malloc(bufsize * sizeof(char *));

  if (!tokens) {
    fprintf(stderr, "malloc fail\n");
    exit(1);
  }
  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens[position] = token;
    position++;
    if (position >= bufsize) {
      bufsize += TOKENSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens) {
        fprintf(stderr, "malloc fail\n");
        exit(1);
      }
    }
    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[position] = NULL;
  *argc = position;
  return tokens;
}

int execute(char **argv, int argc) {
  int i;
  if (argv[0] == NULL) {
    return 0;
  }
  for (i = 0; i < sizeof(cmd_str) / sizeof(char *); i++) {
    if (strcmp(argv[0], cmd_str[i]) == 0) {
      return (*cmd_func[i])(argv, argc);
    }
  }
  return 0;
}

int print_dir(const char *name, int len, unsigned long ino) {
  printf("inode: %-10lu %s\n", ino, name);
  return 0;
}

int print_dir_details(const char *name, int len, unsigned long ino) {
  struct inode s_inode;
  s_inode.i_ino = ino;
  s_inode.i_sb = current_sb;
  current_sb->s_op->read_inode(&s_inode);
  printf("inode: %-10lu - perm: %d UID: %d, GID: %d, %u %s\n", s_inode.i_ino,
         s_inode.i_flags, s_inode.i_uid, s_inode.i_gid, s_inode.i_atime, name);
  return 0;
}

int ls_func(char **argv, int argc) {
  char *path = NULL;
  char flag = 0;
  switch (argc) {
  case 1: /* ls */
    path = ".";
    flag = 0;
    break;
  case 2: /* ls -l or ls <path> */
    if (strcmp(argv[1], "-l") == 0) {
      path = ".";
      flag = 1;
    } else {
      path = argv[1];
      flag = 0;
    }
    break;
  case 3: /* ls -l <path> */
    if (strcmp(argv[1], "-l") == 0) {
      flag = 1;
      path = argv[2];
    } else if (strcmp(argv[2], "-l") == 0) {
      path = argv[1];
      flag = 1;
    }
    break;
  }
  struct dentry *d = pathwalk(path);
  if (!d) {
    printf("Cannot find: %s\n", path);
    return 1;
  }
  struct inode *inode = d->d_inode;
  filldir_t callback = print_dir;
  if (flag) {
    callback = print_dir_details;
  }
  if (S_ISDIR(inode->i_mode)) {
    inode->i_op->readdir(inode, callback);
  } else if (S_ISREG(inode->i_mode)) {
    callback(path, strlen(path), inode->i_ino);
  }
  free(d);
  return 0;
}

int stat_func(char **argv, int argc) {
  struct dentry *d = pathwalk(argv[1]);
  if (!d) {
    printf("Cannot find: %s\n", argv[1]);
    return 1;
  }
  struct kstat stats;
  if (statfile(d, &stats)) {
    printf("Cannot get status of file!\n");
    free(d);
    return -1;
  }
  printf("Name: %s\n", d->d_name);
  printf("Inode num: %d, Mode: %u\n", stats.ino, stats.mode);
  printf("Nlink: %d\n", stats.nlink);
  printf("UID: %d, GID: %u\n", stats.uid, stats.gid);
  printf("Size: %d\n", stats.size);
  printf("Access: %u Modify: %u Create: %u\n", stats.atime, stats.mtime,
         stats.ctime);
  free(d);
  return 0;
}

int cat_func(char **argv, int argc) {
  struct file *f = openfile(argv[1]);
  if (f) {
    char content[2000];
    int r = 0;
    loffset_t totalread = 0;
    if (argv[2]) {
      totalread = atoll(argv[2]);
    }
    while ((r = readfile(f, content, 1024, &totalread))) {
      content[r] = 0;
      totalread += r;
      printf("%s", content);
    }
    closefile(f);
    return 0;
  }
  printf("Cannot open file %s", argv[1]);
  return 1;
}

int readlink_func(char **argv, int argc) {
  struct dentry *d = pathwalk(argv[1]);
  if (!d) {
    printf("Cannot find: %s\n", argv[1]);
    return 1;
  }
  char buf[256];
  int read = 0;
  read = d->d_inode->i_op->readlink(d, buf, 254);
  if (read < 0 && read > 254) {
    printf("readlink returned invalid value\n");
    free(d);
    return -1;
  }
  buf[read] = 0;
  printf("%s\n", buf);
  free(d);
  return 0;
}

int help_func(char **argv, int argc) {
  printf("Usage: <cmd_name> [args...]\n");
  printf("Supported commands\n");
  for (int i = 0; i < sizeof(cmd_str) / sizeof(char *); i++) {
    printf("  %s\n", cmd_str[i]);
  }
  printf("Every command takes absolute paths, relative paths not supported.\n");
  return 0;
}

int exit_func(char **arg_vector, int arg_count) {
  is_running = 0;
  close(current_sb->s_type->file_descriptor);
  return 0;
}

int fs_stats(struct super_block *sb) {
  struct kstatfs fs_stat;
  if (sb->s_op->statfs(sb, &fs_stat)) {
    printf("Cannot get status of fs!\n");
    return -1;
  }
  char fstype[fs_stat.f_namelen + 1];
  memcpy(fstype, fs_stat.name, fs_stat.f_namelen);
  fstype[fs_stat.f_namelen] = 0;
  printf("Mounted %s filesystem.\n", fstype);
  printf("Blocks: Total: %10lu Free: %10lu\n", fs_stat.f_blocks,
         fs_stat.f_bfree);
  printf("Inodes: Total: %10lu Free: %10lu\n", fs_stat.f_inodes,
         fs_stat.f_finodes);
  printf("Magic: %d\nInode size: %d\nMinorRev: %d, Rev: %d\n", fs_stat.f_magic,
         fs_stat.f_inode_size, fs_stat.f_minor_rev_level, fs_stat.f_rev_level);
  return 0;
}

int main(int arg_count, char **arg_vector) {
  if (arg_count != 2) {
    help_func(NULL, 0);
    exit(1);
  }
  if (init_fs(arg_vector[1])) {
    printf("Error initializing FS\n");
    exit(1);
  }
  fs_stats(current_sb);
  char *line;
  char **argv;
  int argc;
  int status = 0;
  while (is_running) {
    printf("> ");
    line = readline();
    argv = splitline(line, &argc);
    status = execute(argv, argc);
    if (status) {
      printf("Command returned with status %d\n", status);
    }
    free(line);
    free(argv);
  }

  return 0;
}
