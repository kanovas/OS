
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
  size_t offset = 0;
  size_t f = 0;
  ssize_t rr;
  while (f == 0 && (rr = read(fd, buf + offset, count)) > 0) {
    size_t i;
    for (i = offset; i < offset + rr && f == 0; ++i)
      if (*((char*)buf + i) == delimiter)
	f = 1;
    offset += rr;
  }
  return rr == -1 ? -1 : offset;
}
