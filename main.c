#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned int valeur = 2867;
  int milliers = (valeur - valeur % 1000) / 1000;
  int centaines = (valeur % 1000 - valeur % 100) / 100;
  int dizaines = (valeur % 100 - valeur % 10) / 10;
  int unites = valeur % 10;
  printf("%d\n%d\n%d\n%d\n",
         milliers,
         centaines,
         dizaines,
         unites);
  return 0;
}
