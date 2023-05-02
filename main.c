#include "main.h"

int main() {
    BITMAP *map;
    BITMAP *page;
    t_perso *perso;

    int screenx, screeny;
    char buf[80];
    int u,d,r,l;
    int key_up,key_down,key_right,key_left;
    allegro_init();
    install_keyboard();


    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,1920,1080,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    page= create_bitmap(SCREEN_W,SCREEN_H);

    clear_bitmap(page);

    map= load_bitmap_check("images/Game_Boy_Advance_Pokemon_Emerald_Battle_Frontier.bmp");

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
        if (perso->x - screenx > SCREEN_W / 3) {
            screenx = perso->x - SCREEN_W / 4;
        }
        if (perso->x - screenx < SCREEN_W / 3) {
            screenx = perso->x - SCREEN_W / 4;
        }

        if (perso->y - screeny > SCREEN_H / 3) {
            screeny = perso->y - SCREEN_H / 4;
        }
        if (perso->y - screeny < SCREEN_H / 3) {
            screeny = perso->y - SCREEN_H / 4;
        }

        if (screenx < 0) {
            screenx = 0;
        }
        if (screenx > map->w - SCREEN_W / 3) {
            screenx = map->w - SCREEN_W / 3;
        }

        if (screeny < 0) {
            screeny = 0;
        }
        if (screeny > map->h - SCREEN_H / 3) {
            screeny = map->h - SCREEN_H / 3;
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


    return 0;
}
END_OF_MAIN()
