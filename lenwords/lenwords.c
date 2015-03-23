#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <helpers.h>
#include <stdio.h>

const size_t BLOCK_SIZE = 4096;

void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}

int main() {
    char buffer[BLOCK_SIZE];
    char out[5];
    int n;
    char space = ' ';
    char enter[1];
    *enter = '\n';

    while ((n = read_until(STDIN_FILENO, buffer, BLOCK_SIZE, space)) != 0) {
        if (n == -1) {
            print_err();
        }

        int char_num = sprintf(out, "%d ", n - 1);
        if (char_num == -1) {
            print_err();
        }

	int write_err = write_(STDOUT_FILENO, out, char_num);
	if (write_err == -1) {
	    print_err();
	}
    }
    write_(STDOUT_FILENO, enter, 1);
    return 0;
}

