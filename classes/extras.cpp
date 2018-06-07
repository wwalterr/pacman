
#include "extras.hpp"

#include <iostream>

#include <allegro5/allegro.h>

#include <allegro5/allegro_native_dialog.h>

int fail(const char *message)
{
    std::cerr << "\n\033[31mError\033[37m : " << message << "\n\n";

    exit(
        al_show_native_message_box(nullptr, "Error", "Error", message, nullptr, ALLEGRO_MESSAGEBOX_ERROR));
}

bool compareGhostPac(Enemy &e_obj, Pac &p_obj)
{
	if (e_obj.getCharacterCol() == p_obj.getCharacterCol() && e_obj.getCharacterLine() == p_obj.getCharacterLine())
		return true;

	return false;
}