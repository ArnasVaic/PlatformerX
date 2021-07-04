#pragma once

#include <allegro5/allegro.h>

struct Constants {
	
	static Constants& get() {
		static Constants c;
		return c;
	}

	ALLEGRO_TRANSFORM identity_transform;

private:

	inline Constants() noexcept {
		al_identity_transform(&identity_transform);
	}
};