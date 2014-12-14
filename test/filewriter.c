
#include <stdio.h>
#include "filewriter.h"
#include "errors.h"

typedef struct file_writer_data_t {
  const char* filename;
  const char* mode;
  FILE *fd;
} file_writer_data_t;

int
file_writer_flush(void *ctx) {
  file_writer_data_t *fwd = (file_writer_data_t*)ctx;
  fwd->fd = fopen(fwd->filename, fwd->mode);
  return 0;
}

int
file_writer_open(void *ctx) {
  file_writer_data_t *fwd = (file_writer_data_t*)ctx;
  fwd->fd = fopen(fwd->filename, fwd->mode);
  return 0;
}

int
file_writer_close(void *ctx) {
  file_writer_data_t *fwd = (file_writer_data_t*)ctx;
  if (fwd->fd)
    fclose(fwd->fd);
  free(fwd);
  return 0;
}

int
file_writer_write(void* ctx, void *data, int len, int* written) {
  file_writer_data_t *fwd = (file_writer_data_t*)ctx;
  int wrote = fwrite(data, 1, len, fwd->fd);
  // We wouldn't actually do this, but this is just a test anyway
  // and we don't have bufio yet
  fflush(fwd->fd);
  if (written) *written = wrote;
  if (wrote < len) return IO_SHORT_WRITE;
  return IO_OK;
}

io_writer *
file_io_writer(const char* filename, const char* mode)
{
  io_writer_def_t file_writer = {
    .open = file_writer_open,
    .close = file_writer_close,
    .write = file_writer_write
  };

  file_writer_data_t *fwd = malloc(sizeof (file_writer_data_t));
  fwd->filename = filename;
  fwd->mode = mode;
  fwd->fd = NULL;

  return io_new_writer(&file_writer, fwd);
};

