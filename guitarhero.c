//
// Created by Scotch on 25/04/2023.
//

#include "guitarhero.h"

void initBoutons(t_boutons *boutons){
    //load les bitmaps
    boutons->vert[0]=load_bitmap("images/Sprite_green_button.bmp",NULL);
    boutons->rouge[0]=load_bitmap("images/Sprite_red_button.bmp",NULL);
    boutons->jaune[0]=load_bitmap("images/Sprite_yellow_button.bmp",NULL);
    boutons->bleu[0]=load_bitmap("images/Sprite_blue_button.bmp",NULL);
    boutons->orange[0]=load_bitmap("images/Sprite_orange_button.bmp",NULL);

    boutons->clavier[0]=key[KEY_Q];
    boutons->clavier[1]=key[KEY_W];
    boutons->clavier[2]=key[KEY_E];
    boutons->clavier[3]=key[KEY_R];
    boutons->clavier[4]=key[KEY_T];

    //déclarer la pos des boutons
    for(int i=0;i<5;i++){
        boutons->xboutons[i]=250+60*i;//RECALLER
        boutons->yboutons[i]=800;
    }


    boutons->color[0]=makecol(176,252,204); //VERT
    boutons->color[1]=makecol(252,188,176); //ROUGE
    boutons->color[2]=makecol(252,228,160); //JAUNE
    boutons->color[3]=makecol(156,252,240); //BLEU
    boutons->color[4]=makecol(252,216,168); //ORANGE
    //à changer quand les bitmap seront faites

    boutons->txb=boutons->tyb=24;
    boutons->txb=boutons->tyb=24;
}



void initScore(t_score *score){
    score->score=0;
    score->xscore=1200;    score->yscore=0;

    score->combo=0;
    score->xcombo=1200;    score->ycombo=50;

    score->color= makecol(255,255,255);
}

void animationBoutons(t_boutons *boutons, BITMAP *page){
    int v,r,j,b,o;
    v = 0;    r = 0;    j = 0;    b = 0;    o = 0;
    if(key[KEY_A]){
        v++;
        if(v>1)
            v=1;
    }
    if(key[KEY_A]){
        r++;
        if(r>1)
            r=1;
    }
    if(key[KEY_A]){
        j++;
        if(j>1)
            j=1;
    }
    if(key[KEY_A]){
        b++;
        if(b>1)
            b=1;
    }
    if(key[KEY_A]){
        o++;
        if(o>1)
            o=1;
    }
    draw_sprite(page, boutons->vert[v],boutons->xboutons[0],boutons->yboutons[0]);
    draw_sprite(page, boutons->rouge[r],boutons->xboutons[1],boutons->yboutons[1]);
    draw_sprite(page, boutons->jaune[j],boutons->xboutons[2],boutons->yboutons[2]);
    draw_sprite(page, boutons->bleu[b],boutons->xboutons[3],boutons->yboutons[3]);
    draw_sprite(page, boutons->orange[o],boutons->xboutons[4],boutons->yboutons[4]);
}



/*void detectScore(t_score *score, t_boutons *boutons){
    int press;
    int multiplier;
    int ybuffer[5];
    multiplier=0;
    press=0;
    clear_keybuf();
    for(int i=0;i<5;i++){
        ybuffer[i]=boutons->yboutons[i];
        for(int j=0;j<ECARTPARFAIT;j++){
            ybuffer[i]+=j;
            textprintf_ex(screen,font,1000,0+10*i,score->color,-1,"%d",ybuffer[i]-boutons->tyb);
            textprintf_ex(screen,font,1000,100+10*i,score->color,-1,"%d",boutons->xboutons[i]+boutons->txb);
            if(keypressed()==boutons->clavier[i] && getpixel(screen,boutons->xboutons[i]+boutons->txb,ybuffer[i]-boutons->tyb)==boutons->color[i]){
                press=PARFAIT;
                multiplier=2;
                break;
            }else
                for(int k=0;k<ECARTMOYEN;k++){
                    ybuffer[i]+=k;
                    textprintf_ex(screen,font,1000,200+10*i,score->color,-1,"%d",ybuffer[i]-boutons->tyb);
                    textprintf_ex(screen,font,1000,300+10*i,score->color,-1,"%d",boutons->xboutons[i]+boutons->txb);
                    if(keypressed()==boutons->clavier[i] && getpixel(screen,boutons->xboutons[i]+boutons->txb,ybuffer[i]-boutons->tyb)==boutons->color[i]){
                        press=MOYEN;
                        multiplier=1;
                        break;

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
    score->score+=press*score->combo;

    textprintf_ex(screen,font,1000,50,score->color,-1,"%d",score->combo);
    textprintf_ex(screen,font,1000,100,score->color,-1,"%d",score->combo);

}*/

void detectScore(t_score *score, t_boutons *boutons,BITMAP *page, bool touchePress[5], int toucheIsPress[5]){
    for(int i=0;i<5;i++){
        if(touchePress[i]){
            if(!toucheIsPress[i]){
                for(int j=0;j<MAXX;j++){
                    if(getpixel(page,boutons->xboutons[i],boutons->yboutons[i]+j)==boutons->color[i]){
                        if(j<=ECARTPARFAIT){
                            score->combo+=2;
                            if(score->combo>8)
                                score->combo=8;
                            score->score+=100*score->combo;
                            toucheIsPress[i]=1;
                            break;
                        }else if(j<=ECARTMOYEN){
                            score->combo+=1;
                            if(score->combo>8)
                                score->combo=8;
                            score->score+=50*score->combo;
                            toucheIsPress[i]=1;
                            break;
                        }else{
                            score->combo=0;
                            toucheIsPress[i]=1;
                            break;
                        }
                    }
                }
            }
        }else
            toucheIsPress[i]=0;
    }
}

void guitareHero(t_score *score, t_boutons *boutons, BITMAP *stage, BITMAP *page,int ystage, bool touchePress[5]){ //rajouter une condition quand un autre stage sera créé
    int toucheIsPress[5] = {0};
    while(!key[KEY_ESC]){
        //Rajouter un 3,2,1;
        ystage--;
        blit(stage,page,-XSTAGE,ystage,0,0,SCREEN_W,SCREEN_H);
        touchePress[0] = key[KEY_Q];
        touchePress[1] = key[KEY_W];
        touchePress[2] = key[KEY_E];
        touchePress[3] = key[KEY_R];
        touchePress[4] = key[KEY_T];
        detectScore(score,boutons,page,touchePress,toucheIsPress);

        textprintf_ex(screen,font,score->xscore,score->yscore,score->color,-1,"score : %ld",score->score);
        textprintf_ex(screen,font,score->xcombo,score->ycombo,score->color,-1,"combo : %d",score->combo);
        //animationBoutons(boutons,page);



        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}




