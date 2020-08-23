#include "fs.h"
#include "ext2_fs/ext2.h"

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int init_fs(const char *image_path) {
  current_fs = initialize_ext2(image_path);
  current_sb = current_fs->get_superblock(current_fs);
  return !(current_fs && current_sb);
}

struct file *openfile(char *path) {
  struct file *f = malloc(sizeof(struct file));
  f->f_path = malloc(strlen(path) + 1);
  strcpy(f->f_path, path);
  struct dentry *dir = pathwalk(path);
  if (!dir) {
    return NULL;
  }
  f->f_inode = dir->d_inode;
  free(dir);
  if (f->f_inode->f_op->open(f->f_inode, f)) {
    return NULL;
  }
  return f;
}

int closefile(struct file *f) {
  if (f->f_op->release(f->f_inode, f)) {
    printf("Error closing file\n");
  }
  free(f);
  f = NULL;
  return 0;
}

int readfile(struct file *f, char *buf, int size, loffset_t *offset) {
  if (*offset >= f->f_inode->i_size) {
    return 0;
  }
  if (*offset + size >= f->f_inode->i_size) {
    size = f->f_inode->i_size - *offset;
  }
  // May add llseek call
  return f->f_op->read(f, buf, size, offset);
}

struct dentry *pathwalk(char *path) {
  /* Allocates and returns a new dentry for a given path */
}

int statfile(struct dentry *d_entry, struct kstat *k_stat) {
  return d_entry->d_inode->i_op->getattr(d_entry, k_stat);
}
