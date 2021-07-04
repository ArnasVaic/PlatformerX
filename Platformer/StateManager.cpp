#include "StateManager.h"

StateManager::StateManager() :
active_state(nullptr){

}

void StateManager::handleEvent(ALLEGRO_EVENT const& event) {
	active_state->handleEvent(event);
}

void StateManager::update(double const delta) {
	active_state->update(delta);
}

void StateManager::draw() const noexcept {
	active_state->draw();
}


void StateManager::addState(std::string const& state_name, std::shared_ptr<State> state_ptr) {
	states[state_name] = state_ptr;
}

void StateManager::activateState(std::string const& state_name) {
	active_state = states[state_name];
}

std::shared_ptr<State> StateManager::getState(std::string const& state_name) {
	return states[state_name];
}
