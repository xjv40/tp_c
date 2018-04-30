#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/main.h"

int main(int argc, char* argv[]) {
  Cellule* pcellule = nouveau();
  if (pcellule == NULL) {
    printf("BUG !!\n");
    return 1;
  }

  Cellule* pbase = pcellule;
  Cellule* ptete = pcellule;

  Cellule* pNouvCellule = nouveau();
  ptete = ajoutTete(pNouvCellule, ptete);
  pNouvCellule = nouveau();
  ptete = ajoutTete(pNouvCellule, ptete);

  affiche(pbase);
  printf("%p\n", recherche(pbase, "russe"));
  return 0;
}

Cellule* nouveau() {
  char tempon[10];
  printf("Nom de la personne :\n");
  scanf("%s", tempon);

  char* chaine_nom = (char*) malloc(sizeof(strlen(tempon))+1);
  if (chaine_nom == NULL)
    return NULL;

  strncpy(chaine_nom, tempon, 9);
  chaine_nom[strlen(chaine_nom)+1] = '\0';

  printf("Numero du bureau :\n");
  scanf("%s", tempon);
  int bureau = atoi(tempon);

  Cellule* pcellule = (Cellule*) malloc(sizeof(Cellule));
  if (pcellule == NULL)
    return NULL;

  pcellule->nom = chaine_nom;
  pcellule->bureau = bureau;
  pcellule->next = NULL;
  return pcellule;
}

Cellule* ajoutTete(Cellule* nouvelleCellule, Cellule* tete) {
  tete->next = nouvelleCellule;
  return nouvelleCellule;
}

void affiche(Cellule* pbase) {
  Cellule* ptemp = pbase;
  while (ptemp != NULL) {
    printf("Nom : %s, bureau : %d\n", ptemp->nom, ptemp->bureau);
    ptemp = ptemp->next;
  }
  return;
}

Cellule* recherche(Cellule* pbase, char* chaine) {
  Cellule* ptemp = pbase;
  while (ptemp != NULL) {
    if (strcmp(ptemp->nom, chaine) == 0) {
      return ptemp;
    }
    ptemp = ptemp->next;
  }
  return NULL;
}
