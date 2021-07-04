#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include "Constants.h"

class Sprite {
	public:
	// sprite position 
	float x = 0.0f, y = 0.0f;
	// center coordinates
	float cx = 0.0f, cy = 0.0f;
	// rotation angle
	float angle = 0.0f;
	// texture rectangle coordinates
	int tx = 0, ty = 0;
	int tw = 0, th = 0;
	// scale
	float sx = 1.0f, sy = 1.0f;
	// color
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	// texture
	ALLEGRO_BITMAP* bitmap = nullptr;

	Sprite() noexcept;
	Sprite(float x, float y, ALLEGRO_BITMAP* bitmap) noexcept;
	Sprite(float x, float y, float sx, float sy, ALLEGRO_BITMAP* bitmap) noexcept;

	void draw() const noexcept;
	void draw(ALLEGRO_TRANSFORM& transform) const noexcept;

	float getWidth() const noexcept;
	float getHeight() const noexcept;
};