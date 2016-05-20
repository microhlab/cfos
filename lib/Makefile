CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
CC = i386-linux-gcc $(CFLAGS)
OBJS = console.o string.o printf.o

all: lib.a

lib.a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -f *.o *.a