#pragma once

#include <allegro5/allegro.h>

#include "StateManager.h"
#include "State.h"
#include "GUI.h"

class MenuState : public State {

	StateManager* manager;
	ALLEGRO_DISPLAY* display;
	Button button;

public:
	MenuState(ALLEGRO_DISPLAY* display, StateManager* manager) noexcept;

	void handleEvent(ALLEGRO_EVENT const& event) override;
	void update(double const delta) override;
	void draw() const noexcept override;
};