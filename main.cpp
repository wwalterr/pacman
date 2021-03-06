#include "main.hpp"

#define ROWS 20

#define COLS 17

using namespace std;

int main(const int argc, const char *argv[])
{
	srand(time(NULL));

	char map[ROWS][COLS]{
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
	ALLEGRO_DISPLAY *display{nullptr};

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	al_set_new_window_position(410, 50);

	display = al_create_display(480, 630);

	if (!display)
		fail("Failed to initialize display");

	al_set_window_title(display, "Pac-man");

	ALLEGRO_BITMAP *icon_system = al_load_bitmap("assets/images/logo_system.png");

	al_set_display_icon(display, icon_system);

	// Audio
	al_reserve_samples(2);

	ALLEGRO_SAMPLE *theme{nullptr};

	ALLEGRO_SAMPLE *eat_fruit{nullptr};

	ALLEGRO_SAMPLE_INSTANCE *instance_theme{nullptr};

	ALLEGRO_SAMPLE_INSTANCE *instance_eat_fruit{nullptr};

	theme = al_load_sample("assets/audios/theme.wav");

	eat_fruit = al_load_sample("assets/audios/eat_fruit.wav");

	instance_theme = al_create_sample_instance(theme);

	instance_eat_fruit = al_create_sample_instance(eat_fruit);

	al_attach_sample_instance_to_mixer(instance_theme, al_get_default_mixer());

	al_attach_sample_instance_to_mixer(instance_eat_fruit, al_get_default_mixer());

	al_play_sample(theme, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, nullptr);

	// Background
	ALLEGRO_BITMAP *background = al_load_bitmap("assets/images/map.png");

	al_draw_bitmap(background, 0, 0, 0);

	// Food
	Food food[166];

	int counter_food{0};

	for (int row{0}; row < ROWS; row++)
	{
		for (int col{0}; col < COLS; col++)
		{
			if (map[row][col] == 'F')
			{
				if (row > 9)
					food[counter_food].setImg("assets/images/food_blue.png");

				food[counter_food].set(col, row);

				food[counter_food++].draw();
			}
		}
	}

	// Event
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 4); // Framerate

	if (!event_queue)
		fail("Failed to create event queue");

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Status
	ALLEGRO_BITMAP *logo_status = al_load_bitmap("assets/images/logo_status.png");

	Button points_bt, life_bt;

	points_bt.setIcon((char *)"assets/images/cherry.png");

	life_bt.setIcon((char *)"assets/images/life.png");

	life_bt.setFontX(421.0);

	life_bt.setIconX(443.0);

	// Winner & game over
	Button gameover, winner;

	winner.setIcon((char *)"assets/images/winner.png");

	winner.setIconX(115.0);

	winner.setIconY(180.0);

	gameover.setIcon((char *)"assets/images/gameover.png");

	gameover.setIconX(115.0);

	gameover.setIconY(180.0);

	// Enemy
	Enemy enemy_red, enemy_blue, enemy_pink, enemy_orange;

	enemy_red.setCharacterCol(1).setCharacterLine(1).setDirection(1);

	enemy_red.setImg("assets/images/ghost_red.png");

	enemy_blue.setCharacterCol(14).setCharacterLine(18).setDirection(0);

	enemy_blue.setImg("assets/images/ghost_blue.png");

	enemy_orange.setCharacterCol(14).setCharacterLine(1).setDirection(3);

	enemy_orange.setImg("assets/images/ghost_orange.png");

	enemy_pink.setCharacterCol(1).setCharacterLine(19).setDirection(2);

	enemy_pink.setImg("assets/images/ghost_pink.png");

	// Pac-man
	Pac pac;

	// Controls
	int direction{0}, intention{0}, points{0}, life{3};

	bool redraw{false}, mute{false};

	// Timer event
	al_start_timer(timer);

	// Game loop
	while (true)
	{
		// Events
		ALLEGRO_EVENT event;

		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}

		if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;

			if (event.keyboard.keycode == ALLEGRO_KEY_O)
			{
				mute = true;

				al_stop_samples();
			}
		}

		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			// Left (a), right (d), top (w) & down (s)
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

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			// Life
			if (life <= 0)
			{
				al_stop_samples();

				al_clear_to_color(al_map_rgb(225, 15, 36));

				gameover.showIcon();

				al_flip_display();

				al_rest(5.0);

				break;
			}

			if (points == 164)
			{
				al_stop_samples();

				al_clear_to_color(al_map_rgb(97, 207, 135));

				winner.showIcon();

				al_flip_display();

				al_rest(5.0);

				break;
			}

			if (compareGhostPac(enemy_blue, pac) || compareGhostPac(enemy_red, pac) || compareGhostPac(enemy_orange, pac) || compareGhostPac(enemy_pink, pac))
			{
				life--;

				direction = 0;

				pac.setCharacterCol(7).setCharacterLine(12).setDirection(0);
			}

			// Pac-man
			if (intention == 0 && pac.moveLeft(map))
				direction = intention;
			else if (intention == 1 && pac.moveRight(map))
				direction = intention;
			else if (intention == 2 && pac.moveUp(map))
				direction = intention;
			else if (intention == 3 && pac.moveDown(map))
				direction = intention;

			enemy_red.randomGhost(map);

			enemy_blue.randomGhost(map);

			enemy_orange.randomGhost(map);

			enemy_pink.randomGhost(map);
		}

		// Redraw
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(background, 0, 0, 0);

			for (int counter{0}; counter < counter_food; counter++)
			{
				if (pac.getCharacterLine() == food[counter].getY() && pac.getCharacterCol() == food[counter].getX())
				{
					if (!mute)
						al_play_sample(eat_fruit, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, nullptr);

					food[counter].set(-1, -1);

					points++;

					continue;
				}

				food[counter].draw();
			}

			// Enemys
			enemy_blue.move(enemy_blue.getDirection(), map);

			enemy_blue.draw();

			enemy_orange.move(enemy_orange.getDirection(), map);

			enemy_orange.draw();

			enemy_red.move(enemy_red.getDirection(), map);

			enemy_red.draw();

			enemy_pink.move(enemy_pink.getDirection(), map);

			enemy_pink.draw();

			// Pac-man
			pac.move(direction, map);

			pac.draw();

			// Status
			points_bt.setStr(const_cast<char *>(to_string(points).c_str()));

			points_bt.showStr().showIcon();

			life_bt.setStr(const_cast<char *>(to_string(life).c_str()));

			life_bt.showStr().showIcon();

			al_draw_bitmap(logo_status, 185.0, 597.0, 0);

			// Flush
			al_flip_display();
		}
	}

	// Clean garbage
	al_destroy_bitmap(logo_status);

	al_destroy_timer(timer);

	al_destroy_event_queue(event_queue);

	al_destroy_sample_instance(instance_eat_fruit);

	al_destroy_sample_instance(instance_theme);

	al_destroy_sample(eat_fruit);

	al_destroy_sample(theme);

	al_destroy_bitmap(background);

	al_destroy_bitmap(icon_system);

	al_destroy_display(display);

	return 0;
}