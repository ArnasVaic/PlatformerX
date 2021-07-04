#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include "Sprite.h"

class Animation {
public:
	// sprite count
	int count_x = 1, count_y = 1;
	// tracks time obviously
	double timer = 0;
	// collumn and row indices
	int frame = 0, row = 0;
	// region width & height 
	int w = 0, h = 0; 

	constexpr Animation() noexcept { }

	Animation(
		int const count_x, 
		int const count_y, 
		Sprite& sprite
	) noexcept;

	void play(
		int const row,
		double const delta,
		double const time_per_frame,
		Sprite& sprite
	) noexcept;
};