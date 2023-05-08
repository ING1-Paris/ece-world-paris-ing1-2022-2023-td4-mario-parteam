//
// Created by Scotch on 25/04/2023.
//

#include "guitarhero.h"

void initBoutons(t_boutons *boutons){
    //load les bitmaps
    boutons->clavier[0]=KEY_A;
    boutons->clavier[1]=KEY_Z;
    boutons->clavier[2]=KEY_E;
    boutons->clavier[3]=KEY_R;
    boutons->clavier[4]=KEY_T;
    //déclarer la pos des boutons
    boutons->color[0]=makecol(0,255,0); //VERT
    boutons->color[0]=makecol(255,0,0); //ROUGE
    boutons->color[0]=makecol(255,255,0); //JAUNE
    boutons->color[0]=makecol(0,0,255); //BLEU
    boutons->color[0]=makecol(255,128,0); //ORANGE
    //à changer quand les bitmap seront faites
}

void initStage(BITMAP *stage,int *xstage,int *ystage){
    stage= load_bitmap("test",NULL);
    xstage=0;
    ystage=0;
}

void initScore(t_score *score){
    score->score=0;
    score->xscore=0;    score->yscore=0;

    score->combo=0;
    score->xcombo=0;    score->ycombo=0;
}



void detectScore(t_score *score, t_boutons *boutons,BITMAP *page){
    int press;
    float multiplier;
    int ybuffer[5];
    multiplier=0;
    press=0;
    for(int i=0;i<5;i++){
        ybuffer[i]=boutons->yboutons[i];
        for(int j=-ECARTPARFAIT/2;j<ECARTPARFAIT;j++){
            ybuffer[i]+=j;
            if(keypressed()==boutons->clavier[i] && getpixel(page,boutons->xboutons[i],ybuffer[i])==boutons->color[i]){
                press=PARFAIT;
                multiplier=0.4;
            }else
                for(int k=-ECARTMOYEN/2;k<ECARTMOYEN;k++){
                    ybuffer[i]+=k;
                    if(keypressed()==boutons->clavier[i] && getpixel(page,boutons->xboutons[i],ybuffer[i])==boutons->color[i]){
                        press=MOYEN;
                        multiplier=0.2;
                    }else{
                        press=RATE;
                        score->combo=0;
                    }
                }
        }
    }
    score->combo+=multiplier;
    if(score->combo>8){
        score->combo=8;
    }
    score->score+=press;
}


void guitareHero(t_score *score, t_boutons *boutons, BITMAP *stage, BITMAP *page,int *xstage,int *ystage){ //rajouter une condition quand un autre stage sera créé
    int fin;
    initBoutons(boutons);
    initStage(stage,xstage,ystage);
    initScore(score);

    while(!key[KEY_ESC]){
        //Rajouter un 3,2,1;

        ystage--;
        blit(stage,page,*xstage,*ystage,0,0,SCREEN_W,SCREEN_H);
        detectScore(score,boutons,page);
    }


}




