CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=gnu11
OBJS    = bit.o tests/test_bit.o

all: test_bit

test_bit: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: test_bit
	./test_bit

clean:
	rm -f $(OBJS) test_bit

.PHONY: all run clean