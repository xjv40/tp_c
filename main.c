#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char* chaine = "qsd";
  char* resultat = repeatString(chaine, strlen(chaine));
  printf("%s\n", resultat);
  return 0;
}

char* repeatString(char* str, int count) {
  int nb_caracteres = (int) strlen(str);
  int i = 0, j = 0, k = 0;

  char* chaine = (char*) malloc(sizeof(char) * ((nb_caracteres * count) + 1));
  for (i = 0; i < count; i++) {
    j = 0;
    while (*(str + j)) {
      *(chaine + k) = *(str + j);
      j++;
      k++;
    }
  }
  *(chaine + ((nb_caracteres * count) + 1)) = '\0';
  return chaine;
}
