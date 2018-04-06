
#ifndef WALL_H

#define WALL_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

class Wall
{

private:
  float x, y;

  int size;

  ALLEGRO_BITMAP *img;

public:
  Wall(void);

  Wall(const float x, const float y, const int size, char const *img);

  void draw(void);

  void setX(const float x);

  float getX(void);

  void setY(const float y);

  float getY(void);

  void setSize(const int size);

  int getSize(void);

  void setImg(char const *img);

  ALLEGRO_BITMAP *getImg(void);

  void set(const float x, const float y);

  ~Wall(void);
};

#endif