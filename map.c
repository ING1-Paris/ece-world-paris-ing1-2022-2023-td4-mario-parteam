//
// Created by Scotch on 27/04/2023.
//

//sources : https://fercoq.bitbucket.io/allegro/Alleg_C4/3_1_scrolling_sur_un_decor.html
#include "map.h"

BITMAP *load_bitmap_check(char *nomImage){
    BITMAP *bmp;
    bmp=load_bitmap(nomImage,NULL);
    if (!bmp)
    {
        allegro_message("pas pu trouver %s",nomImage);
        exit(EXIT_FAILURE);
    }
    return bmp;
}

void deplacement(t_perso *perso,int *u,int *d,int *r,int *l,int *key_up,int *key_down, int *key_right,int *key_left){
    *key_right=*key_left=*key_up=*key_down=0;
    if(key[KEY_RIGHT]){
        perso->dx=5;
        perso->x+=perso->dx;
        *r+=1;
        *r%=3;
        *key_right=1;
    }
    if(key[KEY_UP]){
        perso->dy=5;
        perso->y-=perso->dy;
        *u+=1;
        *u%=3;
        *key_up=1;
    }
    if(key[KEY_LEFT]){
        perso->dx=5;
        perso->x-=perso->dx;
        *l+=1;
        *l%=3;
        *key_left=1;
    }
    if(key[KEY_DOWN]){
        perso->dy=5;
        perso->y+=perso->dy;
        *d+=1;
        *d%=3;
        *key_down=1;
    }

    if(perso->x<0)
        perso->x=0;
    if(perso->y<0)
        perso->y=0;

}

void deplacementmap(BITMAP *map,t_perso *perso, int screenx,int screeny){
    if(perso->x > SCREEN_W/2){
        screenx = perso->x - SCREEN_W/2;
    }
    if (perso->x < SCREEN_W/2)
        screenx = perso->x - SCREEN_W/2;

    if(perso->y > SCREEN_H/2){
        screeny = perso->y - SCREEN_H/2;
    }
    if (perso->y < SCREEN_H/2)
        screeny = perso->y - SCREEN_H/2;

    if ( screenx < 0 )
        screenx=0;
    if ( screenx > map->w - SCREEN_W )
        screenx=map->w - SCREEN_W;

    if ( screeny < 0 )
        screeny=0;
    if ( screeny > map->h - SCREEN_H )
        screeny=map->h - SCREEN_H;
}