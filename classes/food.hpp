
#ifndef FOOD_H

#define FOOD_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

class Food
{

private:
  float x, y;

  int size;

  ALLEGRO_BITMAP *img;

public:
  Food(void);

  Food(const float, const float, const int, char const *);

  void draw(void);

  void setX(const float);

  float getX(void);

  void setY(const float);

  float getY(void);

  void setSize(const int);

  int getSize(void);

  void setImg(char const *);

  ALLEGRO_BITMAP *getImg(void);

  void set(const float, const float);

  ~Food(void);
};

#endif