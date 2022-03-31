//
// Created by abhilekh on 2022-03-30.
//

#ifndef SNAKE_WINDOW_H
#define SNAKE_WINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    Window(std::string l_title, sf::Vector2u l_size);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void update();
    bool isDone() const;
    bool isFullScreen() const;

    sf::Vector2u getWindowSize();
    sf::RenderWindow* getRenderWindow();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
private:
    void Setup(std::string l_title,
               sf::Vector2u l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone = true;
    bool m_isFullscreen = false;
};

#endif //SNAKE_WINDOW_H
