#include "GameState.h"

GameState::GameState(ALLEGRO_DISPLAY* display, StateManager* manager) noexcept :
manager(manager), display(display) {
	button = Button("go to Menu State");
	button.setScale({ 2, 2 });
	button.setPosition({ 256, 256 });
	button.setCallback([=]() {
		manager->activateState("menu state");
	});
	button.setTextColor(al_map_rgb(255, 150, 150));
}

void GameState::handleEvent(ALLEGRO_EVENT const& event) {
	button.handleEvent(event);
}

void GameState::update(double const delta) {

}

void GameState::draw() const noexcept {
	button.draw();
}
