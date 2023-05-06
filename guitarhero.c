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

void detectScore(t_score *score, t_boutons *boutons,BITMAP *page){
    int press;
    int ybuffer[5];
    press=0;
    for(int i=0;i<5;i++){
        ybuffer[i]=boutons->yboutons[i];
        for(int j=-ECARTPARFAIT/2;j<ECARTPARFAIT;j++){
            ybuffer[i]+=j;
            if(keypressed()==boutons->clavier[i] && getpixel(page,boutons->xboutons[i],ybuffer[i])==boutons->color[i]){
                press=PARFAIT;
            }else
                for(int k=-ECARTMOYEN/2;k<ECARTMOYEN;k++){
                    ybuffer[i]+=k;
                    if(keypressed()==boutons->clavier[i] && getpixel(page,boutons->xboutons[i],ybuffer[i])==boutons->color[i]){
                        press=MOYEN;
                    }else
                        press=RATE;
                }
        }
    }
    score->score+=press;
}



