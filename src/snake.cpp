//
// Created by abhilekh on 2022-03-26.
//

#include "../header/snake.h"

Snake ::Snake(int block_size)
{
    m_size = block_size;
    m_bodyRect.setSize(sf::Vector2f(m_size -1 , m_size -1));
    Reset();
}

void Snake :: Reset()
{
    m_snakeBody.clear();
    m_snakeBody.push_back(SnakeSegment(5,6));
    m_snakeBody.push_back(SnakeSegment(5,6));
    m_snakeBody.push_back(SnakeSegment(5,5));

    setDirection(Direction::None);
    m_speed = 15;
    m_lives = 3;
    m_score = 0;

    m_lost = false;
}

void Snake :: setDirection(Direction dir)
{
    m_dir = dir;
}

Direction Snake ::getDirection()
{
    return m_dir;
}

int Snake ::getSpeed()
{
    return m_speed;
}

sf::Vector2i Snake :: getPosition()
{
    return (!m_snakeBody.empty() ? m_snakeBody.front().Position : sf::Vector2i(1,1));
}

int Snake ::getLives()
{
    return m_lives;
}

int Snake :: getScore()
{
    return m_score;
}

void Snake ::increaseScore()
{
    m_score += 10;
}

bool Snake ::hasLost()
{
    return m_lost;
}

void Snake::Lose()
{
    m_lost = true;
}

void Snake ::ToggleLost()
{
    m_lost = !m_lost;
}

void Snake ::Extend()
{
    if(m_snakeBody.empty()){return;}

    SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];

    if (m_snakeBody.size() > 1)
    {
        SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];

        if(tail_head.Position.x == tail_bone.Position.x)
        {
            if(tail_head.Position.y > tail_bone.Position.y)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x, tail_head.Position.y + 1));

            }
            else
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x,tail_head.Position.y - 1));

            }

        }
        else if(tail_head.Position.y == tail_bone.Position.y)
        {
            if(tail_head.Position.x > tail_bone.Position.x)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x + 1, tail_head.Position.y));
            }
            else
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x - 1, tail_head.Position.y));
            }
        }
        else
        {
            if(m_dir == Direction::Up)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x, tail_head.Position.y + 1));
            }
            else if(m_dir == Direction::Down)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x, tail_head.Position.y - 1));
            }
            else if(m_dir == Direction::Right)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x - 1, tail_head.Position.y));
            }
            else if(m_dir == Direction::Left)
            {
                m_snakeBody.push_back(SnakeSegment(tail_head.Position.x + 1 , tail_head.Position.y));
            }

        }

    }
}

void Snake :: Tick()
{
    if(m_snakeBody.empty()){return;}

    if(m_dir == Direction::None){return;}

    Move();
    checkCollision();
}

void Snake :: Move()
{
    for(int i = m_snakeBody.size() - 1 ; i > 0 ; --i)
    {
        m_snakeBody[i].Position = m_snakeBody[i - 1].Position;
    }

    if(m_dir == Direction::Left)
    {
        --m_snakeBody[0].Position.x;
    }
    else if(m_dir == Direction :: Right)
    {
        ++m_snakeBody[0].Position.x;
    }
    else if(m_dir == Direction :: Up)
    {
        --m_snakeBody[0].Position.y;
    }
    else if(m_dir == Direction::Down)
    {
        ++m_snakeBody[0].Position.y;
    }
}

void Snake::checkCollision()
{
    if(m_snakeBody.size() < 5) {return;}

    SnakeSegment& head = m_snakeBody.front();

    for(auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr )
    {
        if(itr->Position == head.Position)
        {
            int segments = m_snakeBody.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake :: Cut(int l_segments)
{
    for(int i = 0; i < l_segments ; ++i)
    {
        m_snakeBody.pop_back();
    }
    --m_lives;
    if(!m_lives)
    {
        Lose();
        return;
    }
}

void Snake ::Render(sf::RenderWindow &window)
{
    if(m_snakeBody.empty()) {return;}

    auto head = m_snakeBody.begin();
    m_bodyRect.setFillColor(sf::Color::Yellow);
    m_bodyRect.setPosition(head->Position.x * m_size, head->Position.y * m_size);

    window.draw(m_bodyRect);

    m_bodyRect.setFillColor(sf::Color::Green);
    for(auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++ itr)
    {
        m_bodyRect.setPosition(itr -> Position.x * m_size, itr->Position.y * m_size);
        window.draw(m_bodyRect);
    }
}

Direction Snake ::getPhysicalDirection()
{
    if(m_snakeBody.size() <= 1)
        return (Direction :: None);

    const SnakeSegment& head = m_snakeBody[0];
    const SnakeSegment& neck = m_snakeBody[1];

    if(head.Position.x == neck.Position.x)
    {
        return (head.Position.y > neck.Position.y ? Direction :: Down : Direction :: Up);
    }
    else if(head.Position.y == neck.Position.y)
    {
        return (head.Position.x > neck.Position.x ? Direction :: Right : Direction :: Left);
    }

    return Direction :: None;
}





