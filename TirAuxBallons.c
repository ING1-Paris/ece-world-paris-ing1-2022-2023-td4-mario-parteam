//
// Created by Laure on 21/05/2023.
//

#include "TirAuxBallons.h"

t_acteur creerActeur ()
{
    t_acteur acteur;

    //allocation
    // acteur = (t_acteur ) malloc(1*sizeof(t_acteur));

    // definition taille
    acteur.tx=123;
    acteur.ty=163;

    // initialisation position
    acteur.x =rand() % (SCREEN_W - acteur.tx)-acteur.tx/3;
    acteur.y = rand() % (SCREEN_H - acteur.ty);

    // Initialiser vecteurs déplacement aléatoire
    acteur.dx=rand() % (5-1)+1;
    acteur.dy=rand() % (30-10)+1;

    acteur.vivant=0;

    return (acteur);
}

/*void remplirTabActeurs(t_acteur * tab[NBALLONS])
{
    int i;
    for (i=0;i<NBALLONS;i++)
        tab[i]=creerActeur();
}*/

// Actualiser un acteur (bouger ...)
t_acteur actualiserActeur(t_acteur acteur) // avec controle des bords
{
    // contrôle des bords : ici on décide de rebondir sur les bords
    if  (  ( acteur.x <= 0 && acteur.dx <= 0 ) ||( acteur.x + acteur.tx > SCREEN_W && acteur.dx > 0) ){
        acteur.dx = -acteur.dx;}

    if  (  ( acteur.y < 0 && acteur.dy < 0 ) ||( acteur.y + acteur.ty > SCREEN_H && acteur.dy > 0) ){
        acteur.dy = -acteur.dy;}


    // calculer nouvelle position
    // nouvelle position = position actuelle + deplacement
    acteur.x = acteur.x + acteur.dx;
    acteur.y = acteur.y + acteur.dy;
    //  printf("dx: %d  dy: %d", acteur.dx, acteur.dy);
    return(acteur);
}

/*
// Gérer l'évolution de l'ensemble des acteurs
void actualiserTabActeurs(t_acteur * tab[NBALLONS]) {
    int i, j, cote;

    // Contrôle des collisions : si on entre en collision avec un autre
    // et que la collision tend à nous rapprocher alors on rebondit
    /*for (i=0;i<NBALLONS;i++)
        for (j=i+1;j<NBALLONS;j++)
            if ( (cote=collisionActeurs(tab[i], tab[j]) ) )
            {
                if ((cote==1 && tab[i]->dx<0) || (cote==2 && tab[i]->dx>0))
                    tab[i]->dx=-tab[i]->dx;
                if ((cote==3 && tab[i]->dy<0) || (cote==4 && tab[i]->dy>0))
                    tab[i]->dy=-tab[i]->dy;
                if ((cote==1 && tab[j]->dx>0) || (cote==2 && tab[j]->dx<0))
                    tab[j]->dx=-tab[j]->dx;
                if ((cote==3 && tab[j]->dy>0) || (cote==4 && tab[j]->dy<0))
                    tab[j]->dy=-tab[j]->dy;
            }

    // Gérer les déplacements habituels...
    for (i = 0; i < NBALLONS; i++) {
        actualiserActeur(tab[i]);
    }
}*/
// Dessiner un acteur sur une bitmap bmp
void dessinerActeur(BITMAP *page,BITMAP *sprite, t_acteur acteur)
{
    // fonction qui dessine les sprites (*fond, *sprite, coord x, y)
    draw_sprite(page, sprite, acteur.x, acteur.y);
    //printf("x: %d y: %d\n", acteur.x, acteur.y);
}

/*
// Dessiner sur une bitmap l'ensemble des acteurs
void dessinerTabActeurs(BITMAP *page,BITMAP *sprite,t_acteur * tab[NBALLONS])
{
    int i;

    for (i=0;i<NBALLONS;i++)
        dessinerActeur(page,sprite,tab[i]);

}
*/
// Gérer le clic de la souris sur un ballon
void tirSouris(t_acteur acteur, BITMAP *sprite) {
    int score=0;
    if (mouse_b == 1) {
        if ((mouse_x >= acteur.x && mouse_x <= acteur.x + acteur.tx) &&
            (mouse_y >= acteur.y && mouse_y <= acteur.y + acteur.ty)) {
            int stop;
            stop = clock();
            printf("Touche temps = %d\n", stop);
            clear_to_color(sprite, makecol(255, 0, 255));
            acteur.vivant = 1;
            score=1;
            printf("Score = %d\n", score);
            textprintf_ex(screen, font, 100, 10, makecol(255,0,200), -1, "SCORE=%d", score);

        }
    }
}

void tirballons()
{
    t_acteur mesActeurs;
    mesActeurs=creerActeur();
    BITMAP *page; // double buffer
    BITMAP *decor; // image de fond
    BITMAP *sprite; // image de l'acteur
    page= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    decor=load_bitmap("images/fondkirby.bmp",NULL);
    sprite=load_bitmap("images/Ballon55.bmp",NULL);

    while (!key[KEY_ESC]){
        // effacer buffer en apliquant decor
        blit(decor,page,0,0,0,0, SCREEN_W,SCREEN_H);
        mesActeurs= actualiserActeur(mesActeurs);
        dessinerActeur(page,sprite, mesActeurs);
        tirSouris(mesActeurs, sprite);
        blit(page, screen, 0,0,0,0, SCREEN_W, SCREEN_H);//A mettre tout à la fin du while

    }

}