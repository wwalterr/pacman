
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

	al_init_acodec_addon();

	al_init_primitives_addon();

	al_install_keyboard();

	al_install_audio();

	// Window

	ALLEGRO_DISPLAY *display = nullptr;

	ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman_logo.png");

	al_set_new_display_flags(ALLEGRO_RESIZABLE);

	al_set_new_window_position(410, 50);

	display = al_create_display(480, 630);

	if (!display)
		fail("Failed to initialize Display");

	al_set_window_title(display, "Pac Man");

	al_set_display_icon(display, icon);

	// Audio

	al_reserve_samples(2);

	ALLEGRO_SAMPLE_ID sp_id;

	ALLEGRO_SAMPLE *theme = nullptr;

	ALLEGRO_SAMPLE *eat_fruit = nullptr;

	ALLEGRO_SAMPLE_INSTANCE *instance_theme = nullptr;

	ALLEGRO_SAMPLE_INSTANCE *instance_eat_fruit = nullptr;

	theme = al_load_sample("audios/pacman_theme.wav");

	eat_fruit = al_load_sample("audios/pacman_eat_fruit.wav");

	instance_theme = al_create_sample_instance(theme);

	instance_eat_fruit = al_create_sample_instance(eat_fruit);

	al_attach_sample_instance_to_mixer(instance_theme, al_get_default_mixer());

	al_attach_sample_instance_to_mixer(instance_eat_fruit, al_get_default_mixer());

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

	// Test

	ALLEGRO_BITMAP *back = al_load_bitmap("images/pacman_pattern.png");

	al_draw_bitmap(back, 0, 0, 0);

	// Event

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 5);

	if (!event_queue)
		fail("Failed to create Event Queue");

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Game Loop

	int direction = 1, points = 0, intention = 1;

	bool redraw = false;

	Pac pac;

	pac.draw();

	al_flip_display();

	al_start_timer(timer);

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
				al_play_sample(theme, 0.2, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &sp_id);
			else if (events.keyboard.keycode == ALLEGRO_KEY_O)
				al_stop_sample(&sp_id);
		}

		if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_S:
				intention = 3;
				break;

			case ALLEGRO_KEY_W:
				intention = 2;
				break;

			case ALLEGRO_KEY_RIGHT:
			case ALLEGRO_KEY_D:
				intention = 1;
				break;

			case ALLEGRO_KEY_LEFT:
			case ALLEGRO_KEY_A:
				intention = 0;
				break;
			}
		}

		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			if (intention == 0 && pac.moveLeft(map))
				direction = intention;
			else if (intention == 1 && pac.moveRight(map))
				direction = intention;
			else if (intention == 2 && pac.moveUp(map))
				direction = intention;
			else if (intention == 3 && pac.moveDown(map))
				direction = intention;
		}

		if (redraw)
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(back, 0, 0, 0);

			for (int counter = 0; counter < counter_w; counter++)
				w[counter].draw();

			for (int counter = 0; counter < counter_f; counter++)
			{
				if (pac.getPacmanLine() == f[counter].getY() && pac.getPacmanCol() == f[counter].getX())
				{
					al_play_sample(eat_fruit, 0.2, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);

					f[counter].set(-1, -1);

					points++;

					continue;
				}

				f[counter].draw();
			}

			pac.move(direction, map);

			pac.draw();

			al_flip_display();
		}
	}

	cout << "\nPac man was eaten \033[31m" << points << "\033[37m fruits\n\n";

	al_destroy_timer(timer);

	al_destroy_event_queue(event_queue);

	al_destroy_sample_instance(instance_theme);

	al_destroy_sample_instance(instance_eat_fruit);

	al_destroy_sample(theme);

	al_destroy_sample(eat_fruit);

	al_destroy_bitmap(icon);

	al_destroy_display(display);

	return 0;
}