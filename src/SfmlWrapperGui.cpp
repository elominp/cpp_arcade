/*
** SfmlWrapperGui.cpp for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/graphicLib/SfmlWrapperGui
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Tue Mar 29 10:10:20 2016 pyre
** Last update Thu Mar 31 10:00:44 2016 pyre
*/

#include "SfmlWrapperGui.hh"

SfmlWrapperGui::SfmlWrapperGui()
{
  sf::Color color(254, 0, 254, 0);
  _window = new sf::RenderWindow(sf::VideoMode(MAP_WIDTH * CASE, MAP_HEIGHT * CASE), "SFML");
  _window->clear(sf::Color(254, 0, 254, 0));
  _image = new sf::Image();
  _image->create(MAP_WIDTH * CASE, MAP_HEIGHT * CASE, color);
  initEventTypes();
}

SfmlWrapperGui::~SfmlWrapperGui()
{
  _window->close();
  delete _window;
}

void SfmlWrapperGui::initEventTypes()
{
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Left, AEvents::LEFT_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Right, AEvents::RIGHT_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Up, AEvents::UP_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Down, AEvents::DOWN_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Q, AEvents::LEFT_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::D, AEvents::RIGHT_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Z, AEvents::UP_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::S, AEvents::DOWN_ARROW));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Space, AEvents::SPACE));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Escape, AEvents::ESCAPE));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Return, AEvents::ENTER));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::BackSpace, AEvents::BACKSPACE));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num4, AEvents::PREVIOUS_GAME));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num5, AEvents::NEXT_GAME));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num2, AEvents::PREVIOUS_GRAPHIC));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num3, AEvents::NEXT_GRAPHIC));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num8, AEvents::RESTART_GAME));
  _eventKeyboard.insert(std::pair<int, int> (sf::Keyboard::Num9, AEvents::MENU));

  _eventMouse.insert(std::pair<int, int> (sf::Mouse::Left, AEvents::LEFT_CLICK));
  _eventMouse.insert(std::pair<int, int> (sf::Mouse::Right, AEvents::RIGHT_CLICK));
  _eventMouse.insert(std::pair<int, int> (sf::Mouse::Middle, AEvents::MIDDLE_CLICK));
}

void SfmlWrapperGui::drawPixel(const Point<int> &position, const Color<unsigned char> &color)
{
  sf::Color sfcolor(color.getRed(), color.getGreen(), color.getBlue());
  _image->setPixel(position.getX() * CASE, position.getY() * CASE, sfcolor);
}

void SfmlWrapperGui::drawBuffer(Point<int> const &position, Buffer<unsigned char> const &buffer)
{
  size_t x = 0;
  size_t y = -1;
  size_t width = buffer.getWidth();
  size_t height = buffer.getHeight();

  while (++y < height)
  {
    x = -1;
    while (++x < width)
    {
      Color<unsigned char> color = buffer.getPixel(x, y);
      sf::Color sfcolor(color.getRed(), color.getGreen(), color.getBlue());
      _image->setPixel(position.getX() + x, position.getY() + y, sfcolor);
    }
  }
}

std::list<int>* SfmlWrapperGui::getEvents() const
{
  sf::Event event;
  std::list<int>* events = new std::list<int>();
  int search;

  while (_window->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
        events->push_back(AEvents::ESCAPE);
    else if (event.type == sf::Event::KeyPressed)
      {
        search = _eventKeyboard.find(event.key.code)->second;
        if (search != AEvents::NO_EVENT)
          events->push_back(search);
      }
    else if (event.type == sf::Event::MouseButtonPressed)
      {
        search = _eventMouse.find(event.key.code)->second;
        if (search != AEvents::NO_EVENT)
          events->push_back(search);
      }
  }
  return events;
}

void SfmlWrapperGui::render()
{
  sf::Texture texture;
  sf::Color const color(255, 0, 255, 255);
  if (!texture.create(MAP_WIDTH * CASE, MAP_HEIGHT * CASE))
    return;
  texture.update(*_image);
  _sprite.setTexture(texture);
  _window->clear(color);
  _window->draw(_sprite);
  _window->display();
}

IGui* Init(void)
{
  IGui* gui = new SfmlWrapperGui;
  return gui;
}