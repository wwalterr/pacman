#include "enemy.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Enemy::Enemy(void)
{
	this->direction = 1;

	this->character_col = 7;

	this->character_line = 12;

	this->size = 30;

	this->img = al_load_bitmap("assets/images/ghost_red.png");
};

Enemy::Enemy(const int direction = 0, const int character_col = 7, const int character_line = 12, const int size = 30, char const *img = {"assets/images/ghost_red.png"})
{
	this->direction = direction;

	this->character_col = character_col;

	this->character_line = character_line;

	this->size = size;

	this->img = al_load_bitmap(img);
};

Enemy::Enemy(Enemy &obj)
{
	this->direction = obj.direction;

	this->character_col = obj.character_col;

	this->character_line = obj.character_line;

	this->size = obj.size;

	this->img = obj.img;
}

void Enemy::setImg(char const *img)
{
	this->img = al_load_bitmap(img);
}

void Enemy::randomGhost(char map[][17])
{
	bool enemy_loop{true};

	int enemy_random{0};

	// Loop until find a valid random position
	while (enemy_loop)
	{
		enemy_random = rand() % 4;

		switch (enemy_random)
		{
		case 0:
			if (this->moveLeft(map) && this->getDirection() != 1)
			{
				this->setDirection(0);

				enemy_loop = false;
			}

			break;

		case 1:
			if (this->moveRight(map) && this->getDirection() != 0)
			{
				this->setDirection(1);

				enemy_loop = false;
			}

			break;

		case 2:
			if (this->moveUp(map) && this->getDirection() != 3)
			{
				this->setDirection(2);

				enemy_loop = false;
			}

			break;

		case 3:
			if (this->moveDown(map) && this->getDirection() != 2)
			{
				this->setDirection(3);

				enemy_loop = false;
			}

			break;
		}
	}
}