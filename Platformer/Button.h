#pragma once

#include <allegro5/allegro_font.h>

#include <functional>
#include <string>

#include "Collision.h"
#include "Assets.h"
#include "Label.h"
#include "Input.h"


class Button {
	Label label;
	std::function<void()> callback = [](){};
	int react_button = Input::LEFT_MOUSE_BUTTON;
	ALLEGRO_BITMAP* idle_bitmap	= nullptr;
	ALLEGRO_BITMAP* hover_bitmap = nullptr;

public:

	Button() noexcept;

	Button(
		std::string const& str,
		ALLEGRO_FONT* font = Assets::get().default_font,
		ALLEGRO_BITMAP* idle_bitmap = Assets::get().widget_idle,
		ALLEGRO_BITMAP* hover_bitmap = Assets::get().widget_selected
	) noexcept;

	

	// GUI related
	void handleEvent(ALLEGRO_EVENT const& event);
	void draw() const noexcept;

	/// Setters
	void setCallback(std::function<void()> callback) noexcept;
	void setReactButton(int const button) noexcept;
	void setPosition(point<float> const& position) noexcept;
	void setScale(point<float> const& scale) noexcept;
	void setString(std::string const& str) noexcept;
	void setFont(ALLEGRO_FONT* font) noexcept;
	void setTextColor(ALLEGRO_COLOR color) noexcept;
	void setIdleBitmap(ALLEGRO_BITMAP* idle_bitmap) noexcept;
	void setHoverBitmap(ALLEGRO_BITMAP* hover_bitmap) noexcept;

	/// Getters
	Label const& getLabel() const noexcept;
	int getReactButton() const noexcept;
	ALLEGRO_BITMAP* getIdleBitmap() const noexcept;
	ALLEGRO_BITMAP* getHoverBitmap() const noexcept;
	std::function<void()> getCallback() const noexcept;
};