#include "Caret.h"

void Caret::update(Text const& text) noexcept {
	int x_offset = al_get_text_width(
		text.getFont(),
		text.getString().substr(0, index).c_str()
	);
	auto t_size = text.getSize();
	position.x = text.getPosition().x + x_offset;
	position.y = text.getPosition().y + (t_size.y - size.y) / 2.0f;
}

void Caret::draw() const noexcept {
	al_draw_filled_rectangle(
		position.x, position.y,
		position.x + size.x, position.y + size.y,
		color
	);
}

void Caret::setIndex(size_t const index, Text const& text) noexcept {
	this->index = index;
	update(text);
}

void Caret::setColor(ALLEGRO_COLOR color) noexcept {
	this->color = color;
}

void Caret::setSize(point<float> const& size) noexcept {
	this->size = size;
}

/// Getters
size_t Caret::getIndex() const noexcept {
	return index;
}

point<float> Caret::getPostion() const noexcept {
	return position;
}

point<float> Caret::getSize() const noexcept {
	return size;
}

ALLEGRO_COLOR Caret::getColor() const noexcept {
	return color;	
}
