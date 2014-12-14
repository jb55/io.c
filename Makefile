
SRC = $(wildcard *.c)
CFLAGS += -std=c99 -Wall
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)
SRC_OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $< -I. -Ideps -c -o $@ $(CFLAGS)

test: test/test

test/test: $(OBJS) $(SRC_OBJS) test/filereader.o test/filewriter.o
	$(CC) test/test.c $^ -Ideps -I. $(CFLAGS) -o test/test
	@./test/test

clean:
	rm -f test/file{reader,writer}.o
	rm -f test/test
	rm -f $(SRC_OBJS)
	rm -f $(OBJS)

.PHONY: test/test test
