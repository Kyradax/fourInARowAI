CC := clang
CFLAGS := -Wall -Wextra -pedantic -g

main: main.o array.o io.o
	$(CC) $(CFLAGS) -o main main.o array.o io.o

main.o: main.c array.h io.h
	$(CC) $(CFLAGS) -c main.c -o main.o

array.o: array.c array.h
	$(CC) $(CFLAGS) -c array.c -o array.o

io.o: io.c io.h array.h
	$(CC) $(CFLAGS) -c io.c -o io.o

clean:
	-rm -rf *.o main

