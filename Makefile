SHELL=/bin/sh
CC=gcc
CFLAGS=-O3 -g

default:	main

fila.o:	fila.c fila_publica.h fila_privada.h
	$(CC) $(CFLAGS) -c fila.c -o fila.o

main:	main.c main.o fila.o
	$(CC) $(CFLAGS) main.c fila.o -o main

clean:	
	rm -f main  *.o core a.out 

all:	main