#include "MenuState.h"

MenuState::MenuState(ALLEGRO_DISPLAY* display, StateManager* manager) noexcept :
manager(manager), display(display) {
	button = Button("go to Game State");
	button.setScale({ 2, 2 });
	button.setPosition({ 16, 16 });
	button.setCallback([=]() {
		manager->activateState("game state");
	});
}

void MenuState::handleEvent(ALLEGRO_EVENT const& event) {
	button.handleEvent(event);
}

void MenuState::update(double const delta) {

}

void MenuState::draw() const noexcept {
	button.draw();
}
