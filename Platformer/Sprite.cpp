#include "Sprite.h"

Sprite::Sprite() noexcept {

}

Sprite::Sprite(
	float x, float y,
	ALLEGRO_BITMAP* bitmap
) noexcept :
x(x), 
y(y),
tw(al_get_bitmap_width(bitmap)), 
th(al_get_bitmap_height(bitmap)),
bitmap(bitmap) {
	if (bitmap == NULL) std::cerr << "Sprite created with NULL bitmap\n";
}

Sprite::Sprite(
	float x, float y,
	float sx, float sy,
	ALLEGRO_BITMAP* bitmap
) noexcept : 
x(x), 
y(y), 
sx(sx),
sy(sy),
tw(al_get_bitmap_width(bitmap)),
th(al_get_bitmap_height(bitmap)),
bitmap(bitmap) {
	if (bitmap == NULL) std::cerr << "Sprite created with NULL bitmap\n";
}

void Sprite::draw(ALLEGRO_TRANSFORM& transform) const noexcept {
	al_use_transform(&transform);
	al_draw_tinted_scaled_rotated_bitmap_region(
		bitmap,
		tx, ty, tw, th,
		color,
		cx, cy,
		x, y,
		sx, sy,
		angle,
		0
	);
	al_use_transform(&Constants::get().identity_transform);
}

void Sprite::draw() const noexcept {
	al_draw_tinted_scaled_rotated_bitmap_region(
		bitmap,
		tx, ty, tw, th,
		color,
		cx, cy,
		x, y,
		sx, sy,
		angle,
		0
	);
}

float Sprite::getWidth() const noexcept {
	return tw * sx;
}

float Sprite::getHeight() const noexcept {
	return th * sy;
}