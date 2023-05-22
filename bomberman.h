//
// Created by Scotch on 25/04/2023.
//

#ifndef MARIO_PARTEAM_V1_BOMBERMAN_H
#define MARIO_PARTEAM_V1_BOMBERMAN_H
#include "generalfunctions.h"
#define ANMATION 3
#define X 13
#define Y 11
#define NBOBJECTS 8
typedef struct {
    int x;
    int y;
    int feu;
    int nb_bombes;
    int vie;
    BITMAP *front[ANMATION];
    BITMAP *back[ANMATION];
    BITMAP *side[ANMATION];
}t_joueur;

typedef struct {
    int x;
    int y;
    int matrice[X][Y];
    time_t creation_time;
    int explosion;
    int explosion_now;
}t_bombe;


void init_matrice(int matrice[X][Y]);
void init_perso(t_joueur perso[2]);
void init_bombe(t_bombe bombe[]);
void x_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe);
void x_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe);
void y_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe);
void y_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe);
void explosion(t_joueur perso[],t_bombe bombej1[],t_bombe bombej2[],int matrice[X][Y],int *nbbombe1,int *nbbombe2,BITMAP *page,BITMAP *Object[NBOBJECTS],BITMAP *stage,int u1,int d1,int r1,int l1,int u2,int d2,int r2,int l2,bool touchePressed1, bool touchePressed2,int *toucheIsPress1,int *toucheIsPress2,BITMAP *mortj1,BITMAP *mortj2);
void dplacement(int matrice[X][Y],t_joueur perso[],int *animation,bool touchePressed1[5], bool touchePressed2[5],int toucheIsPress1[5],int toucheIsPress2[5],BITMAP *page,BITMAP *Object[NBOBJECTS],BITMAP *stage,int *u1,int *d1,int *r1,int *l1,int *u2,int *d2,int *r2,int *l2,BITMAP *mortj1,BITMAP *mortj2);
void affichage(int matrice[X][Y],t_joueur perso[],BITMAP *objects[NBOBJECTS],BITMAP *page,BITMAP *stage,BITMAP *mortj1,BITMAP *mortj2,int u1,int d1,int r1,int l1,int u2,int d2,int r2,int l2);
int Meenu(BITMAP *page,BITMAP *fond,int *x1, int *x2, int *y1, int *y2,SAMPLE *MenuSound);

void Bomberman();
#endif //MARIO_PARTEAM_V1_BOMBERMAN_H
