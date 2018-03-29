
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

#ifndef FOOD_H

#define FOOD_H

class Food
{

private:
  float x, y;

  ALLEGRO_BITMAP *img;

public:
  Food(void);

  Food(const int x, const int y, char const *img);

  void draw(void);

  void set(float x, float y);

  ~Food(void);
};

#endif