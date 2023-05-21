//
// Created by Laure on 21/05/2023.
//

#include <stdio.h>
#include <time.h>
#include <allegro.h>
#ifndef TIRAUXBALLONS_TIRAUXBALLONS_H
#define TIRAUXBALLONS_TIRAUXBALLONS_H
#define NBALLONS 5

// données personnelles de chaque acteur qui se déplace
typedef struct acteur
{
    int x, y;          // coordonnée (du coin sup. gauche)
    int dx, dy;        // vecteur deplacement
    int tx,ty;         // tailles : horizontale/verticale
    int vivant;  // comportement : 0 vivant / 1 touche
    int type;          // numero correspondant à la couleur du ballon

} t_acteur;

t_acteur creerActeur ();

// Remplir un tableau avec des ballons
void remplirTabActeurs(t_acteur * tab[NBALLONS]);

// Actualiser un ballon (bouger ...)
t_acteur actualiserActeur(t_acteur acteur);

// Gérer l'évolution de l'ensemble des ballons
void actualiserTabActeurs(t_acteur * tab[NBALLONS]);

// Dessiner un ballon sur une bitmap bmp
void dessinerActeur(BITMAP *page,BITMAP *sprite, t_acteur acteur);

// Dessiner l'ensemble des ballons sur une bitmap bmp
void dessinerTabActeurs(BITMAP *page,BITMAP *sprite,t_acteur * tab[NBALLONS]);

// Gérer le clic de la souris
void tirSouris(t_acteur acteur, BITMAP *sprite);

void tirballons();


#endif //TIRAUXBALLONS_TIRAUXBALLONS_H
