CC=gcc
CFLAGS=-Wall -Wextra -g

SRC=main.c brainfuck.c
OBJ=$(SRC:.c=.o)
EXEC=brainfuck.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clear:
	rm -f $(OBJ) $(EXEC)
