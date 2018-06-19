#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  int k_pid = lecture();
  kill(k_pid, SIGUSR1);
  return 0;
}

int lecture(void) {
  printf("PID ?\n");
  int nombre_caracteres = 10;
  char* chaine_saisie = (char*) malloc(sizeof(char) * nombre_caracteres);
  if (fgets(chaine_saisie, nombre_caracteres, stdin) != NULL) {
    chaine_saisie[nombre_caracteres - 1] = '\0';
  }
  int chaine_convertie = atoi(chaine_saisie);
  free(chaine_saisie);
  chaine_saisie = NULL;
  if (chaine_convertie > 0) {
    return chaine_convertie;
  }
  return -1;
}
