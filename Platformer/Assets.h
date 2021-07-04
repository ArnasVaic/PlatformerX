#pragma once

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include <iostream>

class Assets {
	~Assets() noexcept;
	Assets() noexcept;
	Assets(Assets const&) = delete;
	void operator = (Assets const&) = delete;

	void load() noexcept;
	void unload() noexcept;
public:

	static Assets& get() noexcept;

	ALLEGRO_FONT* default_font;
	ALLEGRO_BITMAP* bitmap;
	ALLEGRO_BITMAP* player_sheet;
	ALLEGRO_BITMAP* widget_idle;
	ALLEGRO_BITMAP* widget_selected;
};