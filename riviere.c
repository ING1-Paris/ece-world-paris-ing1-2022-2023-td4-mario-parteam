//
// Created by MAJ on 18/05/2023.
//

#include "riviere.h"

void leback (){
    BITMAP *imageChargee;
    BITMAP *rondins;
    BITMAP *rondins2;

    //chargement de l'image
    imageChargee= load_bitmap("images/riv3.bmp",NULL);
    if (!imageChargee){
        allegro_message("pb image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
     // chargement des rondins
    rondins= load_bitmap("images/RONDINS.bmp",NULL);
    if (!rondins){
        allegro_message("pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    while (!key[KEY_ESC]){
        //affichage de l'image chargée
        //stretch_blit(rondins, rondins2, 0, 0, 32, 9, 0, 0, 128, 46);
        draw_sprite(imageChargee,rondins,250,415);
        draw_sprite(imageChargee,rondins,250,365);
        draw_sprite(imageChargee,rondins,250,315);
        draw_sprite(imageChargee,rondins,250,265);
        draw_sprite(imageChargee,rondins,250,215);
        stretch_blit(imageChargee, screen, 0, 0,imageChargee->w,imageChargee->h,0,0,(0.7*screen->w),(0.7*screen->h));
        //blit(imageChargee,screen,0,0,0,0,imageChargee->w,imageChargee->h);
    }
    destroy_bitmap(imageChargee);
    destroy_bitmap(rondins);
}