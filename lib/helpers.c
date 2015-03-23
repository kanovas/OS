
#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
   size_t curr = 0;
    for( ; ;) {
        ssize_t rd = read(fd, buf + curr, count - curr);
        if (rd == -1)
            return -1;
        curr += rd;
        if (rd == 0)
            return curr;
    }
}

ssize_t write_(int fd, const void* buf, size_t count) {
  size_t curr = 0;
  for( ; ;) {
    ssize_t written = write(fd, buf + curr, count - curr);
    if (written == -1)
      return -1;
    curr += written;
    if (curr >= count)
      return curr;
  }
}


ssize_t read_until(int fd, void * buf, size_t count, char delimiter) {
    int curr, n;
    for (curr = 0; curr < count; curr++) {
        n = read(fd, buf + curr, 1);
        if (n == -1)
            return -1;
        if (n == 0)
            return curr;
        if ((((char*)buf)[curr]) == delimiter)
            return curr + 1;
    }

    return curr;
}

