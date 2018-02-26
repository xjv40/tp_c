#include <stdio.h>
#include <stdlib.h>

#include "header/main.h"

int main(int argc, char *argv[]) {
  char saisie[100];
  
  printf("Veuillez saisir la chaine de caractere :\n");
  scanf("%s", &saisie);

  int i = 0;
  
  while (saisie[i] != '\0') {
    i++;
  }

  printf("%s\n", saisie);
  printf("%d\n", i);
  return 0;
}
