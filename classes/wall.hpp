
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

  ALLEGRO_BITMAP *img;

public:
  Wall(void); // Default constructor

  Wall(const int x, const int y, char const *img_url); // Normal constructor

  void draw(void); // Draw on Display

  void set(float x_set, float y_set); // Define positions

  ~Wall(void); // Destructor
};

#endif