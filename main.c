#include <stdio.h>
#include <stdlib.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int T[5] = {0};
  int *p = T;

  int i;
  for (i = 0; i < 5; i++) {
    *(p+i) = i;
    printf("%d\n", *(p+i));
  }
  return 0;
}
