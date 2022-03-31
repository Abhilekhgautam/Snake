//
// Created by abhilekh on 2022-03-30.
//

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include "../header/snake.h"


class World
{
public:
              World(sf::Vector2u l_windSize);
              ~World();

    int       getBlockSize();
    void      reSpawnApple();
    void      update(Snake&  l_player);
    void      render(sf::RenderWindow& l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int          m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];

};

#endif //SNAKE_WORLD_H
