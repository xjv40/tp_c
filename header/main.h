#ifndef __MAIN_H
#define __MAIN_H

struct cellule {
  char* nom;
  int bureau;
  struct cellule* next;
};
typedef struct cellule Cellule;

Cellule* nouveau();
Cellule* ajoutTete(Cellule* nouvelleCellule, Cellule* tete);
void affiche(Cellule* pointeurBase);
Cellule* recherche(Cellule* pbase, char* chaine);
#endif  // __MAIN_H
