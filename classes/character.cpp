
#include "character.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

void Character::draw(void)
{
    al_draw_bitmap_region(this->img, this->direction * this->size, 0, this->size, this->size, this->character_col * this->size, this->character_line * this->size, 0);
}

void Character::setDirection(const int direction)
{
    this->direction = direction;
}

int Character::getDirection(void)
{
    return this->direction;
}

void Character::setCharacterCol(const int character_col)
{
    this->character_col = character_col;
}

int Character::getCharacterCol(void)
{
    return this->character_col;
}

void Character::setCharacterLine(const int character_line)
{
    this->character_line = character_line;
}

int Character::getCharacterLine(void)
{
    return this->character_line;
}

void Character::setSize(const int size)
{
    this->size = size;
}

int Character::getSize(void)
{
    return this->size;
}

void Character::set(const int character_col = 7, const int character_line = 12, const int direction = 0)
{
    this->setCharacterCol(character_col);

    this->setCharacterLine(character_line);

    this->setDirection(direction);
}

bool Character::moveLeft(char map[][17])
{
    if (map[this->getCharacterLine()][this->getCharacterCol() - 1] == 'W')
        return false;

    return true;
}

bool Character::moveRight(char map[][17])
{
    if (map[this->getCharacterLine()][this->getCharacterCol() + 1] == 'W')
        return false;

    return true;
}

bool Character::moveUp(char map[][17])
{
    if (map[this->getCharacterLine() - 1][this->getCharacterCol()] == 'W')
        return false;

    return true;
}

bool Character::moveDown(char map[][17])
{
    if (map[this->getCharacterLine() + 1][this->getCharacterCol()] == 'W')
        return false;

    return true;
}

bool Character::move(const int direction, char map[][17])
{
    this->setDirection(direction);

    switch (this->direction)
    {
    case 0: // Left
        if (!moveLeft(map))
            return false;

        this->character_col -= 1;

        return true;

    case 1: // Right
        if (!moveRight(map))
            return false;

        this->character_col += 1;

        return true;

    case 2: // Top
        if (!moveUp(map))
            return false;

        this->character_line -= 1;

        return true;

    case 3: // Bottom
        if (!moveDown(map))
            return false;

        this->character_line += 1;

        return true;
    };

    return false;
}

/* Character::~Character(void)
{
    al_destroy_bitmap(this->img);
} */