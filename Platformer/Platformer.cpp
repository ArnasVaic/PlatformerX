#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "StateManager.h"
#include "GameState.h"
#include "MenuState.h"

#include "Constants.h"
#include "Assets.h"
#include "Input.h"

int main() {

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();

    const int width = 1080, height = 768;

    ALLEGRO_DISPLAY* display = al_create_display(width, height);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    al_install_keyboard();
    ALLEGRO_EVENT_SOURCE* keyboard_source = al_get_keyboard_event_source();
    al_register_event_source(queue, keyboard_source);

    al_install_mouse();
    ALLEGRO_EVENT_SOURCE* mouse_source = al_get_mouse_event_source();
    al_register_event_source(queue, mouse_source);

    ALLEGRO_EVENT_SOURCE* dispaly_source = al_get_display_event_source(display);
    al_register_event_source(queue, dispaly_source);

    const double FPS = 144.0;
    ALLEGRO_TIMER* clock = al_create_timer(1 / FPS);
    al_register_event_source(queue, al_get_timer_event_source(clock));
    al_start_timer(clock);

    bool running = true;

    long last_time = al_get_timer_count(clock);
    long delta = 0;
    int timer = last_time;
    bool draw = false;

    //Game game(display);
    StateManager state_manager;
    state_manager.addState(
        "game state", 
        std::make_shared<GameState>(display, &state_manager)
    );

    state_manager.addState(
        "menu state", 
        std::make_shared<MenuState>(display, &state_manager)
    );

    state_manager.activateState("menu state");

    while (running) {
        // update time
        long now = al_get_timer_count(clock);
        delta += now - last_time;
        last_time = now;

        // handle events
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        
        if (event.type == ALLEGRO_EVENT_TIMER) draw = true;
        //game.handleEvent(event);
        state_manager.handleEvent(event);
        Input::get().handleEvent(event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = false;
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) running = false;
        }

        // update game logic
        while (delta >= 1) {
            //game.update(event, delta);
            state_manager.update(delta);
            delta--;
        }

        // Draw
        if (draw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(20, 20, 20));
            //game.draw();
            state_manager.draw();
            al_flip_display();
            draw = false;
        }
    }

    //game.free();

    al_destroy_event_queue(queue);
    al_destroy_timer(clock);
    al_destroy_display(display);

    al_uninstall_keyboard();
    al_uninstall_mouse();
}