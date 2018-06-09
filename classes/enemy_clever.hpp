
#ifndef ENEMY_CLEVER_H

#define ENEMY_CLEVER_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include "character.hpp"

#include "dijkstra.hpp"

class EnemyClever : virtual public Character
{
public:
  EnemyClever(void);

  EnemyClever(const int, const int, const int, const int, char const *);

  EnemyClever(EnemyClever &);

  void setImg(char const *);

  void smartGhost(char map[][17], const Dijkstra &, const int, const int);
};

#endif