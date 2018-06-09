
#ifndef PAC_H

#define PAC_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

#include "character.hpp"

class Pac : virtual public Character
{
public:
  Pac(void);

  Pac(const int, const int, const int, const int, char const *);

  Pac(Pac &);
};

#endif