#include <stdio.h>
#include "writer.h"
#include "reader.h"
#include "errors.h"
#include "copy.h"

int io_copy(io_reader *src, io_writer *dst, int64_t *written) {
  char buffer[DEF_READ_SIZE];
  int err = IO_OK;
  if (written) *written = 0;

  while (1) {
    int nr;
    int er = io_read(src, buffer, DEF_READ_SIZE, &nr);
    if (nr > 0) {
      int nw = 0;
      int ew = io_write(dst, buffer, nr, &nw);
      if (written && nw > 0) *written += nw;
      if (ew != IO_OK) {
        err = ew;
        break;
      }
      if (nw != nr) {
        err = IO_SHORT_WRITE;
        break;
      }
    }
    if (er == IO_EOF) break;
    if (er != IO_OK) {
      err = er;
      break;
    }
  }

  return err;
}

int64_t io_copy_n(io_writer *dst, io_reader *src, int64_t n);
