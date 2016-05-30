/*
** sfml.h for  in /home/pyre/projet/tek2/c++/cpp_arcade/graphicLib/sfml
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Fri Mar 18 14:58:59 2016 pyre
** Last update Thu Mar 31 09:37:00 2016 pyre
*/

#ifndef SFML_H_
# define SFML_H_

# include <SFML/Graphics.hpp>
# include <map>
# include <list>
# include <utility>
# include <vector>
# include <iostream>
# include "Buffer.hpp"
# include "Point.hpp"
# include "Color.hpp"
# include "IGui.hh"
# include "AEvents.hh"
# include "AEngine.hh"

# define CASE 64

class SfmlWrapperGui : public IGui
{
private:
  sf::RenderWindow *_window;
  sf::Image *_image;
  sf::Sprite _sprite;
  std::map<int, int> _eventKeyboard;
  std::map<int, int> _eventMouse;

  void initEventTypes();
public:

  SfmlWrapperGui();
  ~SfmlWrapperGui();
  virtual void drawPixel(Point<int> const &, Color<unsigned char> const &);
  virtual void drawBuffer(Point<int> const &, Buffer<unsigned char> const &);
  virtual void render();
  virtual std::list<int>* getEvents() const;
};

#endif /* SFML_H_ */
