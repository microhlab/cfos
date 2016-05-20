CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
INC = -I/home/chientran/works/chienos/lib
CC = i386-linux-gcc $(CFLAGS) $(INC)
OBJS = kernel.o

all: $(OBJS)

%.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -f *.o