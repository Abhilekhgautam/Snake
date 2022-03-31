//
// Created by abhilekh on 2022-03-30.
//

#include "../header/window.h"

Window::Window(){ Setup("Window", sf::Vector2u(640,480)); }
Window::Window(std::string l_title, sf::Vector2u l_size)
{
    Setup(l_title,l_size);
}
Window::~Window(){ Destroy(); }

void Window::Setup(std::string l_title,sf::Vector2u l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    Create();
}

void Window::Create(){
    auto style = (m_isFullscreen ? sf::Style::Fullscreen
                                 : sf::Style::Default);
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 },
                    m_windowTitle, style);
}
void Window::Destroy(){
    m_window.close();
}

void Window::update() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        } else if (event.type == sf::Event::KeyPressed &&
                   event.key.code == sf::Keyboard::F5) {
            ToggleFullscreen();
        }
    }
}

void Window::ToggleFullscreen()
{
          m_isFullscreen = !m_isFullscreen;
          Destroy();
          Create();
}

sf::RenderWindow* Window::getRenderWindow() {return &m_window;}


bool Window::isDone() const {return m_isDone;}
bool Window::isFullScreen() const {return m_isFullscreen;}
void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }
void Window::EndDraw(){ m_window.display(); }





