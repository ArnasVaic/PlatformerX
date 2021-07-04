#pragma once

#include "Assets.h"
#include "Widget.h"
#include "Text.h"

class Label {
	Widget widget;
	Text text;
public:
	Label(
		std::string		str		= "",
		ALLEGRO_FONT*	font	= Assets::get().default_font,
		ALLEGRO_BITMAP* bitmap	= Assets::get().widget_idle
	) noexcept;

	void draw() const noexcept;

	void centerText() noexcept;

	/// Setters
	void setPosition(point<float> const& position) noexcept;
	void setScale(point<float> const& scale) noexcept;
	void setBitmap(ALLEGRO_BITMAP* background) noexcept;
	void setString(std::string const& str) noexcept;
	void setFont(ALLEGRO_FONT* font) noexcept;
	void setTextColor(ALLEGRO_COLOR color) noexcept;

	/// Getters 
	Widget const& getWidget() noexcept;
	Text const& getText() noexcept;
};
