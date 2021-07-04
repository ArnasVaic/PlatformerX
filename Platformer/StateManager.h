#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "State.h"

class StateManager {
	std::unordered_map<std::string, std::shared_ptr<State>> states;
	std::shared_ptr<State> active_state;
public:
	StateManager();

	void handleEvent(ALLEGRO_EVENT const& event);
	void update(double const delta);
	void draw() const noexcept;

	void addState(std::string const& state_name, std::shared_ptr<State> state_ptr);
	void activateState(std::string const& state_name);
	std::shared_ptr<State> getState(std::string const& state_name);
};
