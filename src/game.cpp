//
// Created by abhilekh on 2022-03-30.
//


#include "../header/game.h"

Game :: Game()
      :  m_window("Snake", sf::Vector2u(800,600)),m_snake(m_world.getBlockSize()),m_world(sf::Vector2u(800,600))
{

}

void Game :: run()
{
    while(!m_window.isDone())
    {
// Game loop.
        HandleInput();
        update();
        render();
        sf::sleep(sf::seconds(0.2));
        RestartClock();
    }
}



void Game::update()
{
    m_window.update();
    float fElapsed = getElapsed().asSeconds();
    float frameRate = 1.0f / 60.0f;

    if(m_elapsed.asSeconds() >= frameRate)
    {
        m_snake.Tick();
        m_world.update(m_snake);

        m_elapsed -= sf::seconds(frameRate);

        if(m_snake.hasLost())
        {
            m_snake.Reset();
        }
    }
}

void Game ::render()
{
    m_window.BeginDraw();
    m_world.render(*m_window.getRenderWindow());
    m_snake.Render(*m_window.getRenderWindow());

    m_window.EndDraw();
}

void Game ::HandleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
       && m_snake.getPhysicalDirection() != Direction::Down)
    {
        m_snake.setDirection(Direction::Up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
              && m_snake.getPhysicalDirection() != Direction::Up)
    {
        m_snake.setDirection(Direction::Down);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
              && m_snake.getPhysicalDirection() != Direction::Right)
    {
        m_snake.setDirection(Direction::Left);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
              && m_snake.getPhysicalDirection() != Direction::Left)
    {
        m_snake.setDirection(Direction::Right);
    }
}

void Game ::RestartClock()
{
    m_elapsed += m_clock.restart();
}

