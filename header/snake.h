//
// Created by abhilekh on 2022-03-26.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>

struct SnakeSegment
{
    SnakeSegment(int x, int y) : Position(x,y){}
    sf::Vector2i Position;

};

using SnakeContainer = std::vector<SnakeSegment>;

enum Direction {None, Up ,Down, Right, Left};

class Snake
{
public:
    explicit Snake(int block_size);
    ~Snake() = default;

    void          setDirection(Direction dir);
    Direction     getDirection();
    int           getSpeed();
    sf::Vector2i  getPosition();
    int           getLives();
    int           getScore();
    void          increaseScore();
    bool          hasLost();

    void          Lose();
    void          ToggleLost();

    void          Extend();
    void          Reset();

    void          Move();
    void          Tick();
    void          Cut(int segments);

    void          Render(sf::RenderWindow& window);
    Direction     getPhysicalDirection();


private:
    void          checkCollision();

    SnakeContainer m_snakeBody;
    int            m_size;
    Direction      m_dir;
    int            m_speed;
    int            m_lives;
    int            m_score;
    bool           m_lost;
    sf::RectangleShape m_bodyRect;

};




#endif //SNAKE_SNAKE_H
