
#ifndef EXTRAS_H

#define EXTRAS_H

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include "character.hpp"

#include "pac.hpp"

int fail(const char *);

bool compareGhostPac(Character &, Pac &);

#endif