#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  printf("\nGenerating random numbers:\n");
  int fd;
  fd = open("/dev/random", O_RDONLY);
  if (fd == -1) {
    printf("Random did not open\n");
  }
  int buff[10];
  int returnVal = 0;
  returnVal = read(fd, buff, 10 * sizeof(int));
  if (returnVal == -1) {
    printf("Did not successfully read\n");
  }
  close(fd);
  int x = 0;
  for (x = 0; x < 10; x++) {
    printf("Random %d: %d\n", x, buff[x]);
  }

  printf("\nWriting numbers to file:\n");
  int fd_write;
  fd_write = open("numbers", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  if (fd_write == -1) {
    printf("Numbers did not open\n");
  }
  returnVal = write(fd_write, buff, 10 * sizeof(int));
  if (returnVal == -1) {
    printf("Did not successfully write\n");
  }
  close(fd_write);

  printf("\nChecking random numbers:\n");
  int fd2;
  fd2 = open("numbers", O_RDONLY);
  if (fd2 == -1) {
    printf("Numbers did not open\n");
  }
  int buff2[10];
  returnVal = read(fd2, buff2, 10 * sizeof(int));
  if (returnVal == -1) {
    printf("Did not successfully read\n");
  }
  close(fd2);
  int y = 0;
  for (y = 0; y < 10; y++) {
    printf("Random %d: %d\n", y, buff2[y]);
  }

  return 0;
}
