/*
** AEntity.hh for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/include
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Wed Mar 30 17:31:09 2016 pyre
** Last update Thu Mar 31 10:19:33 2016 pyre
*/

#ifndef AENTITY_HH_
# define AENTITY_HH_

#include <tuple>
#include "Point.hpp"
#include "Protocol.hpp"

typedef arcade::WhereAmI moulinetteWhereAmI;

class Entity
{
protected:
  Point<int> _pos;
  size_t _width;
  size_t _height;

public:
  Entity(Point<int> const &, size_t, size_t);
    Entity();
  Entity &operator=(Entity const &);
  virtual ~Entity();

  virtual bool collide(Entity const &) const;
  virtual bool collide(Point<int> const &) const;
  //getters
  size_t getWidth() const;
  size_t getHeight() const;
  Point<int> const &getPos() const;
  virtual std::pair<std::size_t, char*>* toMoulishitWhereAmI(void) const;

  //setters
  void setWidth(size_t);
  void setHeight(size_t);
  void setPos(Point<int> const &);
};

#endif
