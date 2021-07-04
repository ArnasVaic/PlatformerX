#include "Label.h"

Label::Label(
	std::string str,
	ALLEGRO_FONT* font,
	ALLEGRO_BITMAP* bitmap
) noexcept :
text(str, font),
widget(bitmap) {
	this->centerText();
}

void Label::draw() const noexcept {
	widget.draw();
	text.draw();
}

void Label::centerText() noexcept {
	rect<float> w = widget.getBounds();
	point<int> t = text.getSize();
	text.setPosition({
		w.x + (w.w - t.x) / 2.0f,
		w.y + (w.h - t.y) / 2.0f
	});
}

void Label::setPosition(point<float> const& position) noexcept {
	widget.setPosition(position);
	this->centerText();
}

void Label::setScale(point<float> const& scale) noexcept {
	widget.setScale(scale);
	this->centerText();
}

void Label::setBitmap(ALLEGRO_BITMAP* bitmap) noexcept {
	widget.setBitmap(bitmap);
	this->centerText();
}

void Label::setString(std::string const& str) noexcept {
	text.setString(str);
	this->centerText();
}

void Label::setFont(ALLEGRO_FONT* font) noexcept {
	text.setFont(font);
	this->centerText();
}

void Label::setTextColor(ALLEGRO_COLOR color) noexcept {
	text.setColor(color);
}

Widget const& Label::getWidget() noexcept {
	return widget;
}

Text const& Label::getText() noexcept {
	return text;
}