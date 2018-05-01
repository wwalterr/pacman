
#ifndef ENEMY_H

#define ENEMY_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include "character.hpp"

class Enemy : public Character
{
public:
  Enemy(void);

  Enemy(const int, const int, const int, const int, char const *);

  Enemy(Enemy &);

  ~Enemy(void);
};

#endif