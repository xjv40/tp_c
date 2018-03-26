#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char chaine[] = "azer";
  return 0;
}

char* reverseStr(char* str) {
  int taille_chaine = strlen(str);
  char* nouv_chaine = (char*) malloc(sizeof(char) * (taille_chaine + 1));
  if (nouv_chaine == NULL)
    return 1;

  int i = 0, j = 0;

  for (i = taille_chaine - 1; i >= 0; i--) {
    *(nouv_chaine + j) = *(str + i);
    j++;
  }

  *(nouv_chaine + j) = '\0';

  return nouv_chaine;
}
