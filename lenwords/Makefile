CC = gcc
SRC = lenwords.c
C_FLAGS = -L../lib/ -I../lib/ -Wl,-R../lib/

all: lenwords

lenwords:
	$(CC) -o lenwords $(C_FLAGS) $(SRC) -lhelpers

clean:
	rm -rf lenwords
