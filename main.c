#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char* chaine = "L'Omnimessie vaincra !";
  printf("%s\n", myExtractSubstring(chaine, 2, 8));
  return 0;
}

char* myExtractSubstring(char* str, int debut, int fin) {
  if (fin <= debut)
    return 1;

  char* chaine = (char*) malloc(sizeof(char) * (fin - debut));
  int i = 0;
  int j = 0;

  for (i = debut; i < fin; i++) {
    *(chaine + j) = *(str + i);
    j++;
  }

  return chaine;
}
