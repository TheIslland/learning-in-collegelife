.PHONY: clean
CC = gcc
CFLAGS = -std=c99 -Wall -Werror

ncat : ncat.o roman.o
	gcc $(CFLAGS) -o ncat ncat.o roman.o

ncat.o : ncat.c roman.h
	gcc $(CFLAGS) -c ncat.c 
	
roman.o : roman.c roman.h
	gcc $(CFLAGS) -c roman.c

clean:
	$(RM) -- *.o ncat

