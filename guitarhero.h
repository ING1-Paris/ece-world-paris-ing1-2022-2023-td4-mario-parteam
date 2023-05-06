//
// Created by Scotch on 25/04/2023.
//

#ifndef MARIO_PARTEAM_V1_GUITARHERO_H
#define MARIO_PARTEAM_V1_GUITARHERO_H
#include "generalfunctions.h"
#define PARFAIT 100
#define MOYEN 50
#define RATE 0
#define ANIMATION 5
#define ECARTPARFAIT 10
#define ECARTMOYEN 100
typedef struct boutons{
    BITMAP *vert[ANIMATION];    //0     a
    BITMAP *rouge[ANIMATION];   //1     z
    BITMAP *jaune[ANIMATION];   //2     e
    BITMAP *bleu[ANIMATION];    //3     r
    BITMAP *orange[ANIMATION];  //4     t
    int clavier[5];
    int xboutons[5];
    int yboutons[5];
    int color[5];
}t_boutons;

typedef struct score{
    long int score;
    //tab de score ?
    short int combo;
}t_score;

void initBoutons(t_boutons *boutons);
void menuGh();
void animationBoutons(t_boutons *boutons);
void detectScore(t_score *score, t_boutons *boutons,BITMAP *page); // appeler animationBoutons dans cette fonction
void guitareHero(t_score *score, t_boutons *boutons); //fonction final du jeu, avec BITMAP *stage, menu.... ect


#endif //MARIO_PARTEAM_V1_GUITARHERO_H