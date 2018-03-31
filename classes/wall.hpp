
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

#ifndef WALL_H

#define WALL_H

class Wall
{

private:
  float x, y;

  int size;

  ALLEGRO_BITMAP *img;

public:
  Wall(void);

  Wall(const int x, const int y, const int size, char const *img);

  void draw(void);

  void set(float x, float y);

  ~Wall(void);
};

#endif