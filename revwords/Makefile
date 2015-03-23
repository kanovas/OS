CC = gcc
SRC = revwords.c
C_FLAGS = -L../lib/ -I../lib/ -Wl,-R../lib/

all: cat

cat:
	$(CC) -o revwords $(C_FLAGS) $(SRC) -lhelpers

clean:
	rm -rf revwords
