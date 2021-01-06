CC=gcc
AR=ar
CFLAGS=-Wall -g
PHONY=all clean
PROGS=main

.PHONY: $(PHONY)

all: main

main: main.o myBank.o
	$(CC) $(CFLAGS) main.o myBank.o -o main

main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

clean:
	rm -f *.o $(PROGS)