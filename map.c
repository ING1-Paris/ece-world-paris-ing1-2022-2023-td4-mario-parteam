//
// Created by Scotch on 27/04/2023.
//

//sources : https://fercoq.bitbucket.io/allegro/Alleg_C4/3_1_scrolling_sur_un_decor.html
#include "map.h"



void map() {
    BITMAP *map;
    BITMAP *player[4][PLAYER_ANIM_COUNT];
    BITMAP *buffer;
    BITMAP *detect;

    int map_x = PLAYER_START_X * ZOOM_FACTOR;
    int map_y = PLAYER_START_Y * ZOOM_FACTOR;
    int player_x = SCREEN_W / 3;
    int player_y = SCREEN_H / 3;

    int player_dir = 0; // 0 - down, 1 - up, 2 - right, 3 - left
    int player_frame = 0;
    int player_frame_counter = 0;
    int out=0;

    map = load_bitmap("images/LAMAP1.bmp", NULL);
    detect = load_bitmap("images/COLLISION1.bmp", NULL);


    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    for (int i = 0; i < PLAYER_ANIM_COUNT; i++) {
        char path[40];
        sprintf(path, "images/red-front%d.bmp", i);
        player[0][i] = load_bitmap(path, NULL);

        sprintf(path, "images/red-back%d.bmp", i);
        player[1][i] = load_bitmap(path, NULL);

        sprintf(path, "images/red-side%d.bmp", i);
        player[2][i] = load_bitmap(path, NULL);
        player[3][i] = create_bitmap(PLAYER_W, PLAYER_H);
        clear_to_color(player[3][i], makecol(255, 0, 255));
        draw_sprite_h_flip(player[3][i], player[2][i], 0, 0);
    }

    while (!key[KEY_ESC]) {
        if (key[KEY_LEFT]) {
            player_dir = 2;
            if ((map_x > 0 && player_x == SCREEN_W / 3) || player_x > 0) {
                if (map_x > 0)
                    map_x -= 5 * ZOOM_FACTOR;
                else
                    player_x -= 5;
            }
        }
        if (key[KEY_RIGHT]) {
            player_dir = 3;
            if ((map_x + SCREEN_W < MAP_W * ZOOM_FACTOR && player_x == SCREEN_W / 3)|| player_x < SCREEN_W - PLAYER_W) {
                if (map_x + SCREEN_W < MAP_W * ZOOM_FACTOR)
                    map_x += 5 * ZOOM_FACTOR;
                else
                    player_x += 5;
            }
        }
        if (key[KEY_UP]) {
            player_dir = 1;
            if ((map_y > 0 && player_y == SCREEN_H / 3) || player_y > 0) {
                if (map_y > 0)
                    map_y -= 5 * ZOOM_FACTOR;
                else
                    player_y -= 5;
            }
        }
        if (key[KEY_DOWN]) {
            player_dir = 0;
            if ((map_y + SCREEN_H < MAP_H * ZOOM_FACTOR && player_y == SCREEN_H / 3) || player_y < SCREEN_H - PLAYER_H) {
                if (map_y + SCREEN_H < MAP_H * ZOOM_FACTOR)
                    map_y += 5 * ZOOM_FACTOR;
                else
                    player_y += 5;
            }
        }

        player_frame_counter++;
        if (player_frame_counter > 10) {
            player_frame_counter = 0;
            player_frame++;
            if (player_frame >= PLAYER_ANIM_COUNT)
                player_frame = 0;
        }

        // get color under player
        int color_under_player = getpixel(detect, (map_x + player_x) / ZOOM_FACTOR, (map_y + player_y) / ZOOM_FACTOR);
        if (color_under_player == makecol(64,6,45)) {
            tirballons();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        } else if (color_under_player == makecol(183,9,250)) {
            Taupe();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        } else if (color_under_player == makecol(250,239,0)) {
            lejeu();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        } else if (color_under_player == makecol(129,255,9)) {
            Gh();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        } else if (color_under_player == makecol(4,94,255)) {
            PPC();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        } else if (color_under_player == makecol(255,0,0)) {
            Bomberman();
            map_x = PLAYER_START_X * ZOOM_FACTOR;
            map_y = PLAYER_START_Y * ZOOM_FACTOR;
        }

        stretch_blit(map, buffer, map_x / ZOOM_FACTOR, map_y / ZOOM_FACTOR, SCREEN_W / ZOOM_FACTOR, SCREEN_H / ZOOM_FACTOR, 0, 0, SCREEN_W, SCREEN_H);
        draw_sprite(buffer, player[player_dir][player_frame], player_x, player_y);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        printf("\n%d",out);

        rest(10);
    }

    for (int i = 0; i < PLAYER_ANIM_COUNT; i++) {
        destroy_bitmap(player[0][i]);
        destroy_bitmap(player[1][i]);
        destroy_bitmap(player[2][i]);
        destroy_bitmap(player[3][i]);
    }

    destroy_bitmap(map);
    destroy_bitmap(buffer);

}
