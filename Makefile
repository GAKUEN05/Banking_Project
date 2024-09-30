CC=gcc
CFLAGS=-I.

# Targets
main: main.o lib.o
	$(CC) -o main main.o lib.o

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

lib.o: lib.c
	$(CC) -c lib.c $(CFLAGS)

clean:
	rm -f *.o main
