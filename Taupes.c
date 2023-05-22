#include "Taupes.h"


void regles_taupes(BITMAP* regles_background){
    // Affichage du texte des règles
    textprintf_centre_ex(regles_background, font, 1920 / 2, 1080/2 -50, makecol(255, 255, 255), -1, "Règles du jeu");
    textprintf_centre_ex(regles_background, font, 1920 / 2, 1080/2, makecol(255, 255, 255), -1, "Des Gumbas volants apparaissent aléatoirement des nuages.");
    textprintf_centre_ex(regles_background, font, 1920 / 2, 1080/2 +50, makecol(255, 255, 255), -1, "Clique sur ces derniers pour gagner des points et être le premier !");
    textprintf_centre_ex(regles_background, font, 1920 / 2, 1080/2 +100, makecol(255, 255, 255), -1, "Rapidité et coordination requises !");

    // Affichage de l'image de fond
    blit(regles_background, screen, 0, 0, 0,0, SCREEN_W,SCREEN_H);

}

BITMAP *load_bitmap_check(char *nomImage){
    BITMAP *bmp;
    bmp=load_bitmap(nomImage,NULL);
    if (!bmp)
    {
        allegro_message("pas pu trouver %s",nomImage);
        exit(EXIT_FAILURE);
    }
    return bmp;
}
void game_jouer(BITMAP *jeu_background, BITMAP* taupes, BITMAP *buffer, int *taupe_visible, int *taupe_timer, int *score, int taupe_width, int taupe_height, int taupe_delay, int valeurs[], int division, int *taupe_x, int *taupe_y, int taupe_rester, int elapsed_time) {

    blit(jeu_background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    clock_t start_time = clock();
    while (*taupe_visible == 1) {
        blit(jeu_background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        stretch_sprite(buffer, taupes, *taupe_x, *taupe_y, 90, 90);
        textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255), -1, "Score: %d", *score);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (mouse_b & 1 && mouse_x >= *taupe_x && mouse_x <= *taupe_x + taupe_width && mouse_y >= *taupe_y &&
            mouse_y <= *taupe_y + taupe_height) {
            clear_bitmap(buffer);
            *taupe_visible = 0;
            *score+= 1;
            blit(jeu_background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            break;
        }
        elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC;
        if (elapsed_time >= 2) {
            *taupe_visible = 0;
            clear(buffer);
            blit(jeu_background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            break;
        }
    }

    while (*taupe_visible == 0) {
        rest(2000);
        *taupe_x = (rand() % 6) * division;
        *taupe_y = valeurs[rand() % 3];
        *taupe_visible = 1;
        *taupe_timer = 0;  // Réinitialise le compteur lorsque la taupe réapparaît

    }
}



void Taupe(){
    show_mouse(screen);
    install_keyboard();


    int my = mouse_y;


    BITMAP* menu_background;
    BITMAP* regles_background;
    BITMAP* jeu_background;
    BITMAP* taupes;
    BITMAP* buffer;
    // Chargement de l'image de fond
    menu_background = load_bitmap("images/menu6.bmp", NULL);
    regles_background = load_bitmap("images/regles.bmp", NULL);
    jeu_background = load_bitmap("images/jeu3.bmp", NULL);
    taupes = load_bitmap("images/taupes.bmp", NULL);
    buffer=  create_bitmap(SCREEN_W, SCREEN_H);

    int score = 0;
    srand(time(NULL));
    int taupe_visible = 1;
    int taupe_timer = 0;
    int taupe_delay= 1000;
    int taupe_width = 70;
    int taupe_height = 70;
    int valeurs[] = {822, 920, 720};
    int division = SCREEN_W / 6;
    // Création des rectangles pour les boutons
    int bouton_width = 200;
    int bouton_height = 50;
    int bouton_x = (1526 - bouton_width) / 2;
    int play_bouton_y = 150;
    int regles_bouton_y = 225;
    int quit_bouton_y = 300;
    int taupe_x;
    int taupe_y;
    int taupe_rester;
    int compteur;
    taupe_x = (rand() % 6) * division;
    int taupe_x_main =(rand() % 6) * division;
    int taupe_y_main = valeurs[rand() % 3];
    taupe_y = valeurs[rand() % 3];
    clock_t start_time = clock();
    int elapsed_time = 0;

    blit(menu_background, buffer, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    rectfill(buffer, bouton_x, play_bouton_y, bouton_x + bouton_width, play_bouton_y + bouton_height, makecol(255, 255, 255));
    rectfill(buffer, bouton_x, regles_bouton_y, bouton_x + bouton_width, regles_bouton_y + bouton_height, makecol(255, 255, 255));
    rectfill(buffer, bouton_x, quit_bouton_y, bouton_x + bouton_width, quit_bouton_y + bouton_height, makecol(255, 255, 255));
    textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, play_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Jouer");
    textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, regles_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Regles");
    textprintf_centre_ex(buffer, font, bouton_x + bouton_width / 2, quit_bouton_y + bouton_height / 2, makecol(0, 0, 0), -1, "Quitter");

    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    show_mouse(screen);


    // Attente de l'appui sur un bouton
    while(!key[KEY_ESC])
    {
        elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC;
        if (elapsed_time >= 60) {
            break;
        }


        // Vérification si une minute s'est écoulée
        if (elapsed_time >= 60) {
            break;
        }
        if (mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=play_bouton_y && mouse_y<= play_bouton_y + bouton_height)
        {
            while(!key[KEY_ESC]){
                // L'utilisateur a cliqué sur le bouton "Jouer"
                taupe_y = taupe_y_main;
                taupe_x = taupe_x_main;
                elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC;
                if (elapsed_time >= 60) {
                    break;}

                game_jouer(jeu_background, taupes, buffer, &taupe_visible, &taupe_timer, &score,  taupe_width, taupe_height, taupe_delay, valeurs, division, &taupe_x_main,&taupe_y_main, taupe_rester ,elapsed_time);
                clear_bitmap(buffer);
                textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255), -1, "Score: %d", score);
                show_mouse(buffer);

                blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                show_mouse(screen);

            }
        }
        else if (mouse_b && mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_width && mouse_y>=regles_bouton_y && mouse_y<= regles_bouton_y + bouton_height)
        {
            // L'utilisateur a cliqué sur le bouton "Règles"
            while(!key[KEY_ENTER]){
                regles_taupes(regles_background);
            }



        }
        else if (my >= quit_bouton_y && my <= quit_bouton_y + bouton_height)
        {
            // L'utilisateur a cliqué sur le bouton "Quitter"
            allegro_exit();
        }
    }


    destroy_bitmap(menu_background);
    destroy_bitmap(jeu_background);
    destroy_bitmap(regles_background);

    allegro_exit();
}