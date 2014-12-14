
#include <stdio.h>
#include "filereader.h"

typedef struct file_reader_data_t {
  const char* filename;
  const char* mode;
  FILE *fd;
} file_reader_data_t;

int
file_reader_open(void *ctx) {
  file_reader_data_t *fwd = (file_reader_data_t*)ctx;
  fwd->fd = fopen(fwd->filename, fwd->mode);
  // TODO: handle errors
  return IO_OK;
}

int
file_reader_close(void *ctx) {
  file_reader_data_t *fwd = (file_reader_data_t*)ctx;
  if (fwd->fd)
    fclose(fwd->fd);
  free(fwd);
  // TODO: handle errors
  return IO_OK;
}

int
file_reader_read(void* ctx, void *data, size_t len, int* read) {
  file_reader_data_t *fwd = (file_reader_data_t*)ctx;
  int read_ = fread(data, 1, len, fwd->fd);
  if (read) *read = read_;
  if (feof(fwd->fd)) return IO_EOF;
  return IO_OK;
}

io_reader *
file_io_reader(const char* filename, const char* mode)
{
  io_reader_def_t file_reader = {
    .open = file_reader_open,
    .close = file_reader_close,
    .read = file_reader_read
  };

  file_reader_data_t *fwd = malloc(sizeof (file_reader_data_t));
  fwd->filename = filename;
  fwd->mode = !mode ? "rb" : mode;
  fwd->fd = NULL;

  return io_new_reader(&file_reader, fwd);
}

