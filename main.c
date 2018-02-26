#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "header/main.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int nb_hasard = rand()%1000;
  int saisie;
  int nb_coups = 0;

  printf("Veuillez saisir votre nombre :\n");
  scanf("%d", &saisie);

  while(saisie != nb_hasard) {
    if (saisie > nb_hasard) {
      printf("Trop grand\n");
    }
    else {
      printf("Trop petit\n");
    }
    nb_coups++;
    printf("Veuillez saisir votre nouvelle valeur :\n");
    scanf("%d", &saisie);
  }

  printf("Vous avez trouve !\n");
  printf("C'etait : %d\n", nb_hasard);
  printf("Votre nombre de coups : %d\n", nb_coups);
  return 0;
}
