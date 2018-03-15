#
# Makefile
#



CC=gcc -g
CFLAGS = -W -Wall -ansi -pedantic

TARGET = filesize filecopy

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o

