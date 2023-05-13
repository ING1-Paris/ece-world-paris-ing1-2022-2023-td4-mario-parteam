//
// Created by Scotch on 27/04/2023.
//

#ifndef MARIO_PARTEAM_V1_MAP_H
#define MARIO_PARTEAM_V1_MAP_H
#include "generalfunctions.h"

/*typedef struct perso t_perso;
int contactBordActeur(t_perso *perso, BITMAP *bmp, int couleur);
void deplacement(t_perso *perso);
BITMAP * load_bitmap_check(char *nomImage);
void init_perso(t_perso *perso);
void dep_carte(BITMAP *page,BITMAP *decor,t_perso *perso,int screenx, int screeny);*/

typedef struct perso{
    int x,y;
    int dx,dy;
    int prex,prey;
    int tx,ty;
    BITMAP *front[3];
    BITMAP *back[3];
    BITMAP *side[3];
}t_perso;
BITMAP * load_bitmap_check(char *nomImage);
void deplacement(t_perso *perso,int *u,int *d,int *r,int *l,int *key_up,int *key_down, int *key_right,int *key_left);
void deplacementmap(BITMAP *map,t_perso *perso, int screenx,int screeny);
void map();



#endif //MARIO_PARTEAM_V1_MAP_H
