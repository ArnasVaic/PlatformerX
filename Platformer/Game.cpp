#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) noexcept :
    display(display) {
    width = al_get_display_width(display);
    height = al_get_display_height(display);

    p = Player(96.0f, -128.0f, Assets::get().player_sheet, 12, 4);
    q = Sprite(0, 0, 4.0f, 4.0f, Assets::get().bitmap);
    c = Camera(0, 0);

    label = Label("Label:)");
    label.setScale({ 2.0f, 2.0f });
    label.setPosition({ 16.0f, 16.0f });
    label.setString("This is a label:)");

    button = Button("Button:)");
    button.setScale({ 2.0f, 2.0f });
    button.setPosition({ 16.0f, 64.0f });
    button.setString("This is a button:)");
    button.setReactButton(Input::RIGHT_MOUSE_BUTTON);
    button.setCallback([]() {
        std::cout << "This button has been pressed!\n";
    });

    field = TextField("Field:)");
    field.setScale({ 2.0f, 2.0f });
    field.setPosition({ 16.0f, 112.0f });
}

void Game::handleEvent(ALLEGRO_EVENT& event) noexcept {
    p.handleInput(event);
    button.handleEvent(event);
    field.handleEvent(event);
}

void Game::update(ALLEGRO_EVENT& event, double const delta) noexcept {
    p.update(delta);
    c.setTarget(
        (width  - p.sprite.tw * p.sprite.sx) / 2.0f - p.sprite.x,
        (height - p.sprite.th * p.sprite.sy) / 2.0f - p.sprite.y
    );
}

void Game::draw() noexcept {
    p.draw(c.transform);
    q.draw(c.transform);
    label.draw();
    button.draw();
    field.draw();
}

void Game::free() noexcept {
    
}