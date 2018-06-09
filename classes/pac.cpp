
#include "pac.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Pac::Pac(void)
{
    this->direction = 0;

    this->character_col = 7;

    this->character_line = 12;

    this->size = 30;

    this->img = al_load_bitmap("images/pacman_sprite.png");
};

Pac::Pac(const int direction = 0, const int character_col = 7, const int character_line = 12, const int size = 30, char const *img = {"images/pacman_sprite.png"})
{
    this->direction = direction;

    this->character_col = character_col;

    this->character_line = character_line;

    this->size = size;

    this->img = al_load_bitmap(img);
};

Pac::Pac(Pac &obj)
{
    this->direction = obj.direction;

    this->character_col = obj.character_col;

    this->character_line = obj.character_line;

    this->size = obj.size;

    this->img = obj.img;
}