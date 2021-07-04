#pragma once

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Constants.h"
#include "Animation.h"
#include "Sprite.h"
#include "Input.h"

struct Player {
	Sprite sprite;
	// velocity
	float vx = 0, vy = 0;	
	bool rotate = false;
	Animation animation;
	int row = 0;

	Player() noexcept;

	Player(
		float const x,
		float const y, 
		ALLEGRO_BITMAP* bitmap,
		uint32_t count_x, 
		uint32_t count_y
	) noexcept;

	void handleInput(ALLEGRO_EVENT const& event);
	void update(double const delta);
	void draw();
	void draw(ALLEGRO_TRANSFORM &transform);
};
