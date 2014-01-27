#CFLAGS = -W -Wno-sign-compare
#CFLAGS = -W
CFLAGS = -W -O2
#CFLAGS = -g
#CC = gcc
CC = g++

all:
	$(CC) $(CFLAGS) -o a.out solve.cpp

test:
	./a.out < input.txt

clean:
	rm ./a.out

