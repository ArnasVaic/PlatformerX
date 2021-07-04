#include "Player.h"

Player::Player() noexcept  {

}

Player::Player(
	float const x,
	float const y,
	ALLEGRO_BITMAP* bitmap,
	uint32_t count_x,
	uint32_t count_y) noexcept {
	sprite = Sprite(x, y, 4.0f, 4.0f, bitmap);
	animation = Animation(count_x, count_y, sprite);
}

void Player::handleInput(ALLEGRO_EVENT const& event) {
	ALLEGRO_KEYBOARD_STATE state;
	al_get_keyboard_state(&state);
	
	vx = vy = row = 0;
	if (Input::get().isKeyHeld(ALLEGRO_KEY_D)) {
		vx = 1;
		row = 1;
	}
	if (Input::get().isKeyHeld(ALLEGRO_KEY_A)) {
		vx = -1;
		row = 2;
	}
}

void Player::update(double const delta) {
	sprite.x += delta * vx;
	sprite.y += delta * vy;
	animation.play(row, delta, 10, sprite);
}

void Player::draw(ALLEGRO_TRANSFORM &transform) {
	sprite.draw(transform);
}

void Player::draw() {
	sprite.draw();
}