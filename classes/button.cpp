#include "button.hpp"

Button::Button(void)
{
	this->setColor(255, 255, 0);

	this->setStr((char *)"Text");

	this->setFontPath((char *)"fonts/roboto_regular.ttf");

	this->setFontSize(14);

	this->setFontFlag(0);

	this->setFontX(60.0);

	this->setFontY(605.0);

	this->setIconX(10.0);

	this->setIconY(598.0);
}

Button::Button(char *icon, char *font_path, const int font_size, const int font_flag, const int red, const int green, const int blue, const float font_x, const float font_y, char *str, const float icon_x, const float icon_y) : font_size(font_size), font_flag(font_flag), font_x(font_x), font_y(font_y), icon_x(icon_x), icon_y(icon_y)
{
	this->setIcon(icon);

	this->setColor(red, green, blue);

	this->setStr(str);

	this->setFontPath(font_path);

	this->setFontSize(font_size);

	this->setFontFlag(font_flag);

	this->setFontX(font_x);

	this->setFontY(font_y);

	this->setIconX(icon_x);

	this->setIconY(icon_y);
}

Button::~Button(void)
{
	al_destroy_bitmap(this->icon);

	al_destroy_font(this->font);

	delete str;

	delete font_path;
}

void Button::updateFont(void)
{
	this->font = al_load_ttf_font(this->font_path, this->font_size, this->font_flag);
}

void Button::setFontPath(char *font_path)
{
	this->font_path = font_path;
}

char *Button::getFontPath(void)
{
	return this->font_path;
}

void Button::setFontSize(const int font_size)
{
	this->font_size = font_size;
}

int Button::getFontSize(void)
{
	return this->font_size;
}

void Button::setFontFlag(const int font_flag)
{
	this->font_flag = font_flag;
}

int Button::getFontFlag(void)
{
	return this->font_flag;
}

void Button::setColor(const int red, const int green, const int blue)
{
	this->color = al_map_rgb(red, green, blue);
}

ALLEGRO_COLOR Button::getColor(void)
{
	return this->color;
}

void Button::setIconX(const float x)
{
	this->icon_x = x;
}

float Button::getIconX(void)
{
	return this->icon_x;
}

void Button::setIconY(const float y)
{
	this->icon_y = y;
}

float Button::getIconY(void)
{
	return this->icon_y;
}

void Button::setFontX(const float x)
{
	this->font_x = x;
}

float Button::getFontX(void)
{
	return this->font_x;
}

void Button::setFontY(const float y)
{
	font_y = y;
}

float Button::getFontY(void)
{
	return this->font_y;
}

void Button::setStr(char *str)
{
	this->str = str;
}

char *Button::getStr(void)
{
	return this->str;
}

void Button::setIcon(char *icon)
{
	this->icon = al_load_bitmap(icon);
}

ALLEGRO_BITMAP *Button::getIcon(void)
{
	return this->icon;
}

Button &Button::showStr(void)
{
	this->updateFont();

	al_draw_text(this->font, this->color, this->font_x, this->font_y, ALLEGRO_ALIGN_CENTER, this->str);

	return *this;
}

void Button::showIcon(void)
{
	al_draw_bitmap(this->icon, this->icon_x, this->icon_y, 0);
}