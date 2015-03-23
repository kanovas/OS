#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <helpers.h>

const size_t BLOCK_SIZE = 4096;

void print_err() {
    char *msg = strerror(errno);
    write_(STDERR_FILENO, msg, strlen(msg));
}

void reverse(char *begin, char *end) {
    char tmp;
    while (end - begin > 0) {
        tmp = *begin;
        *begin = *end;
        *end = tmp;
        begin++;
        end--;
    }
}

int main() {
    char buffer[BLOCK_SIZE];
    int n;

    char delimeter = ' ';
    while ((n = read_until(STDIN_FILENO, buffer, BLOCK_SIZE, delimeter)) != 0) {
        if (n == -1) {
            print_err();
        }
        if (n == 0) {
            delimeter = '\n';
        }

        reverse(buffer, buffer + n - 1 - (buffer[n - 1] == delimeter));
        n = write_(STDOUT_FILENO, buffer, n);
        if (n == -1) {
            print_err();
        }
    }

    return 0;
}
