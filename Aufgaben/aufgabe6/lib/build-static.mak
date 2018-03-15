# Makefile build-static.mak

lib: fachnote.o liste.o
	gcc fachnote.o liste.o -o lib

fachnote.o: fachnote.c fachnote.h
	gcc -c fachnote.c
	
liste.o: liste.c liste.h
	gcc -c liste.c

# Kommando-Variablen

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
CPPFLAGS = -I.

RM = rm -f

# Hilfsvariablen

libaufgabe6
fachnote.o  liste.o
SOURCES = $(TARGET).c $(OBJECTS:.o=.c)
HEADERS = $ (OBJECTS:.o=.h)

# Musterregeln
fachnote.o: fachnote.c
	gcc -c $<
liste.o: liste.c
	gcc -c $<

# Explizite Regel
lib: fachnote.o liste.o
	ar rs ./libaufgabe6.a fachnote.o liste.o
	
fachnote.o : fachnote.c fachnote.h
liste.o	   : liste.c liste.h

# Standardziele
.PHONY: all clean
all: lib

lib: fachnote.o liste.o
	gcc -o lib fachnote.o liste.o
clean:
	rm -f lib fachnote.o liste.o
	
# Ziele zur Programmerstellung
$(TARGET): $(TARGET).o $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@
	
# Abhaengigkeiten
fachnote.o: fachnote.c fachnote.h
liste.o: liste.c liste.h
