#include <stdio.h>
#include <stdlib.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int nombre_entiers, i;

  printf("Veuillez rentrer le nombre d'entiers :\n");
  scanf("%d", &nombre_entiers);
  int* ptableau_entiers = (int*) malloc(nombre_entiers*sizeof(int));

  if (ptableau_entiers == NULL) {
    printf("Pas de mémoire disponible.\n");
    return EXIT_FAILURE;
  }

  for (i = 0; i < nombre_entiers; i++) {
    printf("Valeur saisie :\n");
    scanf("%d", (ptableau_entiers+i));
  }

  afficheTableau(ptableau_entiers, nombre_entiers);
  return 0;
}

void afficheTableau(int* ptableau, int nombre_entiers) {
  int i, compteur = 0;

  for (i = 0; i < nombre_entiers; i++) {
    printf("Valeur :\n");
    printf("%d\n", ptableau[i]);
    compteur += ptableau[i];
  }

  printf("Somme :\n");
  printf("%d\n", compteur);
}
