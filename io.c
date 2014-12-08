
#include "io.h"
#include <stdio.h>

/* internal */
struct io_writer {
  struct io_writer_def def;
  void* ctx;
  int opened:1;
};

/* io_writer function definitions */
struct io_writer *io_new_writer(struct io_writer_def *def, void* ctx)
{
  struct io_writer *writer = malloc(sizeof (struct io_writer));
  writer->def.open = def->open;
  writer->def.close = def->close;
  writer->def.write = def->write;
  writer->ctx = ctx;
  def->open(ctx);
  return writer;
}

int io_write(struct io_writer *writer, void* data, size_t len) {
  return writer->def.write(writer->ctx, data, len);
};

int io_writer_close(struct io_writer *writer)
{
  writer->def.close(writer->ctx);
  free(writer);
  return 0;
}

