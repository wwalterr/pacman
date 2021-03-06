#ifndef ENEMY_H

#define ENEMY_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include "character.hpp"

class Enemy : virtual public Character
{
public:
	Enemy(void);

	Enemy(const int, const int, const int, const int, char const *);

	Enemy(Enemy &);

	void setImg(char const *);

	void randomGhost(char map[][17]);
};

#endif