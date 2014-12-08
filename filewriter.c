
#include <stdio.h>
#include "filewriter.h"

struct file_writer_data {
  const char* filename;
  const char* mode;
  FILE *fd;
};

int
file_writer_open(void *ctx) {
  struct file_writer_data *fwd = (struct file_writer_data*)ctx;
  fwd->fd = fopen(fwd->filename, fwd->mode);
  return 0;
}

int
file_writer_close(void *ctx) {
  struct file_writer_data *fwd = (struct file_writer_data*)ctx;
  if (fwd->fd)
    fclose(fwd->fd);
  free(fwd);
  return 0;
}

int
file_writer_write(void* ctx, void *data, size_t len) {
  struct file_writer_data *fwd = (struct file_writer_data*)ctx;
  return fwrite(data, 1, len, fwd->fd);
}

struct io_writer *
file_io_writer(const char* filename, const char* mode)
{
  struct io_writer_def file_writer = {
    .open = file_writer_open,
    .close = file_writer_close,
    .write = file_writer_write
  };

  struct file_writer_data *fwd = malloc(sizeof (struct file_writer_data));
  fwd->filename = filename;
  fwd->mode = mode;
  fwd->fd = NULL;

  return io_new_writer(&file_writer, fwd);
};

