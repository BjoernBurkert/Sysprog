# Makefile

# Kommando-Variablen

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic 
CPPFLAGS = -I../lib
LDFLAGS = -L../lib
RM = rm -f

# Musterregeln
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Standardziele
.PHONY: all clean
all: notenspiegel

clean:
	rm -f notenspiegel notenspiegel.o depend

depend: notenspiegel.c 
	$(CC) $(CPPFLAGS) -MM notenspiegel.c > $@


# Ziele zur Programmerstellung

notenspiegel: notenspiegel.o 
	gcc $(LDFLAGS) $^ -laufgabe6 -o $@

# Abhaengigkeiten
include depend

