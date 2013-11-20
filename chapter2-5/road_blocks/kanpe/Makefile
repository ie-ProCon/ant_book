#CFLAGS = -W -Wno-sign-compare
#CFLAGS = -W
CFLAGS = -W -O2
#CFLAGS = -g
#CC = gcc
CC = g++

all:
	$(CC) $(CFLAGS) -o a.out answer.cc

test:
	./a.out < input > myoutput
	diff myoutput output || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)

clean:
	rm ./a.out

