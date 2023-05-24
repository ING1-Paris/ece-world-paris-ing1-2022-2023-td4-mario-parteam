#include "main.h"

int main() {
    allegroinit();
    //map();
    Bomberman();
    return 0;
}
END_OF_MAIN()

void allegroinit(){
    allegro_init();
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,1920,1080,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);

    }
}
