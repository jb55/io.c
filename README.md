
# io.c

  ![](http://img.shields.io/badge/stability-experimental-orange.svg?style=flat)

  minimal io abstraction for c, inspired by go/io

  *warning* work in progress

## Installation

  Install with clib

    $ clib install jb55/io.c

## Motivation

Having abstract readers and writers will allow libraries to read and write data
from different sources using the same api.

Future: piping data to and from different sources, stream abstraction, etc

## Example

```c
#include "io/io.h"

int written;
io_writer *writer = file_io_writer("test.txt", "wb");
io_write(writer, (void*)msg, size, &written);
io_writer_close(writer);
```

## API

### int io_copy(io_reader \*src, io_writer \*dst, int64_t \*written)

returns an error code or IO_SUCCESS

### TODO

Finish docs

## License

  The MIT License (MIT)

  Copyright (c) 2014 William Casarin

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
