
#include "btn.hpp"

#include <allegro5/allegro_font.h>

#include <allegro5/allegro_ttf.h>

Btn::Btn(void)
{
    this->setFontPath("fonts/roboto_regular.ttf");

    this->setFontSize(15);

    this->setFontFlag(0);

    this->updateFont();

    this->setColor(255, 255, 0);

    this->setX(60.0);

    this->setY(602.0);

    this->setStr("Text");
}

Btn::Btn(const char *font_path = {"fonts/roboto_regular.ttf"}, const int font_size = 15, const int font_flag = 0, const int red = 255, const int green = 255, const int blue = 0, const float x = 60.0, const float y = 602.0, const char *str = {"Text"})
{
    this->font_path = font_path;

    this->font_size = font_size;

    this->font_flag = font_flag;

    this->setColor(red, green, blue);

    this->setX(x);

    this->setY(y);

    this->setStr(str);
}

Btn::~Btn(void)
{
    al_destroy_font(this->font);
}

void Btn::updateFont(void)
{
    this->font = al_load_ttf_font(this->font_path, this->font_size, this->font_flag);
}

void Btn::setFontPath(const char *font_path)
{
    this->font_path = font_path;
}

const char *Btn::getFontPath(void)
{
    return this->font_path;
}

void Btn::setFontSize(const int font_size)
{
    this->font_size = font_size;
}

int Btn::getFontSize(void)
{
    return this->font_size;
}

void Btn::setFontFlag(const int font_flag)
{
    this->font_flag = font_flag;
}

int Btn::getFontFlag(void)
{
    return this->font_flag;
}

void Btn::setColor(const int red, const int green, const int blue)
{
    this->color = al_map_rgb(red, green, blue);
}

ALLEGRO_COLOR Btn::getColor(void)
{
    return this->color;
}

void Btn::setX(const float x)
{
    this->font_x = x;
}

float Btn::getX(void)
{
    return this->font_x;
}

void Btn::setY(const float y)
{
    this->font_y = y;
}

float Btn::getY(void)
{
    return this->font_y;
}

void Btn::setStr(const char *str)
{
    this->str = str;
}

const char *Btn::getStr(void)
{
    return this->str;
}

void Btn::showBtn(void)
{
    al_draw_text(this->font, this->color, this->font_x, this->font_y, ALLEGRO_ALIGN_CENTER, this->str);
}