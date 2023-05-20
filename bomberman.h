//
// Created by Scotch on 25/04/2023.
//

#ifndef MARIO_PARTEAM_V1_BOMBERMAN_H
#define MARIO_PARTEAM_V1_BOMBERMAN_H
#include "generalfunctions.h"
#define ANMATION 5
#define X 13
#define Y 11
#define NBOBJECTS 9
typedef struct joueur{
    int x;
    int y;
    int feu;
    int nb_bombes;
    int vie;
    BITMAP *player[ANMATION];
}t_joueur;

void init_matrice(int matrice[X][Y]);
void init_perso(t_joueur perso[2]);
void explosion(t_joueur perso[],int matrice[X][Y],int *restebombe);
void dplacement(int matrice[X][Y],t_joueur perso[],int *animation,bool touchePressed1[5], bool touchePressed2[5],int toucheIsPress1[5],int toucheIsPress2[5],BITMAP *page);
void affichage(int matrice[X][Y],t_joueur perso[]/*,BITMAP *objects[NBOBJECTS]*/,BITMAP *page);

void Bomberman();
#endif //MARIO_PARTEAM_V1_BOMBERMAN_H
