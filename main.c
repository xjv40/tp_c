#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int nb_valeurs = 0;
  int i = 0;
  int nb_positifs = 0;
  int nb_negatifs = 0;
  int nb_nulles = 0;
  int val_saisie = 0;

  printf("Nombre de valeurs : ");
  scanf("%d", &nb_valeurs);

  for (i = 0; i < nb_valeurs; i++) {
    val_saisie = 0;
    printf("Valeur saisie : ");
    scanf("%d", &val_saisie);
    if (val_saisie < 0) {
      nb_negatifs++;
    } else if (val_saisie > 0){
      nb_positifs++;
    } else {
      nb_nulles++;
    }
  }

  printf("\n\n\n");
  printf("valeurs nulles : %d\nvaleurs négatives : %d\nvaleurs positives : %d\n",
          nb_nulles,
          nb_negatifs,
          nb_positifs);

  return 0;
}
