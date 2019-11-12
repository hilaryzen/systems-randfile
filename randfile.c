#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd;
  fd = open("/dev/random", 0_RDONLY);

  return 0;
}
