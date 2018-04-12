
#ifndef BTN_H

#define BTN_H

#include <allegro5/allegro_font.h>

#include <allegro5/allegro_ttf.h>

class Btn
{

  private:
    ALLEGRO_COLOR color;

    ALLEGRO_FONT *font;

    const char *font_path;

    const char *str;

    int font_size, font_flag;

    float font_x, font_y;

  public:
    Btn();

    Btn(const char *, const int, const int, const int, const int, const int, const float, const float, const char *);

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

    void setX(const float);

    float getX(void);

    void setY(const float);

    float getY(void);

    void setStr(const char *);

    const char *getStr(void);

    void showBtn(void);
};

#endif