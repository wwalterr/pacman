
#include "enemy_clever.hpp"

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include <iostream>

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
    while(true){
    // Right, Left, Top & Down

        int cache[] {
                    path.dijkstra(this->getCharacterLine() * (this->getCharacterCol() - 1), p_line * p_column),
                    path.dijkstra(this->getCharacterLine() * (this->getCharacterCol() + 1), p_line * p_column),
                    path.dijkstra((this->getCharacterLine() + 1) * this->getCharacterCol(), p_line * p_column),
                    path.dijkstra((this->getCharacterLine() - 1) * this->getCharacterCol(), p_line * p_column)};

        int smallest = cache[0], smallestIndice{0};

        for (int counter = 1; counter <= 3; counter++)
        {
            if (cache[counter] < smallest)
            {
                smallest = cache[counter];

                smallestIndice = counter;
            }
        }

        std::cout << "\n\n\033[31mL\033[37m " << cache[0] << " \033[31mR\033[37m " << cache[1] << " \033[31mU\033[37m " << cache[2] << " \033[31mD\033[37m " << cache[3] << " \033[34mS\033[37m " << cache[smallestIndice] << "\n\n";

        switch (smallestIndice)
        {
        case 0:
            if (this->moveLeft(map) && this->getDirection() != 1)
                this->setDirection(0);
            return;

        case 1:
            if (this->moveRight(map) && this->getDirection() != 0)
                this->setDirection(1);
            return;

        case 2:
            if (this->moveUp(map) && this->getDirection() != 3)
                this->setDirection(2);
            return;

        case 3:
            if (this->moveDown(map) && this->getDirection() != 2)
                this->setDirection(3);
            return;
        }
    }
}