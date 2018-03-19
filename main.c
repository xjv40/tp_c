#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char* chaine = "L'Omnimessie vaincra !";

  printf("%s\n", chaine);
  printf("%s\n", duplique_chaine(chaine));

  return 0;
}

int taille_chaine(char* chaine) {
  int compteur = 0;
  while (*(chaine + compteur) != '\0') {
    compteur += 1;
  }
  return compteur;
}

char* duplique_chaine(char* chaine_a_copier) {
  char* chaine_initiale = chaine_a_copier;
  int taille = taille_chaine(chaine_a_copier);
  char* chaine_receptacle = (char*) malloc(taille * sizeof(char));
  int i = 0;

  if (chaine_receptacle == NULL) {
    exit(1);
  }

  do {   
    *(chaine_receptacle + i) = *(chaine_initiale + i);
    i++;
  } while (*(chaine_initiale + (i-1)) != '\0');

  return chaine_receptacle;
}
