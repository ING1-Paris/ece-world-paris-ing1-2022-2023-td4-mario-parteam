#include "main.h"

int main() {
    BITMAP *map;
    BITMAP *page;
    t_perso *perso;

    int screenx, screeny;

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

    perso->img = load_bitmap_check("images/Game Boy Advance - Pokemon Emerald - Red & Leaf.bmp");
    perso->x=0;
    perso->y=0;
    perso->dx=0;
    perso->dy=0;

    while(!key[KEY_ESC]){


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
        blit(map,page,screenx,screeny,0,0,SCREEN_W,SCREEN_H);
        deplacement(perso);
        draw_sprite(page,perso->img,perso->x,perso->y);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_W);
        rest(10);
    }
    free(perso);
    destroy_bitmap(map);
    destroy_bitmap(page);


    return 0;
}
END_OF_MAIN()
