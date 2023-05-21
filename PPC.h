//
// Created by thibp on 21/05/2023.
//

#ifndef MARIO_PARTEAM_V1_PPC_H
#define MARIO_PARTEAM_V1_PPC_H
#include "generalfunctions.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
void regles();
void jouer(BITMAP *jeu, BITMAP *buffer, int player_choice,int computer_choice, BITMAP *rock_me, BITMAP *rock_enemy, BITMAP *paper_me, BITMAP *paper_enemy, BITMAP *scissors_me, BITMAP *scissors_enemy, BITMAP *perdu1,BITMAP *perdu2, int nombre_win, BITMAP *game_over, bool choix_valide, bool choix_valide_bot, int bouton_x, int play_bouton_y, int bouton_width, int bouton_height, BITMAP *Thibaut, BITMAP *perdu3);
void PPC();
#endif //MARIO_PARTEAM_V1_PPC_H
