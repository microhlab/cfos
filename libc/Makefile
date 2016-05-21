CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
INC = -I/home/chientran/works/chienos/libc/include
CC = i386-linux-gcc $(CFLAGS) $(INC)
OBJS = stdio/console.o string/string.o mem/mem.o stdio/keyboard.o

all: libc.a

libc.a: $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $^ -o $@

%.o: %.asm
	nasm -felf32 $^ -o $@

clean:
	rm -f */*.o *.a