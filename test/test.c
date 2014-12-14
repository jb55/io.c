
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tap.c/tap.h"
#include "io.h"
#include "filewriter.h"
#include "filereader.h"
#include "mkdirp/mkdirp.h"

static void copy_test();

int main (void) {
  plan(6);

  const char msg[] = "hello";
  char buffer[32];
  int written, read;
  int err;

  mkdirp("var", 0755);

  io_writer *writer = file_io_writer("var/test.txt", "wb");
  io_reader *reader = file_io_reader("var/test.txt", "rb");

  int size = sizeof(msg) - 1;

  // write some data
  err = io_write(writer, (void*)msg, size, &written);
  ok(err == IO_OK, "io_write shouldn't err %d == %d", err, IO_OK);
  ok(written == size, "written %d == %d", written, size);

  // read it back
  err = io_read(reader, buffer, size, &read);
  ok(err == IO_OK, "io_read shouldn't err %d == %d", err, IO_OK);
  ok(memcmp(buffer, msg, size) == 0, "io_read correct contents %d == %d", read, size);

  // attempting to read more gives EOF
  err = io_read(reader, buffer, 1, &read);
  ok(err == IO_EOF, "io_read should eof %d == %d", err, IO_EOF);

  // clean up
  io_reader_close(reader);
  io_writer_close(writer);

  copy_test();

  done_testing();
}

void copy_test() {
  io_reader *src = file_io_reader("var/test.txt", "rb");
  io_writer *dst = file_io_writer("var/test_copied.txt", "wb");

  int64_t written;
  int err = io_copy(src, dst, &written);

  ok(err == IO_OK, "copy error %d == %d", err, IO_OK);
  ok(written == 5, "copy wrote %d == 5", written);

  io_reader_close(src);
  io_writer_close(dst);
}
