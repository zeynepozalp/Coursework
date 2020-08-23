#ifndef _FS_H_
#define _FS_H_

#include <unistd.h>

/* Mode definitions */
#define S_IFMT 00170000
#define S_IFSOCK 0140000
#define S_IFLNK 0120000
#define S_IFREG 0100000
#define S_IFBLK 0060000
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFIFO 0010000
#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_ISVTX 0001000

/* Mode check macros */
#define S_ISLNK(m) (((m)&S_IFMT) == S_IFLNK)
#define S_ISREG(m) (((m)&S_IFMT) == S_IFREG)
#define S_ISDIR(m) (((m)&S_IFMT) == S_IFDIR)
#define S_ISCHR(m) (((m)&S_IFMT) == S_IFCHR)
#define S_ISBLK(m) (((m)&S_IFMT) == S_IFBLK)
#define S_ISFIFO(m) (((m)&S_IFMT) == S_IFIFO)
#define S_ISSOCK(m) (((m)&S_IFMT) == S_IFSOCK)

/* Permission definitions */
#define S_IRWXU 00700
#define S_IRUSR 00400
#define S_IWUSR 00200
#define S_IXUSR 00100

#define S_IRWXG 00070
#define S_IRGRP 00040
#define S_IWGRP 00020
#define S_IXGRP 00010

#define S_IRWXO 00007
#define S_IROTH 00004
#define S_IWOTH 00002
#define S_IXOTH 00001

typedef unsigned short umode_t;
typedef unsigned short fmode_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;
typedef long long loffset_t;
typedef unsigned long sector_t;
// Callback function used to report entries in a dirctory
typedef int (*filldir_t)(const char *name, int name_len, unsigned long ino);

struct file_system_type;
struct kstatfs;
struct kstat;
struct dentry;
struct file;
struct inode;
struct super_block;
struct file_operations;
struct inode_operations;
struct super_operations;

struct file_system_type {
  int file_descriptor; /* file descriptor of the image file containing the file
                          system */
  const char *name;    /* name of the file system */
  /* Pointer to function to get the superblock */
  struct super_block *(*get_superblock)(struct file_system_type *fs);
};

struct kstatfs {
  char *name;                       /* Name */
  unsigned short f_magic;           /* Magic number */
  long f_bsize;                     /* blocksize */
  sector_t f_blocks;                /* total blocks */
  sector_t f_bfree;                 /* free blocks */
  sector_t f_inodes;                /* total inodes */
  sector_t f_finodes;               /* free inodes */
  unsigned short f_inode_size;      /* inode size */
  unsigned short f_minor_rev_level; /* minor revision level */
  unsigned int f_rev_level;         /* revision level */
  long f_namelen;                   /* length of name */
};

struct kstat {
  unsigned long ino;     /* inode number */
  umode_t mode;          /* mode */
  unsigned int nlink;    /* number of links */
  uid_t uid;             /* user id */
  gid_t gid;             /* group id */
  loffset_t size;        /* size */
  unsigned int atime;    /* access time */
  unsigned int mtime;    /* modify time */
  unsigned int ctime;    /* change time */
  unsigned long blksize; /* blocksize */
  unsigned long blocks;  /* number of blocks */
};

struct dentry {
  unsigned int d_flags;       /* Permissions */
  struct inode *d_inode;      /* Where the name belongs to - NULL is
                               * negative */
  struct dentry *d_parent;    /* parent directory */
  char *d_name;               /* Name */
  struct super_block *d_sb;   /* The root of the dentry tree */
  void *d_fsdata;             /* fs-specific data you can use this however
                               * you see fit */
  /* unsigned long d_time; */ /* Deletion time (not important for hw) */
};

struct file_operations {

  /* llseek: reposition read/write file offset for the file pointed by file
   * struct */
  loffset_t (*llseek)(struct file *, loffset_t, int);
  /* read: read contents of file pointed by file pointer into the buffer
   * provided by user */
  ssize_t (*read)(struct file *, char *, size_t, loffset_t *);
  /* open: reads the file poited by inode and fills the file struct. */
  int (*open)(struct inode *, struct file *);
  /* relase: used to close the file */
  int (*release)(struct inode *, struct file *);
};

struct file {
  char *f_path;                       /* File path */
  struct inode *f_inode;              /* inode of the file */
  const struct file_operations *f_op; /* pointer to file operations */
  unsigned int f_flags;               /* permissions */
  fmode_t f_mode;                     /* mode(type) of file */
  loffset_t f_pos;                    /* cursor offset of the file */
};

struct inode_operations {
  /* lookup: searches for the name of the passed in directory entry in the data
   * of the inode, if found it fills the rest of the directory entry. */
  struct dentry *(*lookup)(struct inode *, struct dentry *);
  /* readlink: reads the contents of the link itself */
  int (*readlink)(struct dentry *, char *, int);
  /* readdir: for every directory entry in data of passed in inode, it calls the
  callback function passed in with the second parameter. */
  int (*readdir)(struct inode *, filldir_t);
  /* getattr: fills in the kstat structure for the file pointed by the directory
   * entry */
  int (*getattr)(struct dentry *, struct kstat *);
};

struct inode {
  unsigned long i_ino;           /* inode number */
  umode_t i_mode;                /* mode */
  unsigned int i_nlink;          /* number of links */
  uid_t i_uid;                   /* user id */
  gid_t i_gid;                   /* group id */
  loffset_t i_size;              /* size */
  unsigned int i_atime;          /* access time */
  unsigned int i_mtime;          /* modify time */
  unsigned int i_ctime;          /* create time */
  unsigned long i_blocks;        /* Blocks count */
  unsigned int i_block[15];      /* Pointers to data blocks */
  struct inode_operations *i_op; /* inode operations */
  struct file_operations *f_op;  /* file operations */
  struct super_block *i_sb;      /* super_block pointer */
  unsigned long i_state;         /*  */
  unsigned int i_flags;          /* Permissions */
};

struct super_operations {
  /* struct inode *(*alloc_inode)(struct super_block *sb);
   * void (*destroy_inode)(struct inode *);*/
  /* read_inode: assumes the passed in inode has its inode number set correctly
   * and reads and populates the remaining fields of the passed in inode */
  void (*read_inode)(struct inode *);
  /* statfs: fills in the kstatfs struct */
  int (*statfs)(struct super_block *, struct kstatfs *);
};

struct super_block {
  unsigned int s_inodes_count;      /* Inodes count */
  unsigned int s_blocks_count;      /* Blocks count */
  unsigned int s_free_blocks_count; /* Free blocks count */
  unsigned int s_free_inodes_count; /* Free inodes count */
  unsigned int s_first_data_block;  /* First Data Block */
  unsigned long s_blocksize;        /* blocksize in bytes */
  unsigned char s_blocksize_bits;   /* log2(s_blocksize) */
  unsigned int s_blocks_per_group;  /* # Blocks per group */
  unsigned int s_inodes_per_group;  /* # Inodes per group */
  unsigned short s_minor_rev_level; /* minor revision level */
  unsigned int s_rev_level;         /* Revision level */
  unsigned int s_first_ino;         /* First non-reserved inode */
  unsigned short s_inode_size;      /* size of inode structure */
  unsigned short s_block_group_nr;  /* block group # of this superblock */
  unsigned long long s_maxbytes;    /* Max file size */
  struct file_system_type *s_type;  /* Pointer to file system type */
  struct super_operations *s_op;    /* Pointer to super operations */
  unsigned long s_flags;            /* */
  unsigned long s_magic;            /* Magic number */
  struct dentry *s_root;            /* Directory entry for root */
  void *s_fs_info;                  /* Filesystem private info */
};

/* Pointer to the registered file system type */
struct file_system_type *current_fs;
/* Pointer to the registered file system type's superblock */
struct super_block *current_sb;
/* Function to initialize the file system, sets the current_fs and current_sb */
int init_fs(const char *image_path);
/* Following functions assumes init_fs was succesfully called.*/
/* pathwalk: takes in an absolute path (i.e. starting from root) and returns the
 * directory entry for it */
struct dentry *pathwalk(char *path);
/* openfile: opens the file at path and returns a file struct */
struct file *openfile(char *path);
/* Function to close a file, do cleanup here */
int closefile(struct file *f);
/* readfile: reads the contents of the file pointed to by the file pointer into
 * the buffer. Amount read is limited by the size and the read starts at the
 * offset */
int readfile(struct file *f, char *buf, int size, loffset_t *offset);
/* statfile: fills in the passed in kstat struct with the information from
 * directory entry */
int statfile(struct dentry *, struct kstat *);

#endif
