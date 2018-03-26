#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  short index = 0;
  char texte[] = "Programmation\nC\n";
  char* ptr = (char*) malloc(sizeof(char) * strlen(texte));
  if (ptr == NULL)
    return 1;

  while (texte[index]) {
    *(ptr + index) = texte[index];
    index++;
  }

  printf("%s", ptr);

  return 0;
}
