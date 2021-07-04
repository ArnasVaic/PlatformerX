#pragma once

#include <allegro5/allegro.h>

class Input {

	unsigned int mods = 0;
	int keys[ALLEGRO_KEY_MAX];

	Input() noexcept {
		memset(keys, 0, sizeof(keys));
	}
	
public:

	// Mouse buttons
	constexpr static int LEFT_MOUSE_BUTTON = 1;
	constexpr static int RIGHT_MOUSE_BUTTON	= 2;
	constexpr static int MIDDLE_MOUSE_BUTTON= 3;

	constexpr static int KEY_SEEN	  = 1;
	constexpr static int KEY_RELEASED = 2;

	constexpr static int NO_MODS  =  0;
	constexpr static int ANY_MODS = -1;

	Input(Input const&) = delete;
	void operator = (Input const&) = delete;

	static Input& get() noexcept {
		static Input input;
		return input;
	}

	constexpr bool isKeyHeld(int const key, unsigned int const mods = ANY_MODS) noexcept {
		if(mods == ANY_MODS || this->mods == mods) return keys[key];
		return false;
	}

	constexpr void handleEvent(ALLEGRO_EVENT const & event) noexcept {
		// code source:
		// https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace%3A-Input
		for (int i = 0; i < ALLEGRO_KEY_MAX; i++)  {
			keys[i] &= KEY_SEEN;
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			keys[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
			mods = event.keyboard.modifiers;
		}
		if (event.type == ALLEGRO_EVENT_KEY_UP) {
			keys[event.keyboard.keycode] &= KEY_RELEASED;
		}
	}
};