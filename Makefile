CC=gcc
CFLAGS=-I.

# Targets
main: system.o lib.o
	$(CC) -o system system.o lib.o

main.o: main.c
	$(CC) -c system.cpp $(CFLAGS)

lib.o: lib.c
	$(CC) -c lib.c $(CFLAGS)

clean:
	rm -f *.o system
