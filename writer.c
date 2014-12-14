
#include "writer.h"
#include <stdio.h>

/* internal */
struct io_writer {
  io_writer_def_t def;
  void* ctx;
  int last_error;
};

/* io_writer function definitions */
io_writer*
io_new_writer(io_writer_def_t *def, void* ctx)
{
  struct io_writer *writer = malloc(sizeof (struct io_writer));
  writer->def.open = def->open;
  writer->def.close = def->close;
  writer->def.write = def->write;
  writer->ctx = ctx;
  def->open(ctx);
  return writer;
}

int
io_write(io_writer *writer, void* data, int len, int* written) {
  return writer->def.write(writer->ctx, data, len, written);
};

int
io_writer_close(io_writer *writer)
{
  writer->def.close(writer->ctx);
  free(writer);
  return 0;
}

