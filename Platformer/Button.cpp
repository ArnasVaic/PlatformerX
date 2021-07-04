#include "Button.h"

Button::Button() noexcept {

}

Button::Button(
	std::string const& str,
	ALLEGRO_FONT* font,
	ALLEGRO_BITMAP* idle_bitmap,
	ALLEGRO_BITMAP* hover_bitmap
) noexcept :
label(str, font, idle_bitmap),
idle_bitmap(idle_bitmap),
hover_bitmap(hover_bitmap) {

}

void Button::setCallback(std::function<void()> callback) noexcept {
	this->callback = callback;
}

void Button::setReactButton(int const button) noexcept {
	this->react_button = button;
}


void Button::handleEvent(ALLEGRO_EVENT const& event) {
	if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
		point<float> p(event.mouse.x, event.mouse.y);
		rect<float> bounds = label.getWidget().getBounds();
		bool contains = point_in_rectangle(p, bounds);

		label.setBitmap(contains ? hover_bitmap : idle_bitmap);
	}
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		if (event.mouse.button == react_button) {
			point<float> p(event.mouse.x, event.mouse.y);
			rect<float> bounds = label.getWidget().getBounds();

			if (point_in_rectangle(p, bounds)) callback(); 
		}
	}
}

void Button::draw() const noexcept {
	label.draw();
}

void Button::setPosition(point<float> const& position) noexcept {
	label.setPosition(position);
}

void Button::setScale(point<float> const& scale) noexcept {
	label.setScale(scale);
}

void Button::setString(std::string const& str) noexcept {
	label.setString(str);
}

void Button::setFont(ALLEGRO_FONT* font) noexcept {
	label.setFont(font);
}

void Button::setTextColor(ALLEGRO_COLOR color) noexcept {
	label.setTextColor(color);
}

void Button::setIdleBitmap(ALLEGRO_BITMAP* idle_bitmap) noexcept {
	this->idle_bitmap = idle_bitmap;
}

void Button::setHoverBitmap(ALLEGRO_BITMAP* hover_bitmap) noexcept {
	this->hover_bitmap = hover_bitmap;
}

/// Getters
Label const& Button::getLabel() const noexcept {
	return label;
}

int Button::getReactButton() const noexcept {
	return react_button;
}

ALLEGRO_BITMAP* Button::getIdleBitmap() const noexcept {
	return idle_bitmap;
}

ALLEGRO_BITMAP* Button::getHoverBitmap() const noexcept {
	return hover_bitmap;
}

std::function<void()> Button::getCallback() const noexcept {
	return callback;
}
