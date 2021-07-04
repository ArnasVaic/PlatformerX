#include "Animation.h"

Animation::Animation(
	int const count_x,
	int const count_y,
	Sprite& sprite
) noexcept :
count_x(count_x),
count_y(count_y),
w(al_get_bitmap_width(sprite.bitmap) / count_x),
h(al_get_bitmap_height(sprite.bitmap) / count_y) {
	sprite.tw = w;
	sprite.th = h;
}

void Animation::play(
	int const row,
	double const delta,
	double const time_per_frame,
	Sprite& sprite
) noexcept {
	this->row = row;
	timer += delta;
	// increment frame
	if (timer >= time_per_frame) {
		frame++;
		if (frame == count_x) frame = 0;
		timer = 0;
	}
	sprite.tx = w * frame;
	sprite.ty = h * row;
}