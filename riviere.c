//
// Created by MAJ on 18/05/2023.
//

#include "riviere.h"

void lejeu(){
    t_rondins* lesrondins[RONDINS];

    BITMAP *page; //buffer d'affichage
    BITMAP *imageChargee; //image de fond
    BITMAP *rondins;

    srand(time(NULL));

    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    //chargement de l'image
    imageChargee = load_bitmap("images/riv3.bmp", NULL);
    if (!imageChargee) {
        allegro_message("pb de l'image chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    rondins = load_bitmap("images/RONDINS.bmp", NULL);
    if (!rondins) {
        allegro_message("pb du rondin chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    remplirlesrondins( lesrondins);

    while (!key[KEY_ESC]) {
        stretch_blit(imageChargee, page, 0, 0,imageChargee->w,imageChargee->h,0,0,(1.1*SCREEN_W),(1.1*SCREEN_H));

        actualiserlesrondins(lesrondins);

        dessinerlesrondins(page,lesrondins,rondins);


        blit(page,screen,0,0,0,0,(SCREEN_W),(SCREEN_H));

        rest(20);

    }
    destroy_bitmap(page);
    destroy_bitmap(rondins);
}


t_rondins * creerRONDINS(int etat, int x, int y, int dx, int tmpdx)
{
    // pointeur sur l'acteur qui sera créé (et retourné)
    t_rondins *rondins;

    // Création (allocation)
    rondins = (t_rondins *)malloc(1*sizeof(t_rondins));

    // Initialisation place et déplacement
    rondins->x=x;
    rondins->y=y;
    rondins->dx=dx;
    rondins->tmpdx=tmpdx;
    rondins->cptdx=0;
    rondins->etat=0;

    return rondins;
}

void remplirlesrondins(t_rondins * tab[RONDINS])
{
    for (int i = 0; i < RONDINS; ++i) {
        if(i<5){
            //                   (etat,   x,    y,   dx,   tmpdx )
            tab[i]=creerRONDINS( 0,0,415,3,1);
        }
        else if(i<10){
            tab[i]=creerRONDINS( 0,0,365,4,1);
        }
        else if (i<15){
            tab[i]=creerRONDINS( 0,0,315,5,1);
        }
        else if (i<20){
            tab[i]=creerRONDINS( 0,0,265,3,1);
        }
        else{
            tab[i]=creerRONDINS( 0,0,215,4,1);
        }

    }
}

void actualiserRondins(t_rondins *rondins)
{

    // gestion des bords "à la pac man"
    // sur cet exemple seulement sur l'axe x (car pas de dy)
    if (rondins->x+rondins->tx < 0) rondins->x=SCREEN_W;
    if (rondins->x >SCREEN_W) rondins->x=-rondins->tx;

    // calculer nouvelle position
    // nouvelle position = position actuelle + deplacement seulement une fois sur tmpdx
    // sur cet exemple seulement sur l'axe x (car pas de dy)
    rondins->cptdx++;
    if (rondins->cptdx >= rondins->tmpdx){
        rondins->cptdx=0;
        rondins->x = rondins->x + rondins->dx;
    }

}

void actualiserlesrondins(t_rondins * tab[RONDINS])
{
    int i;

    for (i=0;i<RONDINS;i++)
        actualiserRondins(tab[i]);
}

// Dessiner un acteur sur une bitmap bmp
void dessinerRondins(BITMAP *bmp, t_rondins *rondins, BITMAP* lerondin)
{
    draw_sprite(bmp, lerondin, rondins->x, rondins->y);
}

// Dessiner l'ensemble des acteurs sur une bitmap bmp
void dessinerlesrondins(BITMAP *bmp,t_rondins * tab[RONDINS], BITMAP *lerondin)
{
    int i;

    for (i=0;i<RONDINS;i++)
        dessinerRondins(bmp,tab[i],lerondin);
}