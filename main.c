#include <stdio.h>
#include <stdlib.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int a = 4;
  int b = 5;

  switch(argc){
    case 1:
      break;
    case 2:
      printf("Deux paramètres requis.\n");
      return 2;
    case 3:
      a = atoi(argv[1]);
      b = atoi(argv[2]);
      break;
    default:
      printf("Deux paramètres sont nécessaires. \n");
      return -1;
  }

  printf("%d, %d\n", a, b);
  echange(&a, &b);
  printf("%d, %d\n", a, b);
  return 0;
}

void echange(int* a,int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
