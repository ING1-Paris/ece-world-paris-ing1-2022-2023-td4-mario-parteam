#include "PPC.h"

void regles(){
    textprintf_centre_ex(screen, font, SCREEN_W / 2, 50, makecol(255, 255, 255), -1, "HAHAHA VOUS AVEZ VRAIMENT BESOIN DE REGLES POUR JOUER AU PIERRE FEUILLE CISEAU ?");
}



void jouer(BITMAP *jeu, BITMAP *buffer, int player_choice,int computer_choice, BITMAP *rock_me, BITMAP *rock_enemy, BITMAP *paper_me, BITMAP *paper_enemy, BITMAP *scissors_me, BITMAP *scissors_enemy, BITMAP *perdu1,BITMAP *perdu2, int nombre_win, BITMAP *game_over, bool choix_valide, bool choix_valide_bot, int bouton_x, int play_bouton_y, int bouton_width, int bouton_height) {
    blit(jeu, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    stretch_sprite(buffer,perdu1, 400, 300, 200,400);
    textout_ex(buffer, font, "Entrez votre choix (0 pour pierre, 1 pour papier, 2 pour ciseaux):", 50, 100,makecol(0, 0, 0), -1);
    textout_ex(buffer, font, "C'est toi mon adversaire", 620, 300,makecol(0, 0, 0), -1);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    while(!choix_valide){
        if (key[KEY_0]) {
            player_choice = ROCK;
            draw_sprite(buffer, rock_me, 750, 550);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide= true;
        } else if (key[KEY_1]) {
            player_choice = PAPER;
            draw_sprite(buffer, paper_me, 750, 550);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide= true;
        } else if (key[KEY_2]) {
            player_choice = SCISSORS;
            draw_sprite(buffer, scissors_me, 750, 550);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide= true;
        }


    }



    rest(2000);
    computer_choice = rand() % 3;
    while(!choix_valide_bot){
        if (computer_choice == ROCK) {
            draw_sprite(buffer, rock_enemy, SCREEN_WIDTH- 1170, 150);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide_bot= true;
        } else if (computer_choice == PAPER) {
            draw_sprite(buffer, paper_enemy, SCREEN_WIDTH- 1170, 150);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide_bot= true;
        } else if (computer_choice == SCISSORS) {
            draw_sprite(buffer, scissors_enemy, SCREEN_WIDTH- 1170, 150);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            choix_valide_bot= true;
        }


        rest(2000);
        while (!key[KEY_ESC]){
            if (player_choice == computer_choice) {
                blit(game_over, game_over, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                stretch_sprite(game_over,perdu2, 750, 400, 100,200);
                textout_ex(game_over, font, "Egalité, tu as de la chance...", 50, 100, makecol(0, 0, 0),-1);
                //blit(game_over, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            } else if ((player_choice == ROCK && computer_choice == SCISSORS) ||
                       (player_choice == PAPER && computer_choice == ROCK) ||
                       (player_choice == SCISSORS && computer_choice == PAPER)) {
                nombre_win++;
                blit(game_over, game_over, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                stretch_sprite(game_over,perdu2, 750, 400, 100,200);
                textout_ex(game_over, font, "Je n'y crois pas tu as gagné", 50, 100, makecol(0, 0, 0),-1);
                //blit(game_over, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            } else {


                blit(game_over, game_over, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                stretch_sprite(game_over,perdu2, 750, 400, 100,200);
                textout_ex(game_over, font, "Facile !", 50, 100, makecol(0, 0, 0), -1);
                //blit(game_over, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

            }
            rectfill(game_over, bouton_x, 700, bouton_x + bouton_width, 700 + bouton_height, makecol(255, 255, 255));
            textprintf_centre_ex(game_over, font, bouton_x + bouton_width / 2, 725, makecol(0, 0, 0), -1, "Re-jouer");
            if (mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=700 && mouse_y<= 700 + bouton_height){
                //l'utilisateur a appuyé sur le bouton jouer
                while(!key[KEY_ESC]){
                    jouer(jeu, buffer, player_choice, computer_choice, rock_me, rock_enemy, paper_me,
                          paper_enemy, scissors_me, scissors_enemy, perdu1, perdu2, nombre_win, game_over, choix_valide, choix_valide_bot, bouton_x,play_bouton_y,bouton_width, bouton_height);
                }


            }
            blit(game_over, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        }

    }
}



void PPC(){
    BITMAP *game_over;
    BITMAP *buffer;
    BITMAP *menu;
    BITMAP *rock_me;
    BITMAP *paper_me;
    BITMAP *scissors_me;
    BITMAP *rock_enemy;
    BITMAP *paper_enemy;
    BITMAP *scissors_enemy;
    BITMAP *jeu_background ;
    BITMAP *perdu1;
    BITMAP *perdu2;
    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires
    show_mouse(screen);


    int player_choice=3;
    int computer_choice=3;
    int nombre_win=0;
    int bouton_width = 200;
    int bouton_height = 50;
    int bouton_x = (SCREEN_W - bouton_width) / 2;
    int play_bouton_y = 150;
    int regles_bouton_y = 225;
    int quit_bouton_y = 300;
    bool choix_valide=false;
    bool choix_valide_bot=false;



    buffer= create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
    clear_bitmap(buffer);
    game_over= load_bitmap("images/Ecran_perdu.bmp",NULL);
    menu= load_bitmap("images/menu.bmp", NULL);
    rock_me = load_bitmap("images/pierre_moi.bmp", NULL);
    paper_me= load_bitmap("images/feuille_moi2.bmp", NULL);
    scissors_me= load_bitmap("images/ciseaux_moi2.bmp", NULL);
    rock_enemy= load_bitmap("images/pierre_ennemie.bmp", NULL);
    paper_enemy= load_bitmap("images/feuille_ennemie2.bmp", NULL);
    scissors_enemy= load_bitmap("images/ciseaux_ennemie2.bmp", NULL);
    jeu_background= load_bitmap("images/jeu2.bmp", NULL);
    perdu1 = load_bitmap("images/mechant_base2.bmp", NULL);
    perdu2= load_bitmap("images/mechant_perdu2.bmp", NULL);
    while(!key[KEY_ESC]) {
        blit(menu, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        rectfill(buffer, bouton_x, play_bouton_y, bouton_x + bouton_width, play_bouton_y + bouton_height, makecol(255, 255, 255));
        rectfill(buffer, bouton_x, regles_bouton_y, bouton_x + bouton_width, regles_bouton_y + bouton_height, makecol(255, 255, 255));
        rectfill(buffer, bouton_x, quit_bouton_y, bouton_x + bouton_width, quit_bouton_y + bouton_height, makecol(255, 255, 255));
        textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, play_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Jouer");
        textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, regles_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Regles");
        textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, quit_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Quitter");

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        if (mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=play_bouton_y && mouse_y<= play_bouton_y + bouton_height){
            //l'utilisateur a appuyé sur le bouton jouer
            while(!key[KEY_SPACE]) {
                jouer(jeu_background, buffer, player_choice, computer_choice, rock_me, rock_enemy, paper_me,
                      paper_enemy, scissors_me, scissors_enemy, perdu1, perdu2, nombre_win, game_over, choix_valide, choix_valide_bot, bouton_x,play_bouton_y,bouton_width, bouton_height);
            }
        }
        if(mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=regles_bouton_y && mouse_y<= regles_bouton_y + bouton_height) {
            //l'utilisateur a appuyé sur le bouton règle
            while (!key[KEY_ENTER]) {
                regles();
            }
        }
        else if(mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=quit_bouton_y && mouse_y<= quit_bouton_y + bouton_height){
            allegro_exit();
        }
    }
    destroy_bitmap(buffer);
    destroy_bitmap(game_over);
    destroy_bitmap(menu);
    destroy_bitmap(rock_me);
    destroy_bitmap(rock_enemy);
    destroy_bitmap(paper_me);
    destroy_bitmap(paper_enemy);
    destroy_bitmap(scissors_me);
    destroy_bitmap(scissors_enemy);
    destroy_bitmap(perdu1);
    destroy_bitmap(perdu2);
    destroy_bitmap(jeu_background);
}