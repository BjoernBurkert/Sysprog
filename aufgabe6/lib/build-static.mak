# Makefile build-static.mak

# Kommando-Variablen

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
CPPFLAGS = -I.

RM = rm -f

# Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Standardziele
.PHONY: all clean
all: libaufgabe6.a

clean:
	rm -f libaufgabe6.a fachnote.o liste.o

depend: fachnote.c fachnote.h liste.c liste.h
	$(CC) $(CPPFLAGS) -MM fachnote.c liste.c > $@

# Abhaengigkeiten
#fachnote.o: fachnote.c fachnote.h
#liste.o: liste.c liste.h fachnote.h

# Ziele zur Programmerstellung

libaufgabe6.a: fachnote.o liste.o
	ar rs libaufgabe6.a fachnote.o liste.o
