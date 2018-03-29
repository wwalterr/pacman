
#include "pac.hpp"

#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

Pac::Pac(void)
{
    this->x = 210;

    this->y = 360;

    this->size = 30;

    this->direction = 0;

    this->img = al_load_bitmap("images/pac.png");
};

Pac::Pac(const int x, const int y, const int size, const int direction, char const *img)
{
    this->x = x;

    this->y = y;

    this->size = size;

    this->direction = direction;
    
    this->img = al_load_bitmap(img);
};

Pac::~Pac(void)
{
    al_destroy_bitmap(this->img);
}

void Pac::draw(void)
{
    al_draw_bitmap_region(this->img, this->direction * size, 0, size, size, x, y, 0);
}

void Pac::set(const int x, const int y, const int direction)
{
    this->x = x;

    this->y = y;

    this->direction = direction;
}