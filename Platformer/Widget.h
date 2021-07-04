#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include "Constants.h"
#include "Collision.h"

class Widget {

	point<float> position;
	point<float> scale		= { 1.0f, 1.0f };
	ALLEGRO_BITMAP* bitmap	= nullptr;
public:
	Widget() noexcept;

	Widget(ALLEGRO_BITMAP* bitmap) noexcept;

	Widget(
		point<float> position,
		ALLEGRO_BITMAP* bitmap
	) noexcept;

	Widget(
		point<float> position,
		point<float> scale,
		ALLEGRO_BITMAP* bitmap
	) noexcept;

	void draw() const noexcept;

	/// Setters
	void setPosition(point<float> const& position) noexcept;
	void setScale(point<float> const& scale) noexcept;
	void setBitmap(ALLEGRO_BITMAP* bitmap) noexcept;

	/// Getters
	rect<float> getBounds() const noexcept;
	point<float> getSize() const noexcept;
	point<float> getPosition() const noexcept;	
	point<float> getScale() const noexcept;
	ALLEGRO_BITMAP* getBitmap() const noexcept;
};