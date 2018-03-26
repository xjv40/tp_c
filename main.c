#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  printf("%d\n", factorielle(5));
  return 0;
}

int factorielle(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorielle(n-1);
}
