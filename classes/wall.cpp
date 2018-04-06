
#include "wall.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Wall::Wall(void)
{
    this->x = 0.0;

    this->y = 0.0;

    this->size = 30;

    this->img = al_load_bitmap("images/pacman_wall.png");
};

Wall::Wall(const float x = 0, const float y = 0, const int size = 30, char const *img = {"images/pacman_wall.png"})
{
    this->x = x;

    this->y = y;

    this->size = size;

    this->img = al_load_bitmap(img);
};

void Wall::draw(void)
{
    al_draw_bitmap(this->img, this->x * this->size, this->y * this->size, 0);
}

void Wall::setX(const float x = 0)
{
    this->x = x;
}

float Wall::getX(void)
{
    return this->x;
}

void Wall::setY(const float y = 0)
{
    this->y = y;
}

float Wall::getY(void)
{
    return this->y;
}

void Wall::setSize(const int size = 30)
{
    this->size = size;
}

int Wall::getSize(void)
{
    return this->size;
}

void Wall::setImg(char const *img = {"images/pacman_wall.png"})
{
    this->img = al_load_bitmap(img);
}

ALLEGRO_BITMAP *Wall::getImg(void)
{
    return this->img;
}

void Wall::set(const float x = 0, const float y = 0)
{
    this->setX(x);

    this->setY(y);
}

Wall::~Wall(void)
{
    al_destroy_bitmap(this->img);
}