
#include "food.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Food::Food(void)
{
    this->x = 0;

    this->y = 0;

    this->size = 30;

    this->img = al_load_bitmap("images/pacman_food.png");
};

Food::Food(const int x = 0, const int y = 0, const int size = 30, char const *img = {"images/pacman_food.png"})
{
    this->x = x;

    this->y = y;

    this->size = size;

    this->img = al_load_bitmap(img);
};

void Food::draw(void)
{
    al_draw_bitmap(this->img, this->x * this->size, this->y * this->size, 0);
}

void Food::setX(const float x = 0)
{
    this->x = x;
}

float Food::getX(void)
{
    return this->x;
}

void Food::setY(const float y = 0)
{
    this->y = y;
}

float Food::getY(void)
{
    return this->y;
}

void Food::setSize(const int size = 30)
{
    this->size = size;
}

int Food::getSize(void)
{
    return this->size;
}

void Food::setImg(char const *img = {"images/pacman_food.png"})
{
    this->img = al_load_bitmap(img);
}

ALLEGRO_BITMAP *Food::getImg(void)
{
    return this->img;
}

void Food::set(const float x = 0, const float y = 0)
{
    this->setX(x);

    this->setY(y);
}

Food::~Food(void)
{
    al_destroy_bitmap(this->img);
}