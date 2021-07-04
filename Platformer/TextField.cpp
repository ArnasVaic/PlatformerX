#include "TextField.h"

TextField::TextField(
	std::string const& placeholder_text,
	ALLEGRO_FONT* font,
	ALLEGRO_BITMAP* idle_bitmap,
	ALLEGRO_BITMAP* selected_bitmap
) noexcept :
idle_bitmap(idle_bitmap),
selected_bitmap(selected_bitmap),
placeholder_text(placeholder_text),
label(placeholder_text, font, idle_bitmap) {
	caret.setIndex(0, label.getText());
}

void TextField::update() noexcept {
	if (selected) {
		label.setBitmap(selected_bitmap);
		draw_caret = true;
	}
	else {
		label.setBitmap(idle_bitmap);
		draw_caret = false;

		if (input_text.size() > 0) {
			size_t spaces = 0;
			for (size_t i = 0; i < input_text.size(); i++) {
				if (input_text[i] == ' ') spaces++;
			}
			if (spaces == input_text.size()) {
				caret.setIndex(0, label.getText());
				input_text.clear();
				label.setString(input_text);
			}
		}
	}
	label.centerText();
}

void TextField::handleEvent(ALLEGRO_EVENT const& event) {
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		if (event.mouse.button == react_button) {
			point<float> p(event.mouse.x, event.mouse.y);
			rect<float> bounds = label.getWidget().getBounds();
			selected = point_in_rectangle(p, bounds);
		}
	}
	// text input
	if (selected) {
		if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
			const int keycode = event.keyboard.keycode;

			/// Deselect the text field
			if (keycode == ALLEGRO_KEY_ENTER) selected = false;

			/// Move caret to the right
			else if (keycode == ALLEGRO_KEY_RIGHT) {
				if (caret.index < input_text.size()) caret.index++;
			}

			/// Move caret to the left
			else if (keycode == ALLEGRO_KEY_LEFT) {
				if (caret.index > 0) caret.index--;
			}

			/// Remove character before caret
			else if (keycode == ALLEGRO_KEY_BACKSPACE) {
				if (input_text.size() > 0 && caret.index > 0) {
					caret.index--;
					input_text.erase(caret.index, 1);
					// store new str in the label text
					// because caret.update() checks the label string
					label.setString(input_text);
				}
			}

			/// Remove character at caret
			else if (keycode == ALLEGRO_KEY_DELETE) {
				if (input_text.size() > 0)  {
					input_text.erase(caret.index, 1);
				}
			}

			/// Add character to our string
			else if(input_text.size() < max_length) {
				input_text.insert(caret.index, 1, event.keyboard.unichar);
				// store new str in the label text
				// because caret.update() checks the label string
				label.setString(input_text);
				caret.index++;
			}
		}

		label.centerText();
		caret.update(label.getText());
	}


	bool empty = (input_text.size() == 0);
	// if string has characters
	// it is possible that they are all spaces
	// check and if so, clear the whole string
	
	// set the label text accordingly
	if (selected) {
		label.setString(input_text);
		label.setTextColor(input_color);
	}
	else { 
		if (empty)  {
			label.setString(placeholder_text);
			label.setTextColor(placeholder_color);
		}
	}

	this->update();
}

void TextField::draw() const noexcept {
	label.draw();
	if(draw_caret) caret.draw();
}

void TextField::setReactButton(int const button) noexcept {
	this->react_button = button;
}

void TextField::setPosition(point<float> const& position) noexcept {
	label.setPosition(position);
	caret.update(label.getText());
}

void TextField::setScale(point<float> const& scale) noexcept {
	label.setScale(scale);
	caret.update(label.getText());
}

void TextField::setFont(ALLEGRO_FONT* font) noexcept {
	label.setFont(font);
	label.centerText();
}

void TextField::setIdleBitmap(ALLEGRO_BITMAP* idle_bitmap) noexcept {
	this->idle_bitmap = idle_bitmap;
}

void TextField::setSelectedBitmap(ALLEGRO_BITMAP* selected_bitmap) noexcept {
	this->selected_bitmap = selected_bitmap;
}


void TextField::setInputTextString(std::string const& str) noexcept {
	input_text = str;
}

void TextField::setInputTextColor(ALLEGRO_COLOR color) noexcept {
	input_color = color;
}

void TextField::setPlaceholderTextString(std::string const& str) noexcept {
	placeholder_text = str;
}

void TextField::setPlaceholderTextColor(ALLEGRO_COLOR color) noexcept {
	placeholder_color = color;
}

void TextField::setMaxTextLength(size_t const length) noexcept {
	max_length = length;
}


/// Getters
Caret const& TextField::getCaret() const noexcept {
	return caret;
}

Label const& TextField::getLabel() const noexcept {
	return label;
}

int TextField::getReactButton() const noexcept {
	return react_button;
}

ALLEGRO_BITMAP* TextField::getIdleBitmap() const noexcept {
	return idle_bitmap;
}

ALLEGRO_BITMAP* TextField::getSelectedBitmap() const noexcept {
	return selected_bitmap;
}

size_t TextField::getMaxTextLength() const noexcept {
	return max_length;
}

bool TextField::isSelected() const noexcept {
	return selected;
}

std::string TextField::getInputTextString() const noexcept {
	return input_text;
}

ALLEGRO_COLOR TextField::getInputTextColor() const noexcept {
	return input_color;
}

std::string TextField::getPlaceholderTextString() const noexcept {
	return placeholder_text;
}

ALLEGRO_COLOR TextField::getPlaceholderTextColor() const noexcept {
	return placeholder_color;
}
