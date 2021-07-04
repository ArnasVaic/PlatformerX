#pragma once

#include "Caret.h"
#include "Assets.h"
#include "Input.h"
#include "Label.h"

class TextField {
	Caret caret;
	Label label;

	std::string input_text = "";
	ALLEGRO_COLOR input_color = al_map_rgb(255, 255, 255);

	std::string placeholder_text;
	ALLEGRO_COLOR placeholder_color = al_map_rgb(200, 200, 200);

	size_t max_length = 16;

	ALLEGRO_BITMAP* idle_bitmap;
	ALLEGRO_BITMAP* selected_bitmap;

	int react_button = Input::LEFT_MOUSE_BUTTON;

	bool selected = false;
	bool draw_caret = false;

public:
	TextField(
		std::string const& placeholder_text = "",
		ALLEGRO_FONT* font					= Assets::get().default_font,
		ALLEGRO_BITMAP* idle_bitmap			= Assets::get().widget_idle,
		ALLEGRO_BITMAP* selected_bitmap		= Assets::get().widget_selected
	) noexcept;

	void update() noexcept;

	void handleEvent(ALLEGRO_EVENT const& event);
	void draw() const noexcept;

	/// Setters
	void setReactButton(int const button) noexcept;
	void setPosition(point<float> const& position) noexcept;
	void setScale(point<float> const& scale) noexcept;
	void setFont(ALLEGRO_FONT* font) noexcept; 

	void setIdleBitmap(ALLEGRO_BITMAP* idle_bitmap) noexcept;
	void setSelectedBitmap(ALLEGRO_BITMAP* selected_bitmap) noexcept;

	void setInputTextString(std::string const& str) noexcept;
	void setInputTextColor(ALLEGRO_COLOR color) noexcept;
	void setPlaceholderTextString(std::string const& str) noexcept;
	void setPlaceholderTextColor(ALLEGRO_COLOR color) noexcept;
	void setMaxTextLength(size_t const length) noexcept;

	/// Getters
	Caret const& getCaret() const noexcept;
	Label const& getLabel() const noexcept;
	int getReactButton() const noexcept;
	ALLEGRO_BITMAP* getIdleBitmap() const noexcept;
	ALLEGRO_BITMAP* getSelectedBitmap() const noexcept;
	size_t getMaxTextLength() const noexcept;
	bool isSelected() const noexcept;
	std::string getInputTextString() const noexcept;
	ALLEGRO_COLOR getInputTextColor() const noexcept;
	std::string getPlaceholderTextString() const noexcept;
	ALLEGRO_COLOR getPlaceholderTextColor() const noexcept;
};
