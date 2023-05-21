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
    boutons->vert[1]=load_bitmap("images/Sprite_green_buttonpress.bmp",NULL);
    boutons->rouge[1]=load_bitmap("images/Sprite_red_buttonpress.bmp",NULL);
    boutons->jaune[1]=load_bitmap("images/Sprite_yellow_buttonpress.bmp",NULL);
    boutons->bleu[1]=load_bitmap("images/Sprite_blue_buttonpress.bmp",NULL);
    boutons->orange[1]=load_bitmap("images/Sprite_orange_buttonpress.bmp",NULL);

    boutons->clavier[0]=key[KEY_Q];
    boutons->clavier[1]=key[KEY_W];
    boutons->clavier[2]=key[KEY_E];
    boutons->clavier[3]=key[KEY_R];
    boutons->clavier[4]=key[KEY_SPACE];

    //déclarer la pos des boutons
    boutons->xboutons[0]=XSTAGE+83;
    boutons->xboutons[1]=XSTAGE+259;
    boutons->xboutons[2]=XSTAGE+433;
    boutons->xboutons[3]=XSTAGE+593;
    boutons->xboutons[4]=XSTAGE+767;


    for(int i=0;i<5;i++) {
        boutons->yboutons[i] = 700;
    }


    boutons->color[0]=makecol(176,252,204); //VERT
    boutons->color[1]=makecol(252,188,176); //ROUGE
    boutons->color[2]=makecol(252,228,160); //JAUNE
    boutons->color[3]=makecol(156,252,240); //BLEU
    boutons->color[4]=makecol(252,216,168); //ORANGE
    //à changer quand les bitmap seront faites

    boutons->txb=boutons->tyb=126;
    boutons->txb=boutons->tyb=126;
}



void initScore(t_score *score){
    score->score=0;
    score->xscore=1050;    score->yscore=5;

    score->combo=0;
    score->xcombo=1050;    score->ycombo=50;

    score->color= makecol(255,255,255);
}

void animationBoutons(t_boutons *boutons, BITMAP *page){
    int v,r,j,b,o;
    v = 0;    r = 0;    j = 0;    b = 0;    o = 0;
    if(key[KEY_Q]){
        v++;
        if(v>1)
            v=1;
    }
    if(key[KEY_W]){
        r++;
        if(r>1)
            r=1;
    }
    if(key[KEY_D]){
        j++;
        if(j>1)
            j=1;
    }
    if(key[KEY_SPACE]){
        b++;
        if(b>1)
            b=1;
    }
    if(key[KEY_K]){
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

void detectScore(t_score *score, t_boutons *boutons,BITMAP *page, bool touchePress[5], int toucheIsPress[5]){ // aout ticket si score->score > x
    for(int i=0;i<5;i++){
        if(touchePress[i]){
            if(!toucheIsPress[i]){
                for(int j=0;j<MAXX;j++){
                    if(getpixel(page,boutons->xboutons[i]+35,boutons->yboutons[i]+j)==boutons->color[i]){
                        if(j<=ECARTPARFAIT){
                            score->score+=100*score->combo;
                            score->combo+=2;
                            if(score->combo>8)
                                score->combo=8;
                            toucheIsPress[i]=1;
                            break;
                        }else if(j<=ECARTMOYEN){
                            score->score+=50*score->combo;
                            score->combo+=1;
                            if(score->combo>8)
                                score->combo=8;
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
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    SAMPLE *Kirby= load_sample("Music/Gourmet Race - Kirby： Super Star.wav");
    //vol=255*(1/(*volume));
    BITMAP *buffer;
    BITMAP *background;
    BITMAP *KirbySing;
    buffer= create_bitmap(SCREEN_W,SCREEN_H);
    background = load_bitmap("images/Fond_Kirby.bmp",NULL);
    KirbySing = load_bitmap("images/Kirby_OwO.bmp",NULL);

    while(!key[KEY_ESC]){
        clear(page);
        draw_sprite(page,KirbySing,1490,820);
        blit(background,page,0,0,0,0,SCREEN_W,SCREEN_H);
        if(getpixel(screen,XSTAGE+10,550)==makecol(255,255,255))
            play_sample(Kirby,255,0,1000,1);
        //Rajouter un 3,2,1;
        ystage-=10;

        //blit(stage,page,-XSTAGE,ystage,0,0,SCREEN_W,SCREEN_H);
        touchePress[0] = key[KEY_Q];
        touchePress[1] = key[KEY_W];
        touchePress[2] = key[KEY_D];
        touchePress[3] = key[KEY_SPACE];
        touchePress[4] = key[KEY_K];
        detectScore(score,boutons,buffer,touchePress,toucheIsPress);

        textprintf_ex(page,font,score->xscore,score->yscore,score->color,-1,"score : %ld",score->score);
        textprintf_ex(page,font,score->xcombo,score->ycombo,score->color,-1,"combo : %d",score->combo);

        textprintf_ex(page,font,score->xcombo,100,score->color,-1,"Bouton vert : A");
        textprintf_ex(page,font,score->xcombo,110,score->color,-1,"Bouton rouge : Z");
        textprintf_ex(page,font,score->xcombo,120,score->color,-1,"Bouton jaune : D");
        textprintf_ex(page,font,score->xcombo,130,score->color,-1,"Bouton bleu : SpaceBar");
        textprintf_ex(page,font,score->xcombo,140,score->color,-1,"Bouton orange : K");

        textprintf_ex(page,font,score->xcombo,170,score->color,-1,"Pour avoir un ticket il faut un score de X minimum !");



        draw_sprite(page,stage,XSTAGE,-ystage);
        rectfill(page,0,820,1000,1080, makecol(0,0,0));
        rect(page,0,0,1535,863, makecol(255,255,255));
        animationBoutons(boutons,page);
        blit(page,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);


    }
    destroy_sample(Kirby);
    destroy_bitmap(page);
    destroy_bitmap(buffer);
    destroy_bitmap(stage);
}

int Menu(BITMAP *page,BITMAP *fond,int *x1, int *x2, int *y1, int *y2){
        if(key[KEY_DOWN] && getpixel(screen,250,50)== makecol(0,0,0)){
            *x1=250;
            *x2=1200;
            *y1=400;
            *y2=600;
        }
        if(key[KEY_UP] && getpixel(screen,250,400)==makecol(0,0,0)){
            *x1=250;
            *x2=1200;
            *y1=50;
            *y2=250;

        }
        if(*y1==400 && key[KEY_SPACE]){
            return 2;
        }

        if(*y1==50 && key[KEY_SPACE]){
            return 1;
        }

        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
        rect(page,*x1,*y1,*x2,*y2, makecol(0,0,0));
        rect(page,*x1-1,*y1-1,*x2+1,*y2+1, makecol(0,0,0));
        rect(page,*x1-2,*y1-2,*x2+2,*y2+2, makecol(0,0,0));
        textprintf_ex(page,font,750,146, makecol(0,0,0),-1,"Jouer");
        textprintf_ex(page,font,750,500, makecol(0,0,0),-1,"Quitter");

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(page);
        return 3;
}

void Gh(){
    t_score *score;
    t_boutons *boutons;
    BITMAP *stage;
    BITMAP *page;
    BITMAP *fond;
    bool touchePresse[5] = {false};

    int x1=250;
    int x2=1200;
    int y1=50;
    int y2=250;
    int l=500;


    page= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);


    stage = load_bitmap("images/Stage_Gh_Kirby.bmp",NULL);
    fond = load_bitmap("images/Bckground.bmp",NULL);

    score=(t_score *) malloc(sizeof (t_score));
    boutons=(t_boutons *) malloc(sizeof (t_boutons));


    initBoutons(boutons);
    initScore(score);

    while(!key[KEY_ESC]){
        Menu(page,fond,&x1,&x2,&y1,&y2);


        if(Menu(page,fond,&x1,&x2,&y1,&y2)==1)
            guitareHero(score,boutons,stage,page,YSTAGE,touchePresse);
    }
    free(score);
    free(boutons);
    destroy_bitmap(stage);
    destroy_bitmap(fond);
    destroy_bitmap(page);

}




