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
typedef struct {
    int x;
    int y;
    int feu;
    int nb_bombes;
    int vie;
    BITMAP *player[ANMATION];
}t_joueur;

typedef struct {
    int x;
    int y;
    int x_plus_feu[10];
    int x_minus_feu[10];
    int y_plus_feu[10];
    int y_minus_feu[10];
    time_t creation_time;
    int explosion;
}t_bombe;


void init_matrice(int matrice[X][Y]);
void init_perso(t_joueur perso[2]);
void init_bombe(t_bombe bombe[]);
void x_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page);
void x_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page);
void y_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page);
void y_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page);
void explosion(t_joueur perso[],t_bombe bombej1[],t_bombe bombej2[],int matrice[X][Y],int *nbbombe,int *nbbombe2,BITMAP *page);
void dplacement(int matrice[X][Y],t_joueur perso[],int *animation,bool touchePressed1[5], bool touchePressed2[5],int toucheIsPress1[5],int toucheIsPress2[5],BITMAP *page);
void affichage(int matrice[X][Y],t_joueur perso[]/*,BITMAP *objects[NBOBJECTS]*/,BITMAP *page);

void Bomberman();
#endif //MARIO_PARTEAM_V1_BOMBERMAN_H
