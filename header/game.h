//
// Created by abhilekh on 2022-03-30.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "../header/snake.h"
#include "../header/world.h"
#include "../header/window.h"

class Game
{
private:
    Window m_window;
    World m_world;
    Snake m_snake;

    sf::Clock m_clock;
    sf::Time m_elapsed;

public:
    Game();
    ~Game() = default;
    void update();
    void render();
    void HandleInput();
    void RestartClock();
    void run();

    sf::Time getElapsed() {return m_elapsed;}
};

#endif //SNAKE_GAME_H
