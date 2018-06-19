#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#include "header/sleep.h"

int main(int argc, char* argv[]) {
  signal(SIGUSR1, reveil);
  int pid = getpid();
  printf("PID : %d\nSleep.\n", pid);
  sleep(20);
  printf("Wake up\n");
}

void reveil(int numsig) {
  printf("Signal reçu : %d !\n", numsig);
}
