# Makefile

# Kommando-Variablen

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic -c -fpic $s
CPPFLAGS = -I.

RM = rm -f

LIBTYPE=a
# Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Standardziele
.PHONY: all clean
all: libaufgabe6.$(LIBTYPE)

clean:
	rm -f libaufgabe6.a libaufgabe6.so fachnote.o liste.o

depend: fachnote.c fachnote.h liste.c liste.h
	$(CC) $(CPPFLAGS) -MM fachnote.c liste.c > $@

# Abhaengigkeiten
include depend

# Ziele zur Programmerstellung

libaufgabe6.so: fachnote.o liste.o
	gcc -shared fachnote.o liste.o -o libaufgabe5.so
libaufgabe6.a: fachnote.o liste.o
	ar rs libaufgabe6.a fachnote.o liste.o


