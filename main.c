#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

Eleve tab[7] = {
  {"Alain", "0011100110"},
  {"Beatrice", "1001101100"},
  {"Claude", "1010010100"},
  {"Daniel", "0100011101"},
  {"Emma", "0111101001"},
  {"Fanny", "1011101100"},
  {"Gregoire", "1101101101"}
};

int main(int argc, char* argv[]) {
  int num_question;
  afficherTous();
  while ((num_question = lecture()))
    printf("Reponses correcte s = %d\n",
           nbr_rep(num_question));
  return 0;
}

void afficherEleve(Eleve eleve) {
  int compte_bonne_reponse = 0, i = 0;

  for (i = 0; i < 10; i++) {
    compte_bonne_reponse += eleve.reponses[i] - '0';
  }
  printf("Nom de l'élève : %s, total : %d\n", eleve.nom, compte_bonne_reponse);
}

void afficherTous(void) {
  int i;
  for (i = 0; i < 7; i++) {
    afficherEleve(tab[i]);
  }
}

int lecture(void) {
  while(1) {
    int nombre_caracteres = 3;
    char* chaine_saisie = (char*) malloc(sizeof(char) * nombre_caracteres);
    chaine_saisie[nombre_caracteres - 1] = '\0';
    printf("Numéro de la réponse : ");
    scanf("%s", chaine_saisie);
    int chaine_convertie = atoi(chaine_saisie);
    if (chaine_convertie >= 0 && chaine_convertie <= 10)
      return chaine_convertie;
  }
}

int nbr_rep(int num_question) {
  int compte_bonne_reponse = 0;
  int i;

  for (i = 0; i < 7; i++) {
    compte_bonne_reponse += tab[i].reponses[num_question-1] - '0';
  }

  return compte_bonne_reponse;
}
