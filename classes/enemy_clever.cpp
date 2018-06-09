
#include "enemy_clever.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

EnemyClever::EnemyClever(void)
{
    this->direction = 1;

    this->character_col = 7;

    this->character_line = 12;

    this->size = 30;

    this->img = al_load_bitmap("images/ghost_blue.png");
};

EnemyClever::EnemyClever(const int direction = 0, const int character_col = 7, const int character_line = 12, const int size = 30, char const *img = {"images/ghost_blue.png"})
{
    this->direction = direction;

    this->character_col = character_col;

    this->character_line = character_line;

    this->size = size;

    this->img = al_load_bitmap(img);
};

EnemyClever::EnemyClever(EnemyClever &obj)
{
    this->direction = obj.direction;

    this->character_col = obj.character_col;

    this->character_line = obj.character_line;

    this->size = obj.size;

    this->img = obj.img;
}

void EnemyClever::setImg(char const *img)
{
    this->img = al_load_bitmap(img);
}

void EnemyClever::smartGhost(char map[][17], const Dijkstra &path, const int p_line, const int p_column)
{
    int dj{path.dijkstra(this->getCharacterLine() * this->getCharacterCol(), p_line * p_column)};

    // Delay -> event list -> dijkstra function
}