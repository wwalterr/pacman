
#include "character.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

Character::~Character(void)
{
    al_destroy_bitmap(this->img);
}

void Character::draw(void)
{
    al_draw_bitmap_region(this->img, this->direction * this->size, 0, this->size, this->size, this->character_col * this->size, this->character_line * this->size, 0);
}

Character& Character::setDirection(const int direction)
{
    this->direction = direction;

    return *this;
}

int Character::getDirection(void)
{
    return this->direction;
}

Character& Character::setCharacterCol(const int character_col)
{
    this->character_col = character_col;

    return *this;
}

int Character::getCharacterCol(void)
{
    return this->character_col;
}

Character& Character::setCharacterLine(const int character_line)
{
    this->character_line = character_line;

    return *this;
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