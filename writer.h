
#ifndef IO_WRITER_H
#define IO_WRITER_H 1

#include <stdlib.h>

/* opaque handles to io writers and readers */
typedef struct io_writer io_writer;

/* function pointers to the writer implementation */
typedef int (*io_writer_open_fn)(void*);
typedef int (*io_writer_close_fn)(void*);
typedef int (*io_writer_write_fn)(void*, void*, int, int*);

/* a struct defining an io_writer implementation */
typedef struct io_writer_def_t {
  io_writer_open_fn open;
  io_writer_close_fn close;
  io_writer_write_fn write;
} io_writer_def_t;

/* io_writer function definitions */
io_writer *io_new_writer(io_writer_def_t *def, void *data);

int io_write(io_writer *writer, void* data, int len, int* written);
int io_writer_open(io_writer *writer);
int io_writer_close(io_writer *writer);

#endif
