CC = gcc
SRC = cat.c
C_FLAGS = -L../lib/ -I../lib/ -Wl,-R../lib/

all: cat

cat:
	$(CC) -o cat $(C_FLAGS) $(SRC) -lhelpers

clean:
	rm -rf cat
