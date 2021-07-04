#include "Text.h"

Text::Text(
	std::string const& str,
	ALLEGRO_FONT* font,
	ALLEGRO_COLOR color
) noexcept :
str(str),
position({ 0.0f, 0.0f }),
font(font),
color(color) {

}

void Text::draw() const noexcept {
	al_draw_text(font, color, position.x, position.y, 0, str.c_str());
}

void Text::draw(ALLEGRO_TRANSFORM& transform) const noexcept {
	al_use_transform(&transform);
	al_draw_text(font, color, position.x, position.y, 0, str.c_str());
	al_use_transform(&Constants::get().identity_transform);
}

/// Setters
void Text::setString(std::string const& str) noexcept {
	this->str = str;
}

void Text::setFont(ALLEGRO_FONT* font) noexcept {
	this->font = font;
}

void Text::setColor(ALLEGRO_COLOR color) noexcept {
	this->color = color;
}

void Text::setPosition(point<float> const& position) noexcept {
	this->position = position;
}

/// Getters

int Text::getWidth() const noexcept {
	return al_get_text_width(font, str.c_str());
}

int Text::getHeight() const noexcept {
	return al_get_font_line_height(font);
}

point<int> Text::getSize() const noexcept {
	return {
		al_get_text_width(font, str.c_str()),
		al_get_font_line_height(font)
	};
}

rect<float> Text::getBounds() const noexcept {
	return {
		position.x, 
		position.y,
		(float) al_get_text_width(font, str.c_str()),
		(float) al_get_font_line_height(font)
	};
}

std::string Text::getString() const noexcept {
	return str;
}

ALLEGRO_FONT* Text::getFont() const noexcept {
	return font;
}

ALLEGRO_COLOR Text::getColor() const noexcept {
	return color;
}

point<float> Text::getPosition() const noexcept {
	return position;
}
