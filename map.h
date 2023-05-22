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


#define MAP_W 2048
#define MAP_H 1167

#define ZOOM_FACTOR 2

#define PLAYER_W 32
#define PLAYER_H 32
#define PLAYER_ANIM_COUNT 3

#define PLAYER_START_X 700
#define PLAYER_START_Y 500

#include "guitarhero.h"
#include "bomberman.h"
#include "riviere.h"
#include "TirAuxBallons.h"
#include "Taupes.h"
#include "PPC.h"

void map();



#endif //MARIO_PARTEAM_V1_MAP_H