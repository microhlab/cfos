CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
INC = -I/home/chientran/works/chienos/libc/include -I/home/chientran/works/chienos/kernel/include 
CC = i386-linux-gcc $(CFLAGS) $(INC)
OBJS = kernel/kernel.o shell/shell.o

all: $(OBJS)
	cp kernel/kernel.o kernel.o
	cp shell/shell.o shell.o

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -f */*.o *.o *.a