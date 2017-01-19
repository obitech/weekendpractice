# run 'make' to compile
# rum 'make clean' to delete object and binary file(s)

CC=cc
CFLAGS=-c -Wall -Werror

all: rotx

rotx: rotx_main.o rotx_cipher.o
	$(CC) rotx_main.o rotx_cipher.o -o rotx

rotx_cipher.o: rotx_main.c
	$(CC) $(CFLAGS) rotx_cipher.c

rotx_main.o: rotx_main.c
	$(CC) $(CFLAGS) rotx_main.c

clean:
	rm *.o rotx