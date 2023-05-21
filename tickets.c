#include "tickets.h"
/*
void tickets(){

    // CREATION BITMAP CLAVIER VIRTUEL (DONC PAS REEL !)
    BITMAP* clavier = create_bitmap(CLAVIER_WIDTH, CLAVIER_HEIGHT);
    clear_to_color(clavier, makecol(255, 255, 255));
    for (int i = 0; i < 26; i++) {
        int x = X_MARGE + i%14 * TOUCHE_WIDTH;
        int y = Y_MARGE + i/14 * TOUCHE_HEIGHT;
        rect(clavier, x, y, x + TOUCHE_WIDTH - 1, y + TOUCHE_HEIGHT - 1, makecol(0, 0, 0));
        char c = 'A' + i;
        textprintf_centre_ex(clavier, font, x + TOUCHE_WIDTH/2, y + TOUCHE_HEIGHT/2, makecol(0, 0, 0), -1, "%c", c);
    }
    int x_del = X_MARGE + 12*TOUCHE_WIDTH;
    int y_del = Y_MARGE + 3*TOUCHE_HEIGHT;
    rect(clavier, x_del, y_del, x_del + TOUCHE_WIDTH - 1, y_del + TOUCHE_HEIGHT - 1, makecol(0, 0, 0));
    textprintf_centre_ex(clavier, font, x_del + TOUCHE_WIDTH/2, y_del + TOUCHE_HEIGHT/2, makecol(0, 0, 0), -1, "Del");
    int x_enter = X_MARGE + 13*TOUCHE_WIDTH;
    int y_enter = Y_MARGE + 3*TOUCHE_HEIGHT;
    rect(clavier, x_enter, y_enter, x_enter + TOUCHE_WIDTH - 1, y_enter + TOUCHE_HEIGHT - 1, makecol(0, 0, 0));
    textprintf_centre_ex(clavier, font, x_enter + TOUCHE_WIDTH/2, y_enter + TOUCHE_HEIGHT/2, makecol(0, 0, 0), -1, "Entree");

    // affichage du clavier virtuel
    blit(clavier, screen, 0, 0, (SCREEN_WIDTH-CLAVIER_WIDTH)/2, (SCREEN_HEIGHT-CLAVIER_HEIGHT)/2, CLAVIER_WIDTH, CLAVIER_HEIGHT);

    // boucle principale
    char nom_SIUU[20] = "";
    int index = 0;
    while (!key[KEY_ESC]) {
        // ON RECUPERE LA POSITION DE LA SOURIS HOP HOP HOP
        int mouse_x = mouse_x - (SCREEN_WIDTH-CLAVIER_WIDTH)/2;
        int mouse_y = mouse_y - (SCREEN_HEIGHT-CLAVIER_HEIGHT)/2;

        // vÃ©rification si la souris est sur le clavier virtuel
        if (mouse_x >= X_MARGE && mouse_x < X_MARGE + 14*TOUCHE_WIDTH &&
            mouse_y >= Y_MARGE && mouse_y < Y_MARGE + 4*TOUCHE_HEIGHT) {
// CAULCUL INDICE SUR LAQUELLE LA SOURIS EST POSITIONNEE
            int x = mouse_x - X_MARGE;
            int y = mouse_y - Y_MARGE;
            int i = y/TOUCHE_HEIGHT * 14 + x/TOUCHE_WIDTH;
// ON VERIFIE SI LA TOUCHE EST UNE LETTRE AAAHHH
            if (i >= 0 && i < 26) {
                char c = 'A' + i;
                nom_SIUU[index] = c;
                index++;
            }
            else if (i == 26*3 + 12) {
                if (index > 0) {
                    index--;
                    nom_SIUU[index] = '\0';
                }
            }
            else if (i == 26*3 + 13) {
                break;
            }
        }
        clear_to_color(screen, makecol(255, 255, 255));
        textprintf_centre_ex(screen, font, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, makecol(0, 0, 0), -1, "%s|", nom_SIUU);
        blit(clavier, screen, 0, 0, (SCREEN_WIDTH-CLAVIER_WIDTH)/2, (SCREEN_HEIGHT-CLAVIER_HEIGHT)/2, CLAVIER_WIDTH, CLAVIER_HEIGHT);
        rest(100);
    }
    // ON AFFICHE LE NOM DU RACISTE HEUU... DU BEAU GOSSE
    clear_to_color(screen, makecol(255, 255, 255));
    textprintf_centre_ex(screen, font, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, makecol(0, 0, 0), -1, "%s", nom_SIUU);
    rest(2000);


    destroy_bitmap(clavier);
    allegro_exit();
}*/
