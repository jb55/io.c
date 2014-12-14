
#ifndef IO_READER_H
#define IO_READER_H 1

#include <stdlib.h>

/* opaque handles to io readers and readers */
typedef struct io_reader io_reader;

/* function pointers to the reader implementation */
typedef int (*io_reader_open_fn)(void*);
typedef int (*io_reader_close_fn)(void*);
typedef int (*io_reader_read_fn)(void*, void*, size_t, int*);

/* a struct defining an io_reader implementation */
typedef struct io_reader_def_t {
  io_reader_open_fn open;
  io_reader_close_fn close;
  io_reader_read_fn read;
} io_reader_def_t;

/* io_reader function definitions */
io_reader *io_new_reader(io_reader_def_t *def, void *data);

int
io_read(io_reader *reader, void* data, int len, int* read);

int
io_reader_open(io_reader *reader);

int
io_reader_close(io_reader *reader);

#endif
