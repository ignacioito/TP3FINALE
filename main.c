//*****************************************
// Montréal QC 23 octobre de 2018
// Auteurs
// Ignacio Ito
// João Gustavo
// Luis Gustavomain
// Travail Pratique 03 Introduction À La Programmation
//*****************************************
//
// Le but de ce projet est de développer une solution programmatique 
// for the problem of complexly (le jeu Yahtzee). Il couvre les tableaux,
// les structures, les pointeurs et les arguments d'exécution. 
// Il a également été développé pour développer ses aptitudes de testeur 
// afin de valider sa stratégie. 
// 
// Professeure Rébecca Lapointe
//*****************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "yahtzee.h"
#define TAILLE_JET 5


int main()
{
  Jet jet;
  char test;

  printf ("\n\n Voulez-vous exécuter des tests?");
  printf ("\n\n Entrez 'S' pour OUI ou n/importe quelle touche pour continuer le jeu: ");
  scanf (" %c", &test);
  if (test == 's'|| test =='S') testJour (jet);
    else
    {
      match (jet);
    }

}
