#include "Assets.h"

Assets::~Assets() noexcept {
	this->unload();
	std::cerr << "Assets unloaded\n";
}

Assets::Assets() noexcept {
	this->load();
	std::cerr << "Assets loaded\n";
}

void Assets::load() noexcept {
	default_font = al_load_ttf_font("font.ttf", 24, 0);
	bitmap = al_load_bitmap("player.png");
	player_sheet = al_load_bitmap("playersheet.png");

	widget_idle = al_load_bitmap("button_idle.png");
	widget_selected = al_load_bitmap("button_selected.png");
}

void Assets::unload() noexcept {
	al_destroy_font(default_font);
	al_destroy_bitmap(bitmap);
	al_destroy_bitmap(player_sheet);
	al_destroy_bitmap(widget_idle);
	al_destroy_bitmap(widget_selected);
}

Assets& Assets::get() noexcept {
	static Assets assets;
	return assets;
}