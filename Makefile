linguaggi: linguaggi.c Makefile
	gcc -ansi -Wall -O linguaggi.c -o linguaggi

pulisci:
	rm -f linguaggi.o

pulisci_tutto:
	rm -f linguaggi linguaggi.o
