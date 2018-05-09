
#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

int fail(const char *message)
{
    std::cerr << "\n\033[31mError\033[37m : " << message << "\n\n";

    exit(
        al_show_native_message_box(nullptr, "Error", "Error", message, nullptr, ALLEGRO_MESSAGEBOX_ERROR));
}

bool compareGhost(Enemy &obj_1, Enemy &obj_2)
{
	if (obj_1.getCharacterCol() == obj_2.getCharacterCol() && obj_1.getCharacterLine() == obj_2.getCharacterLine())
		return true;

	return false;
}

bool compareGhostPac(Enemy &e_obj, Pac &p_obj)
{
	if (e_obj.getCharacterCol() == p_obj.getCharacterCol() && e_obj.getCharacterLine() == p_obj.getCharacterLine())
		return true;

	return false;
}

void randomGhost(Enemy &e_obj, char map[][17])
{
	bool enemy_loop{true};

	int enemy_random{0};

	while (enemy_loop)
	{
		enemy_random = rand() % 4;

		switch (enemy_random)
		{
		case 0:
			if (e_obj.moveLeft(map) && e_obj.getDirection() != 1)
			{
				e_obj.setDirection(0);

				enemy_loop = false;
			}

			break;

		case 1:
			if (e_obj.moveRight(map) && e_obj.getDirection() != 0)
			{
				e_obj.setDirection(1);

				enemy_loop = false;
			}

			break;

		case 2:
			if (e_obj.moveUp(map) && e_obj.getDirection() != 3)
			{
				e_obj.setDirection(2);

				enemy_loop = false;
			}

			break;

		case 3:
			if (e_obj.moveDown(map) && e_obj.getDirection() != 2)
			{
				e_obj.setDirection(3);

				enemy_loop = false;
			}

			break;
		}
	}
}