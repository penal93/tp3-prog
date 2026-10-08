# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall -Wextra -g -std=c99 # flags de compilacao
CC = gcc

all: tp3.o racional.o
	$(CC) -o tp3 tp3.o racional.o auxiliar.o

auxiliar.o: auxiliar.c auxiliar.h
	$(CC) -c $(CFLAGS) auxiliar.c

racional.o: racional.c racional.h
	$(CC) -c $(CFLAGS) racional.c

tp3.o: tp3.c racional.h auxiliar.o
	$(CC) -c $(CFLAGS) tp3.c

clean:
	rm -f *.o *~ tp3
