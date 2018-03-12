#include <stdio.h>
#include <stdlib.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int tableau[] = {5,52,13,2,0};
  int compteur = afficheTableau(tableau);
  printf("Nb d'éléments du tableau : %d\n", compteur);
  return 0;
}

int afficheTableau(int *tableau) {
  int i = 0;
  while (*(tableau + i) != 0) {
    printf("%d : %d\n", i, *(tableau + i));
    i += 1;
  }
  return i;
}
