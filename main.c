#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int nombre_chaine = 3;
  char* tableau_pointeurs[nombre_chaine];
  int nb_caracteres = 80;
  int i = 0;

  for (i = 0; i < nombre_chaine; i++) {
    char* pchaine = (char*) malloc(sizeof(char)*nb_caracteres);
    if (pchaine == NULL) {
      printf("Bug !\n");
      return 1;
    }
    scanf("%s", pchaine);
    tableau_pointeurs[i] = pchaine;
  }

  for (i = 0; i < nombre_chaine; i++) {
    printf("%s\n", tableau_pointeurs[i]);
    free(tableau_pointeurs[i]);
  }

  return 0;
}
