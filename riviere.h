//
// Created by MAJ on 18/05/2023.
//

#ifndef MARIO_PARTEAM_V1_RIVIERE_H
#define MARIO_PARTEAM_V1_RIVIERE_H

#include "generalfunctions.h"
#define RONDINS 25

typedef struct lesrondins{
    int x,y;    //position du coin supérieur gauche
    int dx;     //le mouvement se fait uniquement sur x
    int etat;   //sur l'eau ou non
    int rayons; //quelle ligne
    int tmpdx;  // ralentir les déplacements en x
    int cptdx;  // compteur de ralentissement
    int tx,ty;  // largeur et hauteur
}t_rondins;

//typedef struct leperso{
//    int x,y;    //position du coin supérieur gauche
//
//}t_perso;

void lejeu();

t_rondins * creerRONDINS(int etat, int x, int y, int dx, int tmpdx);
void remplirlesrondins(t_rondins * tab[RONDINS]);
void actualiserRondins(t_rondins *rondins);
void actualiserlesrondins(t_rondins * tab[RONDINS]);
void dessinerRondins(BITMAP *bmp, t_rondins *rondins, BITMAP* lerondin);
void dessinerlesrondins(BITMAP *bmp,t_rondins * tab[RONDINS], BITMAP *lerondin);
//void mouvPerso(t_perso* monperso, BITMAP *page, BITMAP *perso[4]);
//void victoire(t_perso* monperso);

#endif //MARIO_PARTEAM_V1_RIVIERE_H
