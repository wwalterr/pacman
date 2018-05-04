
#include "enemy.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Enemy::Enemy(void)
{
    this->direction = 1;

    this->character_col = 7;

    this->character_line = 12;

    this->size = 30;

    this->img = al_load_bitmap("images/ghost_blue.png");
};

Enemy::Enemy(const int direction = 0, const int character_col = 7, const int character_line = 12, const int size = 30, char const *img = {"images/pacman_wall.png"})
{
    this->direction = direction;

    this->character_col = character_col;

    this->character_line = character_line;

    this->size = size;

    this->img = al_load_bitmap(img);
};

Enemy::Enemy(Enemy &obj)
{
    this->direction = obj.direction;

    this->character_col = obj.character_col;

    this->character_line = obj.character_line;

    this->size = obj.size;

    this->img = obj.img;
}

Enemy::~Enemy(void)
{
    al_destroy_bitmap(this->img);
}