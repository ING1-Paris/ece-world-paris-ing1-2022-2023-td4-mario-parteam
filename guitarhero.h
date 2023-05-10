//
// Created by Scotch on 25/04/2023.
//

#ifndef MARIO_PARTEAM_V1_GUITARHERO_H
#define MARIO_PARTEAM_V1_GUITARHERO_H
#include "generalfunctions.h"
#define PARFAIT 100
#define MOYEN 50
#define RATE 0
#define ANIMATION 2
#define ECARTPARFAIT 20
#define ECARTMOYEN 50
#define MAXX 100
#define XSTAGE 205
#define YSTAGE 30000
typedef struct boutons{
    BITMAP *vert[ANIMATION];    //0     a
    BITMAP *rouge[ANIMATION];   //1     z
    BITMAP *jaune[ANIMATION];   //2     e
    BITMAP *bleu[ANIMATION];    //3     r
    BITMAP *orange[ANIMATION];  //4     t
    char clavier[5];
    int xboutons[5];
    int yboutons[5];
    int color[5];
    int txb, tyb;
}t_boutons;

typedef struct score{
    long int score;
    int xscore, yscore;
    //tab de score ?
    int combo;
    int xcombo,ycombo;
    int color;
}t_score;

void initBoutons(t_boutons *boutons);
void initStage(int *xstage,int *ystage);
void initScore(t_score *score);
void menuGh();
void animationBoutons(t_boutons *boutons, BITMAP *page);
void detectScore(t_score *score, t_boutons *boutons,BITMAP *page, bool touchePress[5], int toucheIsPress[5]); // appeler animationBoutons dans cette fonction
void guitareHero(t_score *score, t_boutons *boutons, BITMAP *stage, BITMAP *page, int ystage, bool touchePress[5]); //fonction final du jeu, avec BITMAP *stage, menu.... ect


#endif //MARIO_PARTEAM_V1_GUITARHERO_H