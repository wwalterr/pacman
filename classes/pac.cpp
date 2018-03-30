
#include "pac.hpp"

#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

Pac::Pac(void)
{
    this->c_pac = 7;

    this->l_pac = 12;

    this->size = 30;

    this->direction = 0;

    this->img = al_load_bitmap("images/pac.png");
};

Pac::Pac(const int c_pac = 7, const int l_pac = 12, const int size = 30, const int direction = 0, char const *img = {"images/pac.png"})
{
    this->c_pac = c_pac;

    this->l_pac = l_pac;

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
    al_draw_bitmap_region(this->img, this->direction * size, 0, size, size, this->c_pac * 30, this->l_pac * 30, 0);
}

void Pac::set(const int c_pac, const int l_pac, const int direction)
{
    this->c_pac = c_pac;

    this->l_pac = l_pac;

    this->direction = direction;
}