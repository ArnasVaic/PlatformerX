#pragma once

#include <allegro5/allegro.h>

struct Camera {
	float x, y;
	ALLEGRO_TRANSFORM transform;

	Camera() noexcept;
	Camera(float x, float y) noexcept;
	void move(float dx, float dy) noexcept;
	void setTarget(float nx, float ny) noexcept;
};