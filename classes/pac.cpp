
#include "pac.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Pac::Pac(void)
{
    this->direction = 0;

    this->pacman_col = 7;

    this->pacman_line = 12;

    this->size = 30;

    this->img = al_load_bitmap("images/pacman_sprite.png");
};

Pac::Pac(const int direction = 0, const int pacman_col = 7, const int pacman_line = 12, const int size = 30, char const *img = {"images/pacman_sprite.png"})
{
    this->direction = direction;

    this->pacman_col = pacman_col;

    this->pacman_line = pacman_line;

    this->size = size;

    this->img = al_load_bitmap(img);
};

void Pac::draw(void)
{
    al_draw_bitmap_region(this->img, this->direction * size, 0, size, size, this->pacman_col * 30, this->pacman_line * 30, 0);
}

void Pac::setDirection(const int direction)
{
    this->direction = direction;
}

int Pac::getDirection(void)
{
    return this->direction;
}

void Pac::setPacmanCol(const int pacman_col)
{
    this->pacman_col = pacman_col;
}

int Pac::getPacmanCol(void)
{
    return this->pacman_col;
}

void Pac::setPacmanLine(const int pacman_line)
{
    this->pacman_line = pacman_line;
}

int Pac::getPacmanLine(void)
{
    return this->pacman_line;
}

void Pac::setSize(const int size)
{
    this->size = size;
}

int Pac::getSize(void)
{
    return this->size;
}

void Pac::set(const int pacman_col = 7, const int pacman_line = 12, const int direction = 0)
{
    this->setPacmanCol(pacman_col);

    this->setPacmanLine(pacman_line);

    this->setDirection(direction);
}

bool Pac::moveLeft(char map[][17])
{
    if (map[this->getPacmanLine()][this->getPacmanCol() - 1] == 'W')
        return false;

    return true;
}

bool Pac::moveRight(char map[][17])
{
    if (map[this->getPacmanLine()][this->getPacmanCol() + 1] == 'W')
        return false;

    return true;
}

bool Pac::moveUp(char map[][17])
{
    if (map[this->getPacmanLine() - 1][this->getPacmanCol()] == 'W')
        return false;

    return true;
}

bool Pac::moveDown(char map[][17])
{
    if (map[this->getPacmanLine() + 1][this->getPacmanCol()] == 'W')
        return false;

    return true;
}

bool Pac::move(const int direction, char map[][17])
{
    this->setDirection(direction);

    switch (this->direction)
    {
    case 0: // Left
        if (!moveLeft(map))
            return false;

        this->pacman_col -= 1;

        return true;

    case 1: // Right
        if (!moveRight(map))
            return false;

        this->pacman_col += 1;

        return true;

    case 2: // Up
        if (!moveUp(map))
            return false;

        this->pacman_line -= 1;

        return true;

    case 3: // Down
        if (!moveDown(map))
            return false;

        this->pacman_line += 1;

        return true;
    };

    return false;
}

Pac::~Pac(void)
{
    al_destroy_bitmap(this->img);
}