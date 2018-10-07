CC = gcc
CFLAGS = -I./thirdpart/include -D TEST_FUNC -std=c11 -Wall -g
OBJS = main.o newton.o half_sqrt.o is_prime.o

.PHONY: clean

a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) thirdpart/libs/libtest.a
    
main.o : main.c
	$(CC) -c $(CFLAGS) main.c

newton.o : newton.c newton.h
	$(CC) -c $(CFLAGS) newton.c

half_sqrt.o : half_sqrt.c half_sqrt.h
	$(CC) -c $(CFLAGS) half_sqrt.c 

is_prime.o : is_prime.c is_prime.h
	$(CC) -c $(CFLAGS) is_prime.c
clean:
	rm -rf *.o a.out
