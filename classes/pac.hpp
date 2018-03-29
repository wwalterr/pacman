
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

#ifndef PAC_H

#define PAC_H

class Pac
{

private:
  int direction, x, y, size;

  ALLEGRO_BITMAP *img;

public:
  Pac(void);

  Pac(const int x, const int y, const int size, const int direction, char const *img);

  void draw(void);

  void set(const int x, const int y, const int direction);

  ~Pac(void);
};

#endif