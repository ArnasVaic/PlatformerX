#pragma once

#include <allegro5/allegro.h>

class State {
public:
	virtual void handleEvent(ALLEGRO_EVENT const& event) = 0;
	virtual void update(double const delta) = 0;
	virtual void draw() const noexcept = 0;
};
