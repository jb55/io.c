
#include "reader.h"
#include <stdio.h>

/* internal */
struct io_reader {
  io_reader_def_t def;
  void* ctx;
};

/* io_reader function definitions */
io_reader *io_new_reader(io_reader_def_t *def, void* ctx)
{
  io_reader *reader = malloc(sizeof (struct io_reader));
  reader->def.open = def->open;
  reader->def.close = def->close;
  reader->def.read = def->read;
  reader->ctx = ctx;
  def->open(ctx);
  return reader;
}

int
io_read(io_reader *reader, void* data, int len, int* read) {
  return reader->def.read(reader->ctx, data, len, read);
};

int io_reader_close(io_reader *reader)
{
  reader->def.close(reader->ctx);
  free(reader);
  return 0;
}
