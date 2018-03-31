
#include "wall.hpp"

#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

Wall::Wall(void)
{
    this->size = 30;

    this->x = 0;

    this->y = 0;

    this->img = al_load_bitmap("images/wall.png");
};

Wall::Wall(const int x, const int y, const int size, char const *img)
{
    this->size = size;

    this->x = x;

    this->y = y;

    this->img = al_load_bitmap(img);
};

Wall::~Wall(void)
{
    al_destroy_bitmap(this->img);
}

void Wall::draw(void)
{
    al_draw_bitmap(this->img, this->x * this->size, this->y * this->size, 0);
}

void Wall::set(float x, float y)
{
    this->x = x;

    this->y = y;
}