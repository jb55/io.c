
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tap.c/tap.h"
#include "io.h"
#include "filewriter.h"

int main (void) {
  plan(1);

  const char msg[] = "hello\n\n";
  struct io_writer *writer = file_io_writer("test.txt", "w");
  int size = sizeof(msg) - 1;
  int written = io_write(writer, (void*)msg, size);

  ok(written == size, "written %d == %d", written, size);
    
  io_writer_close(writer);
  done_testing();
}
