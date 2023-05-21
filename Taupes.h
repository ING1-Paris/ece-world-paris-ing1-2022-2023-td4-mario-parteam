//
// Created by thibp on 15/05/2023.
//

#ifndef MARIO_PARTEAM_V1_TAUPES_H
#define MARIO_PARTEAM_V1_TAUPES_H
#include "generalfunctions.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define TAUPE_WIDTH 60
#define TAUPE_HEIGHT 60
#define NUM_TROUS 6
void regles_taupes(BITMAP* regles_background);
void game_jouer(BITMAP *jeu_background, BITMAP* taupes, BITMAP *buffer, int *taupe_visible, int *taupe_timer, int *score, int taupe_width, int taupe_height, int taupe_delay, int valeurs[], int division, int *taupe_x, int *taupe_y, int taupe_rester, int elapsed_time);
void Taupe();

#endif //MARIO_PARTEAM_V1_TAUPES_H
