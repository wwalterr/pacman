
#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

#ifndef PAC_H

#define PAC_H

class Pac
{

private:
  int direction, c_pac, l_pac, size;

  ALLEGRO_BITMAP *img;

public:
  Pac(void);

  Pac(const int c_pac, const int l_pac, const int size, const int direction, char const *img);

  void draw(void);

  void set(const int c_pac, const int l_pac, const int direction);

  ~Pac(void);
};

#endif