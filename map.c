//
// Created by Scotch on 27/04/2023.
//

//sources : https://fercoq.bitbucket.io/allegro/Alleg_C4/3_1_scrolling_sur_un_decor.html
#include "map.h"

/*BITMAP *load_bitmap_check(char *nomImage){
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


void map(){

    BITMAP *map;
    BITMAP *page;
    t_perso *perso;

    int screenx, screeny;
    char buf[80];
    int u,d,r,l;
    int key_up,key_down,key_right,key_left;

    page= create_bitmap(SCREEN_W,SCREEN_H);

    clear_bitmap(page);

    map= load_bitmap_check("images/LAMAP.bmp");

    perso=(t_perso *) malloc(sizeof (t_perso));

    for(int i=0;i<3;i++){
        sprintf(buf,"images/red-front%d.bmp",i);
        perso->front[i] = load_bitmap_check(buf);
    }
    for(int j=0;j<3;j++){
        sprintf(buf,"images/red-back%d.bmp",j);
        perso->back[j] = load_bitmap_check(buf);
    }
    for(int k=0;k<3;k++){
        sprintf(buf,"images/red-side%d.bmp",k);
        perso->side[k] = load_bitmap_check(buf);
    }


    perso->x=0;
    perso->y=0;
    perso->dx=0;
    perso->dy=0;
    perso->tx=16;
    perso->ty=21;

    u=d=r=l=0;
    draw_sprite(page,perso->front[0],perso->x,perso->y);

    while(!key[KEY_ESC]){
        if (perso->x - screenx > SCREEN_W /2) {
            screenx = perso->x - SCREEN_W /2;
        }
        if (perso->x - screenx < SCREEN_W /2) {
            screenx = perso->x - SCREEN_W /2;
        }

        if (perso->y - screeny > SCREEN_H /2) {
            screeny = perso->y - SCREEN_H /2;
        }
        if (perso->y - screeny < SCREEN_H /2) {
            screeny = perso->y - SCREEN_H /2;
        }

        if (screenx < 0) {
            screenx = 0;
        }
        if (screenx > map->w ) {
            screenx = map->w;
        }

        if (screeny < 0) {
            screeny = 0;
        }
        if (screeny > map->h ) {
            screeny = map->h;
        }

        stretch_blit(map,page,screenx,screeny,SCREEN_W/3,SCREEN_H/3,0,0,SCREEN_W,SCREEN_H);
        //blit(map,page,screenx,screeny,0,0,SCREEN_W,SCREEN_H);
        deplacement(perso,&u,&d,&r,&l,&key_up,&key_down,&key_right,&key_left);
        if(key_up>0){
            draw_sprite(page,perso->back[u],perso->x,perso->y);
        }else if(key_down>0){
            draw_sprite(page,perso->front[d],perso->x,perso->y);
        }else if(key_left>0){
            draw_sprite(page,perso->side[l],perso->x,perso->y);
        }else if(key_right>0){
            draw_sprite_h_flip(page,perso->side[r],perso->x,perso->y);
        }


        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_W);
        rest(10);
    }
    free(perso);
    destroy_bitmap(map);
    destroy_bitmap(page);
}*/
void initialisation_perso(t_perso *perso){
    perso->tx=16;
    perso->ty=21;
    perso->x=1920/2 + perso->tx;
    perso->y=1080/2 + perso->ty;
    perso->dx=0;
    perso->dy=0;
}

void collision(BITMAP *page,t_perso *perso,t_map *map,int *u,int *d, int *r,int *l){
    for(int i=0;i<20;i++){
        if(getpixel(map->collision,map->x-perso->x,perso->y));
        if(key[KEY_UP]){
            *u+=*u+1;
            *u%=3;
            map->dy=5;
            map->y-=map->dy;
        }
        if(key[KEY_DOWN]){
            *d+=*d+1;
            *d%=3;
            map->dy=5;
            map->y+=map->dy;
        }
        if(key[KEY_RIGHT]){
            *r+=*r+1;
            *r%=3;
            map->dx=5;
            map->x+=map->dx;
        }
        if(key[KEY_LEFT]){
            *l+=*l+1;
            *l%=3;
            map->dx=5;
            map->x-=map->dx;
        }
    }





}

void map(){

}