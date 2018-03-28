
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_primitives.h>

#include "classes/extras.hpp"

#include "classes/wall.hpp"

#include "classes/food.hpp"

using namespace std;

char const map[20][17] = {
    "WWWWWWWWWWWWWWWW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WFWWWWWWWWWWWWFW",
    "WFFFFFFWWFFFFFFW",
    "WFFFWFFWWFFWFFFW",
    "WFWWWFFFFFFWWWFW",
    "WFWFFFWWWWFFFWFW",
    "WFFFWFFFFFFWFFFW",
    "WFWWWFWFFWFWWWFW",
    "WFFFWFWWWWFWFFFW",
    "WFFFFFFFFFFFFFFW",
    "WFFFWWWWWWWWFFFW",
    "WFWFFFFFFFFFFWFW",
    "WFWWWWWFFWWWWWFW",
    "WFFFFFFFFFFFFFFW",
    "WWWWWWWWWWWWWWWW"};

int main(const int argc, const char *argv[])
{

    if (!al_init())
        fail("Failed to load Allegro 5");

    // Addons :

    al_init_image_addon();

    al_init_primitives_addon();

    al_install_keyboard();

    ALLEGRO_DISPLAY *display = nullptr;

    ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman.png");

    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    al_set_new_window_position(410, 80); // X - Y

    display = al_create_display(480, 600); // X - Y

    if (!display)
        fail("Failed to initialize Display");

    al_set_window_title(display, "Pac Man");

    al_set_display_icon(display, icon);

    Wall w[154];

    Food f[166];

    int c_wall = 0, c_food = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            if (map[row][col] == 'W')
            {
                w[c_wall].set(col * 30, row * 30);

                w[c_wall].draw();

                c_wall++;
            }

            if (map[row][col] == 'F')
            {
                f[c_food].set(col * 30, row * 30);

                f[c_food].draw();

                c_food++;
            }
        }
    }

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_display_event_source(display));

    ALLEGRO_BITMAP *pac = al_load_bitmap("images/pac.png");

    int direction = 0, xPacman = 210, yPacman = 360;

    al_draw_bitmap_region(pac, 30, 0, 30, 30, xPacman, yPacman, 0);

    al_flip_display();

    bool cl = false;

    while (true)
    {
        ALLEGRO_EVENT events;

        al_wait_for_event(event_queue, &events);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            cout << "\n"
                 << al_get_app_name() << " \033[31mclosed\033[37m !\n\n";

            break;
        }

        if (events.type == ALLEGRO_EVENT_KEY_DOWN)
        {

            cl = true;

            switch (events.keyboard.keycode)
            {
            case ALLEGRO_KEY_S:
                yPacman += 30;
                direction = 3;
                break;

            case ALLEGRO_KEY_W:
                yPacman -= 30;
                direction = 2;
                break;

            case ALLEGRO_KEY_RIGHT:
            case ALLEGRO_KEY_D:
                xPacman += 30;
                direction = 1;
                break;

            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
                xPacman -= 30;
                direction = 0;
                break;

            default:
                cout << "\nPress the appropriate \033[31mshortcut\033[37m\n\n";
            }
        }

        if (cl)
        {

            cl = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));

            for (int col = 0; col < c_wall; col++)
                w[col].draw();

            for (int line = 0; line < c_food; line++)
                f[line].draw();

            al_draw_bitmap_region(pac, direction * 30, 0, 30, 30, xPacman, yPacman, 0);
            
        }
        al_flip_display();
    }

    al_destroy_event_queue(event_queue);

    al_destroy_bitmap(pac);

    al_destroy_bitmap(icon);

    al_destroy_display(display);

    return 0;
}