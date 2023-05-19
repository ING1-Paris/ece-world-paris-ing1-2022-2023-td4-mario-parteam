//
// Created by MAJ on 18/05/2023.
//

#ifndef MARIO_PARTEAM_V1_RIVIERE_H
#define MARIO_PARTEAM_V1_RIVIERE_H

#include "generalfunctions.h"
#define RONDINS 25

typedef struct rondins{
    int x,y;
    int dx,dy;
    int prex,prey;
    int tx,ty;
}t_rondins;

void leback ();

#endif //MARIO_PARTEAM_V1_RIVIERE_H
