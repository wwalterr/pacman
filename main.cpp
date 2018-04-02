
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

    // Addon

    al_init_image_addon();

    al_init_primitives_addon();

    al_install_keyboard();

    al_install_audio();

    al_init_acodec_addon();

    // Window

    ALLEGRO_DISPLAY *display = nullptr;

    ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman.png");

    al_set_new_display_flags(ALLEGRO_RESIZABLE);

    al_set_new_window_position(410, 80);

    display = al_create_display(480, 600);

    if (!display)
        fail("Failed to initialize Display");

    al_set_window_title(display, "Pac Man");

    al_set_display_icon(display, icon);

    // Audio

    al_reserve_samples(1);

    ALLEGRO_SAMPLE *sample = nullptr;

    ALLEGRO_SAMPLE_INSTANCE *instance = nullptr;

    sample = al_load_sample("audios/bits.wav");

    instance = al_create_sample_instance(sample);

    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

    // Map

    Wall w[154];

    Food f[166];

    int c_wall = 0, c_food = 0;

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            if (map[row][col] == 'W')
            {
                w[c_wall].set(col, row);

                w[c_wall++].draw();
            }

            if (map[row][col] == 'F')
            {
                f[c_food].set(col, row);

                f[c_food++].draw();
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

    int l_pac = 12, c_pac = 7, direction = 0;

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
                al_play_sample(sample, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, nullptr);
        }

        if (events.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            clear = true;

            switch (events.keyboard.keycode)
            {
            case ALLEGRO_KEY_S:
                l_pac += 1;
                direction = 3;
                break;

            case ALLEGRO_KEY_W:
                l_pac -= 1;
                direction = 2;
                break;

            case ALLEGRO_KEY_RIGHT:
            case ALLEGRO_KEY_D:
                c_pac += 1;
                direction = 1;
                break;

            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
                c_pac -= 1;
                direction = 0;
                break;

            default:
                continue;
            }

            /* if (map[l_pac][c_pac] == 'F')
                cout << "\nFood \033[31m:\033[37m L " << l_pac << " C " << c_pac << "\n";
            else if (map[l_pac][c_pac] == 'W')
                cout << "\nWall \033[34m:\033[37m L " << l_pac << " C " << c_pac << "\n"; */
        }

        if (clear)
        {
            clear = false;
            
            al_clear_to_color(al_map_rgb(0, 0, 0));

            for (int counter = 0; counter < c_wall; counter++)
                w[counter].draw();

            for (int counter = 0; counter < c_food; counter++)
                f[counter].draw();

            pac.set(c_pac, l_pac, direction);

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