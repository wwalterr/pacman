
#include "headers.hpp"

using namespace std;

int main(const int argc, const char *argv[])
{

    char map[20][17] = {
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

    if (!al_init())
        fail("Failed to load Allegro 5");

    al_init_image_addon();

    al_init_primitives_addon();

    al_install_keyboard();

    al_install_audio();

    al_init_acodec_addon();

    // Window

    ALLEGRO_DISPLAY *display = nullptr;

    ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman_logo.png");

    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    al_set_new_window_position(410, 80);

    display = al_create_display(480, 600);

    if (!display)
        fail("Failed to initialize Display");

    al_set_window_title(display, "Pac Man");

    al_set_display_icon(display, icon);

    // Audio

    al_reserve_samples(1);

    ALLEGRO_SAMPLE_ID sp_id;

    ALLEGRO_SAMPLE *sample = nullptr;

    ALLEGRO_SAMPLE_INSTANCE *instance = nullptr;

    sample = al_load_sample("audios/pacman_theme.wav");

    instance = al_create_sample_instance(sample);

    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

    // Map

    Wall w[154];

    Food f[166];

    int counter_w = 0, counter_f = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            if (map[row][col] == 'W')
            {
                w[counter_w].set(col, row);

                w[counter_w++].draw();
            }

            if (map[row][col] == 'F')
            {
                if (row > 9)
                    f[counter_f].setImg("images/pacman_food_blue.png");

                f[counter_f].set(col, row);

                f[counter_f++].draw();
            }
        }
    }

    // Event

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (!event_queue)
        fail("Failed to create Event Queue");

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_display_event_source(display));

    // Game Loop

    int pacman_line = 12, pacman_col = 7, direction = 0;

    bool clear = false;

    Pac pac;

    pac.draw();

    al_flip_display();

    while (true)
    {
        ALLEGRO_EVENT events;

        al_wait_for_event(event_queue, &events);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

        if (events.type == ALLEGRO_EVENT_KEY_UP)
        {
            if (events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                break;
            else if (events.keyboard.keycode == ALLEGRO_KEY_P)
                al_play_sample(sample, 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &sp_id); // Play
            else if (events.keyboard.keycode == ALLEGRO_KEY_O)
                al_stop_sample(&sp_id); // One-stop
        }

        if (events.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            clear = true;

            switch (events.keyboard.keycode)
            {
            case ALLEGRO_KEY_S:
                pacman_line += 1;
                direction = 3;
                break;

            case ALLEGRO_KEY_W:
                pacman_line -= 1;
                direction = 2;
                break;

            case ALLEGRO_KEY_RIGHT:
            case ALLEGRO_KEY_D:
                pacman_col += 1;
                direction = 1;
                break;

            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
                pacman_col -= 1;
                direction = 0;
                break;

            default:
                continue;
            }
        }

        if (clear)
        {
            clear = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));

            for (int counter = 0; counter < counter_w; counter++)
                w[counter].draw();

            for (int counter = 0; counter < counter_f; counter++)
            {
                if (pac.getPacmanLine() == f[counter].getY() && pac.getPacmanCol() == f[counter].getX())
                {
                    f[counter].set(-1, -1);

                    continue;
                }

                f[counter].draw();
            }

            pac.set(pacman_col, pacman_line, direction);

            pac.draw();
        }

        al_flip_display();
    }

    al_destroy_event_queue(event_queue);

    al_destroy_sample_instance(instance);

    al_destroy_sample(sample);

    al_destroy_bitmap(icon);

    al_destroy_display(display);

    return 0;
}