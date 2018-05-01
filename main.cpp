
#include "headers.hpp"

#define ROWS 20

#define COLS 17

using namespace std;

int main(const int argc, const char *argv[])
{
	srand (time(NULL));

	char map[ROWS][COLS] = {
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
		"WFWWWFW  WFWWWFW",
		"WFFFWFWWWWFWFFFW",
		"WFFFFFFFFFFFFFFW",
		"WFFFWWWWWWWWFFFW",
		"WFWFFFFFFFFFFWFW",
		"WFWWWWWFFWWWWWFW",
		"WFFFFFFFFFFFFFFW",
		"WWWWWWWWWWWWWWWW"};

	// Modules

	if (!al_init())
		fail("Failed to load Allegro 5");

	// Add-ons

	al_init_image_addon();

	al_init_acodec_addon();

	al_init_primitives_addon();

	al_init_font_addon();

	al_init_ttf_addon();

	al_install_keyboard();

	al_install_audio();

	// Window

	ALLEGRO_DISPLAY *display = nullptr;

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	al_set_new_window_position(410, 50);

	display = al_create_display(480, 630);

	if (!display)
		fail("Failed to initialize Display");

	al_set_window_title(display, "Pac Man");

	ALLEGRO_BITMAP *icon = al_load_bitmap("images/pacman_logo.png");

	al_set_display_icon(display, icon);

	// Audio

	al_reserve_samples(2);

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

	al_play_sample(theme, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, nullptr);

	// Background

	ALLEGRO_BITMAP *back = al_load_bitmap("images/pacman_pattern.png");

	al_draw_bitmap(back, 0, 0, 0);

	// Food

	Food f[166];

	int counter_food = 0;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (map[row][col] == 'F')
			{
				if (row > 9)
					f[counter_food].setImg("images/pacman_food_blue.png");

				f[counter_food].set(col, row);

				f[counter_food++].draw();
			}
		}
	}

	// Event

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 4); // Framerate

	if (!event_queue)
		fail("Failed to create Event Queue");

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Status

	ALLEGRO_BITMAP *logo_bottom = al_load_bitmap("images/pacman_logo_bottom.png");

	Btn points_btn, life_btn;

	points_btn.setIcon("images/pacman_cherry.png");

	life_btn.setIcon("images/pacman_life.png");

	life_btn.setX(421.0);

	life_btn.setIconX(443.0);

	// Game Loop

	Enemy enemy;

	enemy.setCharacterCol(1);

	enemy.setCharacterLine(1);

	// enemy.setDirection(1);
	
	Pac pac;

	int direction = 0, intention = 0, points = 0, life = 3;

	bool redraw = false, mute = false;

	al_start_timer(timer);

	while (true)
	{
		ALLEGRO_EVENT event;

		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;

		else if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;
			else if (event.keyboard.keycode == ALLEGRO_KEY_O)
			{
				mute = true;
				
				al_stop_samples();
			}
		}

		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
			case ALLEGRO_KEY_S:
				intention = 3;
				break;

			case ALLEGRO_KEY_UP:
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

		else if (event.type == ALLEGRO_EVENT_TIMER)
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

			for (int counter = 0; counter < counter_food; counter++)
			{
				if (pac.getCharacterLine() == f[counter].getY() && pac.getCharacterCol() == f[counter].getX())
				{
					if (!mute)
						al_play_sample(eat_fruit, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);

					f[counter].set(-1, -1);

					points++;

					continue;
				}

				f[counter].draw();
			}
						
			pac.move(direction, map);

			pac.draw();

			points_btn.setStr(to_string(points).c_str());

			points_btn.showStr().showIcon();

			life_btn.setStr(to_string(life).c_str());

			life_btn.showStr().showIcon();

			al_draw_bitmap(logo_bottom, 185.0, 597.0, 0);

			al_flip_display();
		}		
	}

	al_destroy_bitmap(logo_bottom);

	al_destroy_timer(timer);

	al_destroy_event_queue(event_queue);

	al_destroy_sample_instance(instance_eat_fruit);

	al_destroy_sample_instance(instance_theme);

	al_destroy_sample(eat_fruit);

	al_destroy_sample(theme);

	al_destroy_bitmap(back);

	al_destroy_bitmap(icon);

	al_destroy_display(display);

	return 0;
}