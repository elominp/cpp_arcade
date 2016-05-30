/*
** AEntity for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/src
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Wed Mar 30 17:29:52 2016 pyre
** Last update Wed Mar 30 18:37:52 2016 pyre
*/

#include "Entity.hh"

Entity::Entity(Point<int> const &pos, size_t width, size_t height) : _pos(pos), _width(width), _height(height)
{

}

Entity::Entity() : _pos(0, 0), _width(1), _height(1) {}

Entity &Entity::operator=(Entity const &entity)
{
  _pos = entity.getPos();
  _width = entity.getWidth();
  _height = entity.getHeight();
  return *this;
}

Entity::~Entity()
{

}

size_t Entity::getWidth() const
{
  return _width;
}

size_t Entity::getHeight() const
{
  return _height;
}

Point<int> const &Entity::getPos() const
{
  return _pos;
}

void Entity::setWidth(size_t width)
{
  _width = width;
}

void Entity::setHeight(size_t height)
{
  _height = height;
}

void Entity::setPos(Point<int> const &pos)
{
  _pos = pos;
}

//soit ses coordonnées sont dans le siennes soit les siennes sont dans les miennes

bool Entity::collide(Entity const &other) const
{
  if (((_pos.getX() <= other.getPos().getX()) && (static_cast<int>(_pos.getX() + _width - 1) >= other.getPos().getX())) ||
      ((other.getPos().getX() <= _pos.getX()) && (static_cast<int>(other.getPos().getX() + other.getWidth() - 1) >= _pos.getX())))
  {
    if (((_pos.getY() <= other.getPos().getY()) && (static_cast<int>(_pos.getY() + _height - 1) >= other.getPos().getY())) ||
        ((other.getPos().getY() <= _pos.getY()) && (static_cast<int>(other.getPos().getY() + other.getHeight() - 1) >= _pos.getY())))
      return true;
  }
  return false;
}

bool Entity::collide(Point<int> const &other) const {
    if ((_pos.getX() <= other.getX()) && (static_cast<int>(_pos.getX() + _width - 1) >= other.getX()))
    {
        if ((_pos.getY() <= other.getY()) && (static_cast<int>(_pos.getY() + _height - 1) >= other.getY()))
            return true;
    }
    return false;
}

std::pair<std::size_t, char*>* Entity::toMoulishitWhereAmI() const
{
  arcade::WhereAmI* moulinetteWhereAmI = reinterpret_cast<arcade::WhereAmI*>(malloc(sizeof(arcade::WhereAmI) + sizeof(arcade::Position)));

  if (moulinetteWhereAmI != NULL)
  {
    moulinetteWhereAmI->lenght = 1;
    moulinetteWhereAmI->type = arcade::CommandType::WHERE_AM_I;
    moulinetteWhereAmI->position[0].x = _pos.getX();
    moulinetteWhereAmI->position[0].y = _pos.getY();

    std::pair<std::size_t, char*>* moulinetteData = new std::pair<std::size_t, char*>(sizeof(arcade::WhereAmI) + sizeof(arcade::Position),
                                                                                     reinterpret_cast<char *>(moulinetteWhereAmI));
    return moulinetteData;
  }
  return NULL;
}