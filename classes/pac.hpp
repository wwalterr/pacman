
#ifndef PAC_H

#define PAC_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

class Pac
{

private:
  int direction, pacman_col, pacman_line, size;
 
  ALLEGRO_BITMAP *img;

public:
  Pac(void);

  Pac(const int direction, const int pacman_col, const int pacman_line, const int size, char const *img);

  Pac(Pac &obj);

  void draw(void);

  void setDirection(const int direction);

  int getDirection(void);

  void setPacmanCol(const int pacman_col);

  int getPacmanCol(void);

  void setPacmanLine(const int pacman_line);

  int getPacmanLine(void);

  void setSize(const int size);

  int getSize(void);

  void set(const int pacman_col, const int pacman_line, const int direction);

  bool moveLeft(char map[][17]);

  bool moveRight(char map[][17]);

  bool moveUp(char map[][17]);

  bool moveDown(char map[][17]);

  bool move(const int direction, char map[][17]);

  ~Pac(void);
};

#endif