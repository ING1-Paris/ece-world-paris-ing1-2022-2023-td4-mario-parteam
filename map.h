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
    BITMAP *img;
}t_perso;
BITMAP * load_bitmap_check(char *nomImage);
void deplacement(t_perso *perso);
void deplacementmap(BITMAP *map,t_perso *perso, int screenx,int screeny);



#endif //MARIO_PARTEAM_V1_MAP_H
