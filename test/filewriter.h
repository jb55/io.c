
#include "writer.h"

#ifndef IO_FILE_WRITER
#define IO_FILE_WRITER 1

io_writer *
file_io_writer(const char* filename, const char* mode);

int
file_writer_open(void *ctx);

int
file_writer_close(void *ctx);

int
file_writer_write(void *ctx, void *data, int len, int *written);


#endif
