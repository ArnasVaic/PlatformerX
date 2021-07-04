#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Collision.h"
#include "Text.h"

struct Caret {

	size_t index = 0;
	point<float> position = { 0.0f, 0.0f };
	point<float> size = { 1.0f, 24.0f };
	ALLEGRO_COLOR color = al_map_rgb(20, 20, 20);

public:

	void update(Text const& text) noexcept;
	void draw() const noexcept;

	/// Setters
	void setIndex(size_t const index, Text const& text) noexcept;
	void setColor(ALLEGRO_COLOR color) noexcept;
	void setSize(point<float> const& size) noexcept;
	/// Getters
	size_t getIndex() const noexcept;
	point<float> getPostion() const noexcept;
	point<float> getSize() const noexcept;
	ALLEGRO_COLOR getColor() const noexcept;
};
