CFLAGS=-c -Wall -I include
VPATH=src1 src2 main
main:f1.o f2.o main.o
	
.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;rm f1 f2 main 
