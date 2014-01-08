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
	./a.out < input2 > myoutput
	diff myoutput output2 || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)
	./a.out < input3 > myoutput
	diff myoutput output3 || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)
	./a.out < input4 > myoutput
	diff myoutput output4 || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)
	./a.out < input5 > myoutput
	diff myoutput output5 || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)
	./a.out < input6 > myoutput
	diff myoutput output6 || (echo NG && rm myoutput && false) && (echo OK && rm myoutput)
#	./a.out

clean:
	rm ./a.out

