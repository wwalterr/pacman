
#include "wall.hpp"

#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

using namespace std;

Wall::Wall()
{ // Default values to some object
    this->x = 0;

    this->y = 0;

    this->img = al_load_bitmap("images/wall.bmp");
};

Wall::Wall(const int x, const int y, char const *img_url)
{
    this->x = x;

    this->y = y;

    this->img = al_load_bitmap(img_url);
};

Wall::~Wall(void)
{
    /* cout << "\nObject [ \033[36mWall\033[37m ] is being \033[31mdeleted\033[37m\n"
         << endl; */

    al_destroy_bitmap(this->img);
}

void Wall::draw(void)
{
    al_draw_bitmap(this->img, this->x, this->y, 0);
}

void Wall::set(float x_set, float y_set)
{
    this->x = x_set;

    this->y = y_set;
}