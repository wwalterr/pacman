
#ifndef EXTRAS_H

#define EXTRAS_H

#include "enemy.hpp"

#include "pac.hpp"

int fail(const char *);

bool compareGhost(Enemy &, Enemy &);

bool compareGhostPac(Enemy &, Pac &);

void randomGhost(Enemy &, char map[][17]);

#endif