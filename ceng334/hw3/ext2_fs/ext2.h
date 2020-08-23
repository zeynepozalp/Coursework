#ifndef _EXT2_H_
#define _EXT2_H_

#include "ext2_fs.h"
#include "vfs/fs.h"
#include <stdio.h>

struct file_system_type myfs;

struct file_system_type *initialize_ext2(const char *image_path);

#endif
