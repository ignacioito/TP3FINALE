#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "yahtzee.h"
#define TAILLE_JET 5


void match (Jet jet)
{
     Score score = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     
     int scoreFinale = 0;
     int sorti = 0;
     printf ("******************************************************************\n");
     printf ("*                      BIENVENU AU YAHTZEE!!!                    *\n");
     printf ("******************************************************************\n");
  
  for (int i = 0; i < 13; ++i)
  {
    Jet joueFait = joue (jet);
    char option;

  
    printf ("\n\n\n");
    printf ("******************************************************************\n");
    printf ("*                QUEL POINTAGE VOULEZ-VOUS GARDER?               *\n");
    printf ("******************************************************************\n");
    printf ("*  (A) - Les valeurs avec le visage 1 ajouté: %d\n", nbDeFace(joueFait,1));
    printf ("*  (B) - Les valeurs avec le visage 2 ajouté: %d\n", nbDeFace(joueFait,2));
    printf ("*  (C) - Les valeurs avec le visage 3 ajouté: %d\n", nbDeFace(joueFait,3));
    printf ("*  (D) - Les valeurs avec le visage 4 ajouté: %d\n", nbDeFace(joueFait,4));
    printf ("*  (E) - Les valeurs avec le visage 5 ajouté: %d\n", nbDeFace(joueFait,5));
    printf ("*  (F) - Les valeurs avec le visage 6 ajouté: %d\n", nbDeFace(joueFait,6));
    printf ("*  (G) - Pour le main plaine on a la valeur: %d\n", mainPleine (joueFait));
    printf ("*  (H) - Pour le brelan on a la valeur: %d\n", brelan (joueFait));
    printf ("*  (I) - Pour le carre on a la valeur: %d\n", carre (joueFait));
    printf ("*  (J) - Pour le petite suite on a la valeur: %d\n", petiteSuite (joueFait));
    printf ("*  (K) - Pour le grande suite on a la valeur: %d\n", grandeSuite (joueFait)); 
    printf ("*  (L) - Pour le chance on a la valeur: %d\n", chance (joueFait));
    printf ("*  (M) - Pour le yahtzee on a la valeur: %d\n", yahtzee (joueFait));
    printf ("\n");
    printf ("******************************************************************\n\n\n\n");
 
    do 
    {
     printf ("ATTENTION!!! CHOISISSEZ EN MAJUSCULE VOTRE JEU: ");
     scanf (" %c", &option);
     // Ici, l'utilisateur est invité à choisir le jeu qu'il souhaite marquer. 
     printf ("\n");

       switch(option)
       {
          case ('A'): 
               score.un = nbDeFace(joueFait,1);
               sorti = 0;
               break;
            
               case ('B'): 
               score.deux = nbDeFace(joueFait,2);
               sorti = 0;
               break;

               case ('C'):
               score.trois = nbDeFace(joueFait,3);
               sorti = 0;
               break;

               case ('D'): 
               score.quatre = nbDeFace(joueFait,4);
               sorti = 0;
               break;

               case ('E'): 
               score.cinq = nbDeFace(joueFait,5);
               sorti = 0;
               break;

               case ('F'): 
               score.six = nbDeFace(joueFait,6);
               sorti = 0;
               break;

               case ('G'): 
               score.mainPleine = mainPleine(joueFait);
               sorti = 0;
               break;
            
               case ('H'): 
               score.brelan = brelan(joueFait);
               sorti = 0;
               break;

               case ('I'): 
               score.carre = carre(joueFait);
               sorti = 0;
               break;

               case ('J'): 
               score.petiteSuite = petiteSuite(joueFait);
               sorti = 0;
               break;

               case ('K'): 
               score.grandeSuite = grandeSuite(joueFait);
               sorti = 0;
               break;

               case ('L'): 
               score.chance = chance(joueFait);
               sorti = 0;
               break;

               case ('M'): 
               score.yahtzee = yahtzee(joueFait);
               sorti = 0;
               break;

               default: printf ("\nATTENTION! OPTION INVALIDE!!!\n");
               sorti = 1;


          }
        } 
        while (sorti);

  
        scoreFinale = (score.un + score.deux + score.trois + score.quatre + score.cinq + score.six + score.mainPleine + score.brelan + score.carre + score.petiteSuite + score.grandeSuite + score.chance + score.yahtzee);

        printf ("******************************************************************\n");
        printf ("*                            SCORE                               *\n");
        printf ("******************************************************************\n");
        printf("* (A) - Vous avez %d points dans la somme des données de valeur 1   \n", score.un);
        printf("* (B) - Vous avez %d points dans la somme des données de valeur 2 \n", score.deux);
        printf("* (C) - Vous avez %d points dans la somme des données de valeur 3   \n", score.trois);
        printf("* (D) - Vous avez %d points dans la somme des données de valeur 4   \n", score.quatre);
        printf("* (E) - Vous avez %d points dans la somme des données de valeur 5   \n", score.cinq);
        printf("* (F) - Vous avez %d points dans la somme des données de valeur 6   \n", score.six);
        printf("* (G) - Vous avez %d points dans en main plaine   \n", score.mainPleine);
        printf("* (H) - Vous avez %d points dans en brelan   \n", score.brelan);
        printf("* (I) - Vous avez %d points dans en carre   \n", score.carre);
        printf("* (J) - Vous avez %d points dans en petite suite   \n", score.petiteSuite);
        printf("* (K) - Vous avez %d points dans en grande suite   \n", score.grandeSuite);
        printf("* (L) - Vous avez %d points dans en chance   \n", score.chance);
        printf("* (M) - Vous avez %d points dans en yahtzee   \n\n", score.yahtzee);
        printf ("******************************************************************\n");
        printf ("\n*                      VOTRE SCORE:  %d                          *\n\n", scoreFinale);
        printf ("******************************************************************\n\n\n");
     }
}
//****
//
//****
 void testJour (Jet jet)
{
     printf ("******************************************************************\n");
     printf ("*                                  MODE TEST                                            *\n");
     printf ("******************************************************************\n");

     printf ("\n");
     printf (" TEST nbDeFace\n");
     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 1;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,1) == 3) printf("Si la somme des dés avec face 1 est 3, la fonction marche\n ");
     else printf("Si la somme des dés avec face 1 est different de 3, la fonction ne marche pas\n ");

     jet.des[0] = 2;
     jet.des[1] = 1;
     jet.des[2] = 2;
     jet.des[3] = 2;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,2) == 6) printf("Si la somme des dés avec face 2 est 6, la fonction marche\n ");
     else printf("Si la somme des dés avec face 2 est different de 6, la fonction ne marche pas\n ");

     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 3;
     jet.des[3] = 4;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,3) == 6) printf("Si la somme des dés avec face 3 est 6, la fonction marche\n ");
     else printf("Si la somme des dés avec face 3 est different de 6, la fonction ne marche pas\n ");

     jet.des[0] = 2;
     jet.des[1] = 1;
     jet.des[2] = 4;
     jet.des[3] = 2;
     jet.des[4] = 4;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,4) == 8) printf("Si la somme des dés avec face 4 est 8, la fonction marche\n ");
     else printf("Si la somme des dés avec face 4 est different de 8, la fonction ne marche pas\n ");

     jet.des[0] = 1;
     jet.des[1] = 5;
     jet.des[2] = 3;
     jet.des[3] = 5;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,5) == 10) printf("Si la somme des dés avec face 5 est 10, la fonction marche\n ");
     else printf("Si la somme des dés avec face 5 est different de 10, la fonction ne marche pas\n ");

     jet.des[0] = 6;
     jet.des[1] = 1;
     jet.des[2] = 6;
     jet.des[3] = 6;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(nbDeFace (jet,6) == 18) printf("Si la somme des dés avec face 6 est 18, la fonction marche\n\n ");
     else printf("Si la somme des dés avec face 6 est different de 18, la fonction ne marche pas\n\n ");

     printf ("TEST mainPleine\n");
     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(mainPleine (jet) == 25) printf("S'il y a deux dés avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction marche \n ");
     else printf("s'il n'y a pas deux données avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction ne marche pas\n ");

     jet.des[0] = 2;
     jet.des[1] = 1;
     jet.des[2] = 2;
     jet.des[3] = 2;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(mainPleine (jet) == 0) printf("S'il y a deux dés avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction marche \n ");
     else printf("s'il n'y a pas deux données avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction ne marche pas\n ");


     jet.des[0] = 2;
     jet.des[1] = 2;
     jet.des[2] = 4;
     jet.des[3] = 4;
     jet.des[4] = 4;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(mainPleine (jet) == 25) printf("S'il y a deux dés avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction marche \n ");
     else printf("s'il n'y a pas deux données avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction ne marche pas\n ");


     jet.des[0] = 6;
     jet.des[1] = 1;
     jet.des[2] = 2;
     jet.des[3] = 4;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(mainPleine (jet) == 0) printf("S'il y a deux dés avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction marche \n ");
     else printf("s'il n'y a pas deux données avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction ne marche pas\n ");


     jet.des[0] = 5;
     jet.des[1] = 1;
     jet.des[2] = 5;
     jet.des[3] = 1;
     jet.des[4] = 5;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(mainPleine (jet) == 25) printf("S'il y a deux dés avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction marche \n\n ");
     else printf("s'il n'y a pas deux données avec des faces égales entre elles et trois autres données avec des faces égales entre elles, la fonction ne marche pas\n\n ");

     printf ("TEST brelan\n");
     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 1;
     jet.des[3] = 1;
     jet.des[4] = 3;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(brelan (jet) == 7) printf("Si le retour vault 7, la fonction marche parce que il y a trois dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 7, la fonction ne marche pas \n ");


     jet.des[0] = 1;
     jet.des[1] = 3;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(brelan (jet) == 13) printf("Si le retour vault 13, la fonction marche parce que il y a trois dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 13, la fonction ne marche pas \n ");

     jet.des[0] = 3;
     jet.des[1] = 3;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(brelan (jet) == 15) printf("Si le retour vault 15, la fonction marche parce que il y a trois dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 15, la fonction ne marche pas \n ");
 
     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 2;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(brelan (jet) == 0) printf("Si le retour vault 0, la fonction marche parce que il n'y a pas trois dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 3;
     jet.des[3] = 4;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(brelan (jet) == 0) printf("Si le retour vault 0, la fonction marche parce que il n'y a pas trois dés avec des faces égales\n\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n\n ");

     printf ("TEST carre\n");
     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 1;
     jet.des[3] = 2;
     jet.des[4] = 3;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(carre (jet) == 0) printf("Si le retour vault 0, la fonction marche parce que il n'y a pas quattre dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 3;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(carre (jet) == 13) printf("Si le retour vault 13, la fonction marche parce que il y a quattre dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 13, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 1;
     jet.des[2] = 2;
     jet.des[3] = 3;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(carre (jet) == 0) printf("Si le retour vault 0, la fonction marche parce que il n'y a pas quattre dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 5;
     jet.des[2] = 5;
     jet.des[3] = 5;
     jet.des[4] = 5;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(carre (jet) == 21) printf("Si le retour vault 21, la fonction marche parce que il y a quattre dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 21, la fonction ne marche pas \n ");

     jet.des[0] = 6;
     jet.des[1] = 6;
     jet.des[2] = 6;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(carre (jet) == 27) printf("Si le retour vault 27, la fonction marche parce que il y a quattre dés avec des faces égales\n\n ");
     else printf("S'il ne retourne pas le valeur 27, la fonction ne marche pas \n\n ");

     printf ("TEST petiteSuite\n");
     jet.des[0] = 6;
     jet.des[1] = 5;
     jet.des[2] = 4;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(petiteSuite (jet) == 30) printf("Si le retour vault 30, la fonction marche parce que il y a une sequence de quattre chiffres\n ");
     else printf("S'il ne retourne pas le valeur 30, la fonction ne marche pas \n ");

     jet.des[0] = 5;
     jet.des[1] = 6;
     jet.des[2] = 6;
     jet.des[3] = 4;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(petiteSuite (jet) == 30) printf("Si le retour vault 30, la fonction marche parce que il y a une sequence de quattre chiffres\n ");
     else printf("S'il ne retourne pas le valeur 30, la fonction ne marche pas \n ");

     jet.des[0] = 4;
     jet.des[1] = 6;
     jet.des[2] = 4;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(petiteSuite (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas une sequence de quattre chiffres\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 6;
     jet.des[2] = 2;
     jet.des[3] = 3;
     jet.des[4] = 4;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(petiteSuite (jet) == 30) printf("Si le retour vault 30, la fonction marche parce que il y a une sequence de quattre chiffres\n ");
     else printf("S'il ne retourne pas le valeur 30, la fonction ne marche pas \n ");


     jet.des[0] = 5;
     jet.des[1] = 6;
     jet.des[2] = 5;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(petiteSuite (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas une sequence de quattre chiffres\n\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n\n ");

     printf ("TEST grandeSuite\n");
     jet.des[0] = 1;
     jet.des[1] = 3;
     jet.des[2] = 2;
     jet.des[3] = 5;
     jet.des[4] = 4;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(grandeSuite (jet) == 40) printf("Si le retour vault 40, la fonction marche, parce que il y a une sequence de cinq chiffres\n ");
     else printf("S'il ne retourne pas le valeur 40, la fonction ne marche pas \n ");

     jet.des[0] = 2;
     jet.des[1] = 6;
     jet.des[2] = 3;
     jet.des[3] = 5;
     jet.des[4] = 4;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(grandeSuite (jet) == 40) printf("Si le retour vault 40, la fonction marche, parce que il y a une sequence de cinq chiffres\n ");
     else printf("S'il ne retourne pas le valeur 40, la fonction ne marche pas \n ");;

     jet.des[0] = 5;
     jet.des[1] = 6;
     jet.des[2] = 5;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(grandeSuite (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas une sequence de cinq chiffres\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 5;
     jet.des[1] = 4;
     jet.des[2] = 5;
     jet.des[3] = 1;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(grandeSuite (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas une sequence de cinq chiffres\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 6;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(grandeSuite (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas une sequence de cinq chiffres\n\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n\n ");

     printf ("TEST chance\n");
     jet.des[0] = 1;
     jet.des[1] = 4;
     jet.des[2] = 3;
     jet.des[3] = 3;
     jet.des[4] = 5;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(chance (jet) == 16) printf("Si le retour vault 16, la fonction marche parce que la somme des dés est %d\n ", chance (jet));
     else printf("S'il ne retourne pas le valeur 16, la fonction ne marche pas \n ");

     jet.des[0] = 2;
     jet.des[1] = 6;
     jet.des[2] = 4;
     jet.des[3] = 3;
     jet.des[4] = 1;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(chance (jet) == 16) printf("Si le retour vault 16, la fonction marche parce que la somme des dés est %d\n ", chance (jet));
     else printf("S'il ne retourne pas le valeur 16, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 3;
     jet.des[2] = 3;
     jet.des[3] = 5;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(chance (jet) == 18) printf("Si le retour vault 18, la fonction marche parce que la somme des dés est %d\n ", chance (jet));
     else printf("S'il ne retourne pas le valeur 18, la fonction ne marche pas \n ");

     jet.des[0] = 1;
     jet.des[1] = 6;
     jet.des[2] = 2;
     jet.des[3] = 2;
     jet.des[4] = 2;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(chance (jet) == 13) printf("Si le retour vault 13, la fonction marche parce que la somme des dés est %d\n ", chance (jet));
     else printf("S'il ne retourne pas le valeur 13, la fonction ne marche pas \n ");

     jet.des[0] = 4;
     jet.des[1] = 5;
     jet.des[2] = 3;
     jet.des[3] = 6;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(chance (jet) == 24) printf("Si le retour vault 24, la fonction marche parce que la somme des dés est %d\n\n ", chance (jet));
     else printf("S'il ne retourne pas le valeur 24, la fonction ne marche pas \n\n ");

     printf ("TEST yahtzee\n");
     jet.des[0] = 6;
     jet.des[1] = 6;
     jet.des[2] = 6;
     jet.des[3] = 6;
     jet.des[4] = 6;
     printf (" %d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(yahtzee (jet) == 50) printf("Si le retour vault 50, la fonction marche parce que il y a cinq dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 50, la fonction ne marche pas \n ");

     jet.des[0] = 3;
     jet.des[1] = 5;
     jet.des[2] = 3;
     jet.des[3] = 6;
     jet.des[4] = 2;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(yahtzee (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas cinq dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 4;
     jet.des[1] = 4;
     jet.des[2] = 4;
     jet.des[3] = 4;
     jet.des[4] = 4;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(yahtzee (jet) == 50) printf("Si le retour vault 50, la fonction marche parce que il y a cinq dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 50, la fonction ne marche pas \n ");


     jet.des[0] = 1;
     jet.des[1] = 5;
     jet.des[2] = 2;
     jet.des[3] = 6;
     jet.des[4] = 3;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(yahtzee (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas cinq dés avec des faces égales\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n ");

     jet.des[0] = 4;
     jet.des[1] = 5;
     jet.des[2] = 3;
     jet.des[3] = 6;
     jet.des[4] = 6;
     printf ("%d, %d, %d, %d, %d  ", jet.des[0],jet.des[1],jet.des[2],jet.des[3],jet.des[4]);  
     if(yahtzee (jet) == 0) printf("Si le retour vault 0, la fonction marche, parce que il n'y a pas cinq dés avec des faces égales\n\n ");
     else printf("S'il ne retourne pas le valeur 0, la fonction ne marche pas \n\n ");


}
//****
//
//****
Jet joue (Jet jet)
{
     const int MIN = 1;
     const int MAX = 6;
  
     srand(time(NULL));

     int des[5];
     char quant [5];
     int n = 0;
     // Nous déclarons ici les trois variables utilisées dans chacun des mouvements. 

     printf("Voici cinq nombres pigés au hasard entre %d et %d : \n\n", MIN, MAX);
     // Ici, nous informons l'utilisateur qu'il y a cinq nombres choisis au hasard

     for (int i = 0; i < 5; ++i)
     {
          n = rand() % MAX + MIN;
          jet.des[i] = n;
          // Ici nous avons couru un pour pour pour la première fois remplir le tableau contenant
          // les valeurs des données du premier coup.
     
}
  printf("\n");

  dessineDes(jet);
  // Nous appelons ici la fonction dessineDes pour que les valeurs obtenues dans le premier
  // les jeux sont représentés comme s'ils étaient des dés.

  for (int c = 0; c < 2; ++c)
  {
  // Ici, nous réglons ceci pour que nous puissions lancer les dés deux fois plus

     printf("\nEntrez 0 POUR CONSERVER la valeur des données ou entrez 1 POUR MODIFIER la valeur de chacune des cinq données.\n\n");
     // Nous demandons ici à l’utilisateur de choisir les valeurs des données qui seront conservées et les valeurs
     // des données qui seront modifiées, à la fois au deuxième et au troisième coup de chaque tour.

     for (int i = 0; i < 5; ++i)
     {
          scanf (" %c", &quant[i]);
     }
     // Ici, nous mettons un scanf pour que l’utilisateur puisse taper 0 ou 1 et conserver ou changer le
     // valeur des données des deux derniers tours. Les valeurs 0 ou 1 sont reçues dans tableau quant []
     printf("\n");

     for (int i = 0; i < 5; ++i)
     {
          if (quant[i] == '1')
          {
               n = rand() % MAX + MIN;
               jet.des[i] = n;
          }
          // Ici, nous avons fait cela pour déterminer quelles données devaient être conservées et quelles données devaient être conservées.
          // a joué à nouveau, dans les deux derniers jeux de chaque tour.
     }
     dessineDes(jet);
     // Ici, nous appelons la fonction dessineDes afin que les valeurs obtenues à la fois dans le deuxième et le troisième
     // dans le troisième coup sont représentés comme s'ils étaient des dés.
        
  }
     
     return jet;
     // La fonction renvoie les valeurs dans une structure de type jet
}

//****
//
//****

int nbDeFace (Jet jet, int face)
{
  int i;
  int valeur = 0;

  for (i = 0; i < TAILLE_JET; i++)
  {
    if (jet.des[i] == face)
    valeur ++;
  }
  return (valeur * face);

}
 //****
 //
 //****
int mainPleine(Jet jet)
{
  int somme1 = 0;
  int somme2 = 0;
  int somme3 = 0;
  int somme4 = 0;
  int somme5 = 0;
  int somme6 = 0;
  // Nous déclarons ici les six variables de paramètres locaux de type int que nous allons utiliser dans la fonction.
  
      for (int i = 0; i < 5; ++i)
      { 
              if (jet.des[i] == 1)
              {
                somme1 ++;
              }
              if (jet.des[i] == 2)
              {
                somme2 ++;
              }
              if (jet.des[i] == 3)
              {
                somme3 ++;
              }
              if (jet.des[i] == 4)
              {
                somme4 ++;
              }
              if (jet.des[i] == 5)
              {
                somme5 ++;
              }
              if (jet.des[i] == 6)
              {
                somme6 ++;
              }
        }
        // Ici, nous avons fait un for pour capturer en six variables (somme1, somme2, somme3, somme4, somme5 et somme6)
        // le nombre de fois que chacune des cinq données apparaît
            
            if (((somme1 == 3) && (somme2 == 2)) ||
                ((somme1 == 3) && (somme3 == 2)) ||
                ((somme1 == 3) && (somme4 == 2)) ||
                ((somme1 == 3) && (somme5 == 2)) ||
                ((somme1 == 3) && (somme6 == 2)) ||
                ((somme2 == 3) && (somme1 == 2)) ||
                ((somme2 == 3) && (somme3 == 2)) ||
                ((somme2 == 3) && (somme4 == 2)) ||
                ((somme2 == 3) && (somme5 == 2)) ||
                ((somme2 == 3) && (somme6 == 2)) ||
                ((somme3 == 3) && (somme1 == 2)) ||
                ((somme3 == 3) && (somme2 == 2)) ||
                ((somme3 == 3) && (somme4 == 2)) ||
                ((somme3 == 3) && (somme5 == 2)) ||
                ((somme3 == 3) && (somme6 == 2)) ||
                ((somme4 == 3) && (somme1 == 2)) ||
                ((somme4 == 3) && (somme2 == 2)) ||
                ((somme4 == 3) && (somme3 == 2)) ||
                ((somme4 == 3) && (somme5 == 2)) ||
                ((somme4 == 3) && (somme6 == 2)) ||
                ((somme5 == 3) && (somme1 == 2)) ||
                ((somme5 == 3) && (somme2 == 2)) ||
                ((somme5 == 3) && (somme3 == 2)) ||
                ((somme5 == 3) && (somme4 == 2)) ||
                ((somme5 == 3) && (somme6 == 2)) ||
                ((somme6 == 3) && (somme1 == 2)) ||
                ((somme6 == 3) && (somme2 == 2)) ||
                ((somme6 == 3) && (somme3 == 2)) ||
                ((somme6 == 3) && (somme4 == 2)) ||
                ((somme6 == 3) && (somme5 == 2)))
                // Nous écrivons ici les conditions dans lesquelles une main plaine peut se produire      
            {
              return 25; 
            }
      
  return 0 ;
// Si une condition du main pleine est satisfaite, la fonction renvoie 25, sinon elle renvoie 0.
}
//****
//
//****
int brelan(Jet jet)
{
  
  int total = 0;
  int somme1 = 0;
  int somme2 = 0;
  int somme3 = 0;
  int somme4 = 0;
  int somme5 = 0;
  int somme6 = 0;
  // Nous déclarons ici les sept variables de paramètres locaux de type int que nous allons utiliser dans la fonction.
  
  for (int i = 0; i < 5; ++i)
    {
      total = total + jet.des[i]; 
    }
  // Ici nous avons fait un for pour déterminer la somme de toutes les faces des données à la fin des trois tours de chaque tour.
      
      for (int i = 0; i < 5; ++i)
        { 
              if (jet.des[i] == 1)
              {
                somme1 ++;
              }
              if (jet.des[i] == 2)
              {
                somme2 ++;
              }
              if (jet.des[i] == 3)
              {
                somme3 ++;
              }
              if (jet.des[i] == 4)
              {
                somme4 ++;
              }
              if (jet.des[i] == 5)
              {
                somme5 ++;
              }
              if (jet.des[i] == 6)
              {
                somme6 ++;
              }
        }
// Ici, nous avons fait un for pour capturer en six variables (somme1, somme2, somme3, somme4, somme5 et somme6)
// le nombre de fois que chacune des cinq données apparaît.
            
            if ((somme1 >= 3) || (somme2 >= 3) || (somme3 >= 3) || (somme4 >= 3) || (somme5 >= 3) || (somme6 >= 3))
// Nous écrivons ici les conditions dans lesquelles une brelan peut se produire.
            {
              return total; 
            }
      
  return 0 ;
// Si l'une des conditions du brelan est remplie, la fonction renvoie la valeur de somme de toutes
// les données à la fin du troisième mouvement, sinon elle renvoie 0. 
}

 //****
 //
 //**** 
int carre(Jet jet)
{
  
  int total = 0;
  int somme1 = 0;
  int somme2 = 0;
  int somme3 = 0;
  int somme4 = 0;
  int somme5 = 0;
  int somme6 = 0;
// Nous déclarons ici les sept variables de paramètres locaux de type int que nous allons utiliser dans la fonction.
  

  for (int i = 0; i < 5; ++i)
    {
      total = total + jet.des[i]; 
    }
// Ici nous avons fait un for pour déterminer la somme de toutes les faces des données à la fin des trois tours de chaque tour.
      
      for (int i = 0; i < 5; ++i)
        { 
              if (jet.des[i] == 1)
              {
                somme1 ++;
              }
              if (jet.des[i] == 2)
              {
                somme2 ++;
              }
              if (jet.des[i] == 3)
              {
                somme3 ++;
              }
              if (jet.des[i] == 4)
              {
                somme4 ++;
              }
              if (jet.des[i] == 5)
              {
                somme5 ++;
              }
              if (jet.des[i] == 6)
              {
                somme6 ++;
              }
        }
// Ici, nous avons fait un for pour capturer en six variables (somme1, somme2, somme3, somme4, somme5 et somme6)
// le nombre de fois que chacune des cinq données apparaît.
            
            if ((somme1 >= 4) || (somme2 >= 4) || (somme3 >= 4) || (somme4 >= 4) || (somme5 >= 4) || (somme6 >= 4))
// Nous écrivons ici les conditions dans lesquelles une carre peut se produire.
            {
              return total; 
            }
      
  return 0 ;
// Si l'une des conditions du carre est remplie, la fonction renvoie la valeur de somme de toutes
// les données à la fin du troisième mouvement, sinon elle renvoie 0.  
} 
//****
//
//****

int petiteSuite(Jet jet)
{
  
  int somme1 = 0;
  int somme2 = 0;
  int somme3 = 0;
  int somme4 = 0;
  int somme5 = 0;
  int somme6 = 0;
  // Nous déclarons ici les six variables de paramètres locaux de type int que nous allons utiliser dans la fonction.
  
      
      for (int i = 0; i < 5; ++i)
        { 
              if (jet.des[i] == 1)
              {
                somme1 ++;
              }
              if (jet.des[i] == 2)
              {
                somme2 ++;
              }
              if (jet.des[i] == 3)
              {
                somme3 ++;
              }
              if (jet.des[i] == 4)
              {
                somme4 ++;
              }
              if (jet.des[i] == 5)
              {
                somme5 ++;
              }
              if (jet.des[i] == 6)
              {
                somme6 ++;
              }
        }
// Ici, nous avons fait un for pour capturer en six variables (somme1, somme2, somme3, somme4, somme5 et somme6)
// le nombre de fois que chacune des cinq données apparaît.
            
            if (((somme1 >= 1) && (somme2 >= 1) && (somme3 >= 1) && (somme4 >= 1)) ||
                ((somme2 >= 1) && (somme3 >= 1) && (somme4 >= 1) && (somme5 >= 1)) ||
                ((somme3 >= 1) && (somme4 >= 1) && (somme5 >= 1) && (somme6 >= 1)))
// Nous écrivons ici les conditions dans lesquelles une petite suite peut se produire.   
            {
              return 30; 
            }
      
  return 0 ;
// Si une condition du petite suite est satisfaite, la fonction renvoie 30, sinon elle renvoie 0.
}

//****
//
//****
 int grandeSuite(Jet jet)
{

  int somme1 = 0;
  int somme2 = 0;
  int somme3 = 0;
  int somme4 = 0;
  int somme5 = 0;
  int somme6 = 0;
// Nous déclarons ici les six variables de paramètres locaux de type int que nous allons utiliser dans la fonction.
  
      
      for (int i = 0; i < 5; ++i)
        { 
              if (jet.des[i] == 1)
              {
                somme1 ++;
              }
              if (jet.des[i] == 2)
              {
                somme2 ++;
              }
              if (jet.des[i] == 3)
              {
                somme3 ++;
              }
              if (jet.des[i] == 4)
              {
                somme4 ++;
              }
              if (jet.des[i] == 5)
              {
                somme5 ++;
              }
              if (jet.des[i] == 6)
              {
                somme6 ++;
              }
        }
// Ici, nous avons fait un for pour capturer en six variables (somme1, somme2, somme3, somme4, somme5 et somme6)
// le nombre de fois que chacune des cinq données apparaît.
            
            if (((somme1 == 1) && (somme2 == 1) && (somme3 == 1) && (somme4 == 1) && (somme5 == 1)) ||
                ((somme2 == 1) && (somme3 == 1) && (somme4 == 1) && (somme5 == 1) && (somme6 == 1)))
// Nous écrivons ici les conditions dans lesquelles une grande suite peut se produire.       
            {
              return 40; 
            }
      
  return 0 ;
// Si une condition du grande suite est satisfaite, la fonction renvoie 40, sinon elle renvoie 0. 
}
 
 //****
 //
 //****
int chance(Jet teste)
{
    int somme = 0;
// Ici, nous déclarons la variable de type int de paramètres locaux que nous allons utiliser dans la fonction.

    for (int i = 0; i < 5; ++i)
     
      somme = somme + teste.des[i]; 
      
      return somme;
// Ici nous avons fait un for pour déterminer la somme de toutes les faces des données à la fin du troisième tour de chaque tour.
// Nous demandons également que la valeur de la somme des données renvoie la fonction.

 }
//****
//
//****
int yahtzee(Jet jet)
{
     if((jet.des[0] == jet.des[1]) && (jet.des[1] == jet.des[2]) && (jet.des[2]== jet.des[3]) && (jet.des[3]== jet.des[4])) 
     // Ici nous avons fait la condition pour qu'un yahtzee soit fait.
     {
      return 50;
     }
  
     return 0;
// Si la condition du yahtzee est satisfaite, la fonction renvoie 50, sinon elle renvoie 0.
}
//****
//
//****
void dessineDes(Jet jet)
{  
  int rangee;
  int colonne;
  int JetGauche = 0;
  int JetDroite = 6;  
  char montrerDes[5][47];
  
  for(rangee = 0; rangee < 5; rangee++)
  {
    for(colonne = 0; colonne < 47; colonne++)
    {
      montrerDes[rangee][colonne] = ' ';      
      if(((rangee == 0) || (rangee == 4)) && (colonne != 7) && (colonne != 8)
      && (colonne != 9) && (colonne != 17) && (colonne != 18) && (colonne != 19) && (colonne != 27) && (colonne != 28)
      && (colonne != 29) && (colonne != 37) && (colonne != 38) && (colonne != 39))
      {
        montrerDes[rangee][colonne] = '-';        
      }                 
      if(colonne == JetGauche)
      {
        montrerDes[rangee][colonne] = '|';
        montrerDes[0][JetGauche] = '+'; 
        montrerDes[4][JetGauche] = '+';   
        JetGauche += 10;              
      }
      else if(colonne == JetDroite)
      {
        montrerDes[rangee][colonne] = '|';
        montrerDes[0][JetDroite] = '+';
        montrerDes[4][JetDroite] = '+';
        JetDroite += 10;        
      }             
    }
    JetGauche = 0;
    JetDroite = 6;  
  } 
  switch(jet.des[0])
  {
    case 1:     
      montrerDes[2][3] = 'o';       
    break;
    case 2:
      montrerDes[1][5] = 'o';
      montrerDes[3][1] = 'o';
    break;
    case 3:
      montrerDes[1][5] = 'o';
      montrerDes[2][3] = 'o';
      montrerDes[3][1] = 'o';       
    break;
    case 4:
      montrerDes[1][1] = 'o';
      montrerDes[1][5] = 'o';
      montrerDes[3][1] = 'o';
      montrerDes[3][5] = 'o';
    break;
    case 5:
      montrerDes[1][1] = 'o';
      montrerDes[1][5] = 'o';
      montrerDes[2][3] = 'o'; 
      montrerDes[3][1] = 'o';
      montrerDes[3][5] = 'o';
    break;
    case 6:
      montrerDes[1][1] = 'o';
      montrerDes[1][5] = 'o';
      montrerDes[1][3] = 'o';
      montrerDes[3][3] = 'o';
      montrerDes[3][1] = 'o';
      montrerDes[3][5] = 'o';
    break;
  }
  switch(jet.des[1])
  {
    case 1:     
      montrerDes[2][13] = 'o';        
    break;
    case 2:
      montrerDes[1][15] = 'o';
      montrerDes[3][11] = 'o';
    break;
    case 3:
      montrerDes[1][15] = 'o';
      montrerDes[2][13] = 'o';
      montrerDes[3][11] = 'o';        
    break;
    case 4:
      montrerDes[1][11] = 'o';
      montrerDes[1][15] = 'o';
      montrerDes[3][11] = 'o';
      montrerDes[3][15] = 'o';
    break;
    case 5:
      montrerDes[1][11] = 'o';
      montrerDes[1][15] = 'o';
      montrerDes[2][13] = 'o';  
      montrerDes[3][11] = 'o';
      montrerDes[3][15] = 'o';
    break;
    case 6:
      montrerDes[1][11] = 'o';
      montrerDes[1][15] = 'o';
      montrerDes[1][13] = 'o';
      montrerDes[3][13] = 'o';
      montrerDes[3][11] = 'o';
      montrerDes[3][15] = 'o';
    break;
  }
  switch(jet.des[2])
  {
    case 1:     
      montrerDes[2][23] = 'o';        
    break;
    case 2:
      montrerDes[1][25] = 'o';
      montrerDes[3][21] = 'o';
    break;
    case 3:
      montrerDes[1][25] = 'o';
      montrerDes[2][23] = 'o';
      montrerDes[3][21] = 'o';        
    break;
    case 4:
      montrerDes[1][21] = 'o';
      montrerDes[1][25] = 'o';
      montrerDes[3][21] = 'o';
      montrerDes[3][25] = 'o';
    break;
    case 5:
      montrerDes[1][21] = 'o';
      montrerDes[1][25] = 'o';
      montrerDes[2][23] = 'o';  
      montrerDes[3][21] = 'o';
      montrerDes[3][25] = 'o';
    break;
    case 6:
      montrerDes[1][21] = 'o';
      montrerDes[1][25] = 'o';
      montrerDes[1][23] = 'o';
      montrerDes[3][23] = 'o';
      montrerDes[3][21] = 'o';
      montrerDes[3][25] = 'o';
    break;
  }
  switch(jet.des[3])
  {
    case 1:     
      montrerDes[2][33] = 'o';        
    break;
    case 2:
      montrerDes[1][35] = 'o';
      montrerDes[3][31] = 'o';
    break;
    case 3:
      montrerDes[1][35] = 'o';
      montrerDes[2][33] = 'o';
      montrerDes[3][31] = 'o';        
    break;
    case 4:
      montrerDes[1][31] = 'o';
      montrerDes[1][35] = 'o';
      montrerDes[3][31] = 'o';
      montrerDes[3][35] = 'o';
    break;
    case 5:
      montrerDes[1][31] = 'o';
      montrerDes[1][35] = 'o';
      montrerDes[2][33] = 'o';  
      montrerDes[3][31] = 'o';
      montrerDes[3][35] = 'o';
    break;
    case 6:
      montrerDes[1][31] = 'o';
      montrerDes[1][35] = 'o';
      montrerDes[1][33] = 'o';
      montrerDes[3][33] = 'o';
      montrerDes[3][31] = 'o';
      montrerDes[3][35] = 'o';
    break;
  }
  switch(jet.des[4])
  {
    case 1:     
      montrerDes[2][43] = 'o';        
    break;
    case 2:
      montrerDes[1][45] = 'o';
      montrerDes[3][41] = 'o';
    break;
    case 3:
      montrerDes[1][45] = 'o';
      montrerDes[2][43] = 'o';
      montrerDes[3][41] = 'o';        
    break;
    case 4:
      montrerDes[1][41] = 'o';
      montrerDes[1][45] = 'o';
      montrerDes[3][41] = 'o';
      montrerDes[3][45] = 'o';
    break;
    case 5:
      montrerDes[1][41] = 'o';
      montrerDes[1][45] = 'o';
      montrerDes[2][43] = 'o';  
      montrerDes[3][41] = 'o';
      montrerDes[3][45] = 'o';
    break;
    case 6:
      montrerDes[1][41] = 'o';
      montrerDes[1][45] = 'o';
      montrerDes[1][43] = 'o';
      montrerDes[3][43] = 'o';
      montrerDes[3][41] = 'o';
      montrerDes[3][45] = 'o';
    break;
  }   
  for(rangee = 0; rangee < 5; rangee++)
  {
    for(colonne = 0; colonne < 47; colonne++)
    {
      printf("%c",montrerDes[rangee][colonne]);
    }
    printf("\n");
  }
}
