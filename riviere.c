//
// Created by MAJ on 18/05/2023.
//

#include "riviere.h"

void lejeu(){
    t_rondins* lesrondins[RONDINS];

    BITMAP *page; //buffer d'affichage
    BITMAP *imageChargee; //image de fond
    BITMAP *rondins;
    //BITMAP *Perso[4];

    //t_perso *leperso;

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

    /*
     *  Perso[0]= load_bitmap("DEDOS.bmp",NULL);
    if (!Perso[0]) {
        allegro_message("pb de l'image 1 chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    Perso[1]= load_bitmap("SAUTE.bmp",NULL);
    if (!Perso[1]) {
        allegro_message("pb de l'image 2 chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    Perso[2]= load_bitmap("AGAUCHE.bmp",NULL);
    if (!Perso[2]) {
        allegro_message("pb de l'image 3 chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    Perso[3]= load_bitmap("ADROITE.bmp",NULL);
    if (!Perso[3]) {
        allegro_message("pb de l'image 4 chargee");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
     */

    remplirlesrondins( lesrondins);

    while (!key[KEY_ESC]) {
        stretch_blit(imageChargee, page, 0, 0,imageChargee->w,imageChargee->h,0,0,(0.7*page->w),(0.7*page->h));
        //blit(imageChargee,page,0,0,0,0,SCREEN_W,SCREEN_H);
        actualiserlesrondins(lesrondins);

        dessinerlesrondins(page,lesrondins,rondins);

        //mouvPerso(leperso,page,Perso);

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

//on remplit l'etat, le x de depart, la hauteur, la vitesse de chaque rayon, et on garde le même écart
// de temps pour chaque
{
    tab[0]=creerRONDINS( 0,0,280,4,1);
    tab[1]=creerRONDINS( 0,163,280,4,1);
    tab[2]=creerRONDINS( 0,300,280,4,1);
    tab[3]=creerRONDINS( 0,300,280,4,1);//superposé pour qu'il n'existe pas
    tab[4]=creerRONDINS( 0,550,280,4,1);
    tab[5]=creerRONDINS( 0,0,345,3,1);
    tab[6]=creerRONDINS( 0,200,345,3,1);
    tab[7]=creerRONDINS( 0,300,345,3,1);
    tab[8]=creerRONDINS( 0,600,345,3,1);
    tab[9]=creerRONDINS( 0,600,345,3,1);//pareil
    tab[10]=creerRONDINS( 0,0,415,4,1);
    tab[11]=creerRONDINS( 0,250,415,4,1);
    tab[12]=creerRONDINS( 0,500,415,4,1);
    tab[13]=creerRONDINS( 0,500,415,4,1);//pareil
    tab[14]=creerRONDINS( 0,750,415,4,1);
    tab[15]=creerRONDINS( 0,0,480,3,1);
    tab[16]=creerRONDINS( 0,150,480,3,1);
    tab[17]=creerRONDINS( 0,150,480,3,1);//pareil
    tab[18]=creerRONDINS( 0,600,480,3,1);
    tab[19]=creerRONDINS( 0,750,480,3,1);
    tab[20]=creerRONDINS( 0,0,545,4,1);
    tab[21]=creerRONDINS( 0,150,545,4,1);
    tab[22]=creerRONDINS( 0,450,545,4,1);
    tab[23]=creerRONDINS( 0,450,545,4,1);//pareil
    tab[24]=creerRONDINS( 0,750,545,4,1);
}

void actualiserRondins(t_rondins *rondins)
{

    // gestion des bords "à la pac man"
    // sur cet exemple seulement sur l'axe x (car pas de dy)
    if (rondins->x+rondins->tx < 0) rondins->x=SCREEN_W;
    if (rondins->x >(0.7*SCREEN_W)) rondins->x=-rondins->tx;

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

/*
 * void mouvPerso(t_perso* monperso, BITMAP *page, BITMAP *perso[4]){
    if(key[KEY_L]){
        monperso->x=monperso->x+10;
        draw_sprite(page,perso[3],monperso->x,monperso->y);
    }
    if(key[KEY_I]){
        monperso->y=monperso->y-10;
        draw_sprite(page,perso[1],monperso->x,monperso->y);
    }
    if(key[KEY_J]){
        monperso->x=monperso->x-10;
        draw_sprite(page,perso[2],monperso->x,monperso->y);
    }
    if(key[KEY_K]){
        monperso->y=monperso->y+10;
        draw_sprite(page,perso[1],monperso->x,monperso->y);
    }
}

void victoire(t_perso* monperso){
    if (monperso->y<=270){
        allegro_message("GAGNEEEEEEEEE");
    }
}
 */