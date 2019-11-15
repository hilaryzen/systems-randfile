#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  printf("Generating random numbers:\n");
  int fd;
  fd = open("/dev/urandom", O_RDONLY);
  int buff[10];
  read(fd, buff, 10 * sizeof(int));
  close(fd);
  int x = 0;
  for (x = 0; x < 10; x++) {
    printf("Random %d: %d\n", x, buff[x]);
  }

  printf("\nWriting numbers to file:\n");
  int fd_write;
  fd_write = open("numbers", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(fd_write, buff, 10 * sizeof(int));
  close(fd_write);

  printf("\nChecking random numbers:\n");
  int fd2;
  fd2 = open("numbers", O_RDONLY);
  int buff2[10];
  read(fd2, buff2, 10 * sizeof(int));
  close(fd2);
  int y = 0;
  for (y = 0; y < 10; y++) {
    printf("Random %d: %d\n", y, buff2[y]);
  }

  return 0;
}
