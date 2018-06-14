#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  char* chemin = "donnees/1b.dat";

  switch (creation_fichierb(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de la création du fichier binaire.\n");
      perror(chemin);
      break;
    default:
      printf("L'opération de création du fichier binaire "
             "s'est déroulée sans problème.\n");
      break;
  }

  switch(ecriture_fichierb(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de l'écriture du fichier binaire.'\n");
      perror(chemin);
      break;
    default:
      printf("L'opération d'écriture du fichier binaire "
             "s'est déroulée sans problème.\n");
      break;
  }

  switch(lecture_fichierb(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de la lecture du fichier binaire.'\n");
      perror(chemin);
      break;
    default:
      printf("L'opération de lecture du fichier binaire "
             "s'est déroulée sans problème.\n");
      break;
  }

  printf("\n\n\n");

  chemin = "donnees/1.dat";

  switch (creation_fichier(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de la création du fichier.\n");
      perror(chemin);
      break;
    default:
      printf("L'opération de création du fichier "
             "s'est déroulée sans problème.\n");
      break;
  }

  switch(ecriture_fichier(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de l'écriture du fichier.'\n");
      perror(chemin);
      break;
    default:
      printf("L'opération d'écriture du fichier "
             "s'est déroulée sans problème.\n");
      break;
  }

  switch(lecture_fichier(chemin)) {
    case 1:
    case 2:
      printf("Erreur lors de la lecture du fichier.'\n");
      perror(chemin);
      break;
    default:
      printf("L'opération de lecture du fichier "
             "s'est déroulée sans problème.\n");
      break;
  }

  printf("\n");

  return 0;
}

// Fonction de gestion des fichiers textes.

int creation_fichier(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "w");
  if (fichier != NULL) {
    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}


int ecriture_fichier(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "r+");
  if (fichier != NULL) {
    char msg[TAILLE] = "Rapport de fonctionnement :";
    fprintf(fichier, "%s\n", msg);

    int i;
    for (i = 0; i < 10; i++) {
      sprintf(msg, "Données %d : %d", i, i);
      fprintf(fichier, "%s\n", msg);
    }
    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}

int lecture_fichier(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "r");
  if (fichier != NULL) {
    char chaine[TAILLE];
    while (fgets(chaine, TAILLE, fichier) != NULL) {
      printf("%s", chaine);
    }
    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}


// Fonctions de gestions des fichiers binaires.
int creation_fichierb(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "wb");
  if (fichier != NULL) {
    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}

int ecriture_fichierb(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "rb+");
  if (fichier != NULL) {
    char msg[TAILLE] = "Rapport de fonctionnement :";
    fwrite(msg, sizeof(char), strlen(msg) + 1, fichier);


    int i;
    for (i = 0; i < 10; i++) {
      memset(msg, 0, TAILLE);
      sprintf(msg, "Donnees %d : %d", i, i);
      fwrite(msg, sizeof(char), strlen(msg) + 1, fichier);
    }

    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}

int lecture_fichierb(const char* nom_fichier) {
  FILE* fichier = fopen(nom_fichier, "rb");
  if (fichier != NULL) {
    char ligne[TAILLE];

    fread(ligne, sizeof(char), longueur_titre, fichier);
    printf("%s\n", ligne);

    // Attention, les caractères accentués prennent plus de place
    // que les caractères ASCII, il faut le prendre en compte
    // lorsque l'on définit les dimensions des données binaires
    // à lire.
    while(fread(ligne, sizeof(char), longueur_ligne, fichier) == longueur_ligne) {
      printf("%s\n", ligne);
      // Vidage du tampon ligne
      memset(ligne, 0, TAILLE);
    }

    if (fclose(fichier) != 0) {
      return 2;
    }
  }
  else {
    return 1;
  }
  return 0;
}
