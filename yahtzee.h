//*****************************************
#pragma once
#define TAILLE_JET 5

typedef struct Jet Jet;
struct Jet
 {
  int des[TAILLE_JET]; 

 }; 
// Nous avons mis en place cette structure semblable à Jet dont le nom est Jet pour qu'elle 
// puisse recevoir les valeurs des données jouées à chaque tour.


typedef struct Score Score;
struct Score
{
  
  int un;
  int deux;
  int trois;
  int quatre;
  int cinq;
  int six;
  int brelan;
  int carre;
  int mainPleine;
  int petiteSuite;
  int grandeSuite;
  int chance;
  int yahtzee;
};
// / Nous avons mis en place cette structure semblable à Score dont le nom est Score pour qu'elle 
// puisse recevoir les valeurs des jeux choisis par l'utilisateur à chaque tour.


Jet joue (Jet jet);
// ***************************
// dessineDes
//
// Dessiner les données Dès
//
// INPUT:
//      jet: pour les cinq des.
//
// SORTIE:
//      Le dessin de chaque dès correspondant à chaque visage
//
// Exemples:
// . jet.des [face] = montrerDes [rangee] [colonne];
// ***************************
void dessineDes(Jet jet);
// ***************************
// nbDeFace
//
// Calcule le pointage pour la figure "face"
//
// INPUT:
//      jet: cinq dés.
//      face: la face a comptabiliser.
//
// SORTIE:
//      le pointage pour visage dans jet. Le pointage est le produit de face et du
//      nombre de jets qui valent face.
//
// Exemples:
//      nbDeFace ({5,5,1,3,2}, 5) = 2 * 5 = 10;
//      nbDeFace ({5,5,1,3,2}, 1) = 1 * 1 = 1;
//      nbDeFace ({5,5,1,3,2}, 2) = 1 * 2 = 2;
//      nbDeFace ({2,2,1,1,2}, 2) = 3 * 2 = 6;
// ***************************
int nbDeFace (Jet jet, int face);
// ***************************
// brelan
//
// Calcule le pointage pour la figure "brelan"
//
// INPUT:
//      jet: cinq dés.
//
// SORTIE:
//      le pointage pour brelan dans jet. Un brelan est trois visages
//      identiques. Il vaut la somme de dés.
//
// Exemples:
//      brelan ({5,5,1,3,2}) = 0;
//      brelan ({2,2,1,5,2}) = 2 + 2 + 1 + 5 + 2 = 12;
// ***************************
int brelan(Jet jet);
// ***************************
// carre
//
// Calcule le pointage pour la figure "carre"
//
// INPUT:
//       jet: cinq dés.
//
// SORTIE:
//      le pointage pour carre dans jet. Un carre est quatres faces
//      identiques. Il vaut la somme des dés.
//
// Exemples:
//      carre ({5,5,1,3,2}) = 0;
//      carre ({2,2,1,2,2}) = 2 + 2 + 1 + 2 + 2 = 9;
// ***************************
int carre(Jet jet);
// ***************************
// mainPleine
//
// Calcule le pointage pour la figure "main pleine"
//
// INPUT:
//       jet: cinq dés.
//
// SORTIE:
//      le pointage pour main pleine dans jet. Une grande est trois faces
//      identiques et deux vis identiques. Elle vaut 25 points.
//
// Exemples:
//      mainPleine ({5,5,5,3,2}) = 0;
//      mainPleine ({2,2,1,1,2}) = 25;
// ***************************
int mainPleine(Jet jet);
// ***************************
// petiteSuite
//
// Calcule le pointage pour la figure "petite suite"
//
// INPUT:
//      jet: cinq dés.
//
// SORTIE:
//      le pointage pour petite suite dans jet. Une petite suite vaut 30
//      points. Il y a trois petites suites possibles: 1,2,3,4 ou 2,3,4,5 ou
//      3,4,5,6. L'ordre des dés n'a pas d'importance
//
// Exemples:
//      petiteSuite {{5,3,2,3,4}) = 30;
//      petiteSuite ({2,3,5,6,1}) = 0;
// ***************************
int petiteSuite(Jet jet);
// ***************************
// grandeSuite
//
// Calcule le pointage pour la figure "grande suite"
//
// INPUT:
//      jet: cinq dés.
//
// SORTIE:
//      le pointage pour grande suite dans jet. Une grande suite vaut 40
//      points. Il y a deux grandes suites possibles: 1,2,3,4,5 ou
//      2,3,4,5,6. L'ordre des dés n'a pas d'importance.
//
// Exemples:
//      grandeSuite {{5,3,2,6,4}) = 40;
//      grandeSuite ({2,3,5,6,1}) = 0;
// ***************************
int grandeSuite(Jet jet);
// ***************************
// yahtzee
//
// Calcule le pointage pour la figure "yahtzee"
//
// INPUT:
//      jet: cinq dés.
//
// SORTIE:
//      le pointage pour yahtzee dans jet. Un yahtzee est cinq des identiques. Il
//      vaut 50 points.
//
// Exemples:
//      yahtzee {{2,2,2,2,2}) = 50;
//      yahtzee ({2,3,2,2,2}) = 0;
// ***************************
int yahtzee(Jet jet);
// ***************************
// chance
//
// Calcule le pointage pour la figure "chance"
//
// INPUT:
//      jet: cinq dés.
//
// SORTIE:
//      le pointage pour la chance est la somme des visages.
//
// Exemples:
//      chance {{5,6,2,1,4}) = 18;
//      chance ({1,1,1,1,3}) = 7;
// ***************************
int chance(Jet jet);
void testJour (Jet jet);
void match (Jet jet);
// Nous faisons ici la déclaration de chacune des fonctions utilisées dans le jeu.