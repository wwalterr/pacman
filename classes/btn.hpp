
#ifndef BTN_H

#define BTN_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_font.h>

#include <allegro5/allegro_ttf.h>

class Btn
{

private:
  ALLEGRO_BITMAP *icon;

  ALLEGRO_COLOR color;

  ALLEGRO_FONT *font;

  const char *font_path;

  const char *str;

  int font_size, font_flag;

  float font_x, font_y, icon_x, icon_y;

public:
  Btn();

  Btn(const char *, const char *, const int, const int, const int, const int, const int, const float, const float, const char *, const float, const float);

  ~Btn(void);

  void updateFont(void);

  void setFontPath(const char *);

  const char *getFontPath(void);

  void setFontSize(const int);

  int getFontSize(void);

  void setFontFlag(const int);

  int getFontFlag(void);

  void setColor(const int, const int, const int);

  ALLEGRO_COLOR getColor(void);

  void setIconX(const float);

  float getIconX(void);

  void setIconY(const float);

  float getIconY(void);

  void setX(const float);

  float getX(void);

  void setY(const float);

  float getY(void);

  void setStr(const char *);

  const char *getStr(void);

  Btn &showStr(void);

  void setIcon(const char *);

  ALLEGRO_BITMAP *getIcon(void);

  void showIcon(void);

  void showIcon(Btn);
};

#endif