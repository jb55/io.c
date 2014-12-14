
#ifndef IO_COPY_H
#define IO_COPY_H 1

#include "writer.h"
#include "reader.h"

#define DEF_READ_SIZE 1024*32

int io_copy(io_reader *src, io_writer *dst, int64_t* written);

//int64_t io_copy_n(io_writer *dst, io_reader *src, int64_t n);

#endif
