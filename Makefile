
SRC = $(filter-out test.c, $(wildcard *.c))
CFLAGS += -std=c99 -Wall
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)
SRC_OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

test: $(OBJS) $(SRC_OBJS)
	$(CC) test.c $(SRC_OBJS) $(OBJS) -Ideps $(CFLAGS) -o test
	./test

clean:
	rm -f test test.txt
	rm -f $(SRC_OBJS)
	rm -f $(OBJS)

.PHONY: test
