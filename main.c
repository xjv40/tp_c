#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  FILE* fichier = fopen("donnees/data.bak", "r");

  if (fichier == NULL) {
    perror("Impossible d'ouvrir le fichier.");
    return 1;
  }

  char* ligne = malloc(TAILLE);
  printf("Debut du fichier :\n");
  while (fgets(ligne, TAILLE, fichier) != NULL) {
    printf("%s", ligne);
  }
  printf("Fin de fichier.\n");

  if (fclose(fichier) != 0) {
    perror("Impossible de fermer le fichier.");
    return 1;
  }

  printf("Bien ferme !\n");

  return 0;
}
