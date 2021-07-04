#pragma once

#include <allegro5/allegro.h>

#include <iostream>

#include "TextField.h"
#include "Player.h"
#include "Camera.h"
#include "Sprite.h"
#include "Button.h"
#include "Assets.h"
#include "Label.h"

class Game {

    ALLEGRO_DISPLAY* display = nullptr;
    int width, height;
   
    Player p;
    Sprite q;
    Camera c;

    Label label;
    Button button;
    TextField field;

public:

    Game(ALLEGRO_DISPLAY* display) noexcept;
    void handleEvent(ALLEGRO_EVENT& event) noexcept;
    void update(ALLEGRO_EVENT& event, double const delta) noexcept;
    void draw() noexcept;
    void free() noexcept;
        
};