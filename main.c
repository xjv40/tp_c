#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  pid_t pidfils;
  int my_pipe[2];

  char donnees[] = "data...\n";
  unsigned char messageLire[TAILLE_TAMPON], messageEcrire[TAILLE_TAMPON];

  if (pipe(my_pipe)) {
    perror("Erreur lors de la création du pipe\n");
    return -1;
  }

  pidfils = fork();
  if (pidfils) {
    perror("Création lors du fork.\n");
  }

  if (pidfils == 0) {
    printf("Fermeture de l'entrée du fils.\n");
    close(my_pipe[1]);

    read(my_pipe[0], messageLire, TAILLE_TAMPON);
    printf("Nous sommes dans le fils, et voici le message : %s\n", messageLire);
  }
  else {
    printf("Fermeture de la sortie du père.\n");
    close(my_pipe[0]);

    sprintf(messageEcrire, donnees, strlen(donnees));
    printf("Nous sommes dans le père, et voici le message : %s\n", messageEcrire);
    write(my_pipe[1], messageEcrire, TAILLE_TAMPON);
    wait(NULL);
  }

  return 0;
}
