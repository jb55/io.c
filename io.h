
#ifndef IO_H
#define IO_H 1

#include "stdlib.h"

#define IO_VERSION "0.0.1"

#define IO_NOT_OPEN -1

/* opaque handles to io writers and readers */
struct io_writer;

/* function pointers to the writer implementation */
typedef int (*io_writer_open_fn)(void*);
typedef int (*io_writer_close_fn)(void*);
typedef int (*io_writer_write_fn)(void*, void*, size_t);

/* a struct defining an io_writer implementation */
struct io_writer_def {
  io_writer_open_fn open;
  io_writer_close_fn close;
  io_writer_write_fn write;
};

/* io_writer function definitions */
struct io_writer *io_new_writer(struct io_writer_def *def, void *data);

int io_write(struct io_writer *writer, void* data, size_t len);
int io_writer_open(struct io_writer *writer);
int io_writer_close(struct io_writer *writer);

/* io_reader */
//struct io_reader;

/* function pointers to the reader implementation */
//typedef int (*io_reader_read_fn)(void*, size_t);

/* io_reader function definitions */
//struct io_reader *io_make_reader(struct io_reader_def *fn);



#endif
