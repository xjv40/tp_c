#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int pid = getpid();
  int ppid = getppid();

  printf("pid : %d\nppid : %d\n", pid, ppid);

  int fpid = fork();
  printf("%d\n", fpid);
  printf("\n\n\n\n\n\n");

  int i;
  for (i = 0; i < 100; i++) {
    printf("%d\n", i);
    sleep(0.5);
  }

  return 0;
}
