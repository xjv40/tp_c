#ifndef __MAIN_H
#define __MAIN_H

struct eleve {
  char* nom;
  char* reponses;
};
typedef struct eleve Eleve;

void afficherEleve(struct eleve);
int lecture(void);
void afficherTous(void);
int nbr_rep(int question);
#endif  // __MAIN_H
