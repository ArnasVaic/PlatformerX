#include "Widget.h"

Widget::Widget() noexcept {

}

Widget::Widget(ALLEGRO_BITMAP* bitmap) noexcept :
bitmap(bitmap) {

}

Widget::Widget(
	point<float> position,
	ALLEGRO_BITMAP* bitmap
) noexcept :
position(position),
bitmap(bitmap) {

}


Widget::Widget(
	point<float> position,
	point<float> scale,
	ALLEGRO_BITMAP* bitmap
) noexcept :
position(position),
scale(scale),
bitmap(bitmap) {

}

void Widget::draw() const noexcept {
	// using this function to avoid the need t hold
	// useless info about bitmap, that is necessary
	// with al_draw_scaled_bitmap()
	al_draw_scaled_rotated_bitmap(
		bitmap,
		0.0f, 0.0f,
		position.x, position.y,
		scale.x, scale.y,
		0.0f,
		0
	);
}

rect<float> Widget::getBounds() const noexcept {
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);
	return { position.x, position.y, w * scale.x, h * scale.y };
}

point<float> Widget::getSize() const noexcept {
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);
	return {w * scale.x, h * scale.y };
}

point<float> Widget::getPosition() const noexcept {
	return position;
}

point<float> Widget::getScale() const noexcept {
	return scale;
}

ALLEGRO_BITMAP* Widget::getBitmap() const noexcept {
	return bitmap;
}

void Widget::setPosition(point<float> const& position) noexcept {
	this->position = position;
}

void Widget::setScale(point<float> const& scale) noexcept {
	this->scale = scale;
}

void Widget::setBitmap(ALLEGRO_BITMAP* bitmap) noexcept {
	this->bitmap = bitmap;
}
