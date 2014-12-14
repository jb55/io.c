

#include "io.h"

#ifndef IO_FILE_READER
#define IO_FILE_READER 1

io_reader *
file_io_reader(const char* filename, const char* mode);

int
file_reader_open(void *ctx);

int
file_reader_close(void *ctx);

int
file_reader_write(void *ctx, void *data, size_t len);


#endif
