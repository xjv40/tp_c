#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char* chaine = "   test   ";

  char* resultat = trim(chaine);

  return 0;
}

char* trim(char* str) {
  char* p = str;
  int i = 0;

  int resultat = compte_chaine(p);

  while ((*p == ' ') || (*p == '\t') || (*p == '\n')) {
    i++;
    p++;
  }

  printf("Nombre de caracteres en debut de chaine trouves : %d.\n", i);
  return str;
}

int compte_chaine(char* str) {
  int i = 0;
  char* p = str;

  while (*p != '\0') {
    i++;
  }

  return i;
}

