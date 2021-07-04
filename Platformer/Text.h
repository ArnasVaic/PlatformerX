#pragma once

#include <allegro5/allegro_font.h>

#include <iostream>
#include <string>

#include "Collision.h"
#include "Constants.h"
#include "Assets.h"

class Text {
	std::string str;
	point<float> position;
	ALLEGRO_FONT* font;
	ALLEGRO_COLOR color;
public:
	Text(
		std::string const& str = "",
		ALLEGRO_FONT* font = Assets::get().default_font,
		ALLEGRO_COLOR color = al_map_rgb(255, 255, 255)
	) noexcept;

	void draw() const noexcept;
	void draw(ALLEGRO_TRANSFORM& transform) const noexcept;

	/// Setters
	void setString(std::string const& str) noexcept;
	void setFont(ALLEGRO_FONT* font) noexcept;
	void setColor(ALLEGRO_COLOR color) noexcept;
	void setPosition(point<float> const& position) noexcept;

	/// Getters
	int getWidth() const noexcept;
	int getHeight() const noexcept;
	point<int> getSize() const noexcept;
	rect<float> getBounds() const noexcept;
	std::string getString() const noexcept;
	ALLEGRO_FONT* getFont() const noexcept;
	ALLEGRO_COLOR getColor() const noexcept;
	point<float> getPosition() const noexcept;
};