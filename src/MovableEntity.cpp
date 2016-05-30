//
// Created by pyre on 31/03/16.
//

#include "MovableEntity.hh"
#include "AEngine.hh"

MovableEntity::MovableEntity(Point<int> const & pos, size_t width, size_t height):
        Entity(pos, width, height)
{
    _x = 0;
    _y = 0;
}

MovableEntity::~MovableEntity()
{

}

void MovableEntity::move() {
    _pos.setX(_pos.getX() + _x);
    _pos.setY(_pos.getY() + _y);
    if (_pos.getX() < 0)
        _pos.setX((MAP_WIDTH - 1) * MAP_TILE);
    if (_pos.getX() >= MAP_WIDTH * MAP_TILE)
        _pos.setX(0);
    if (_pos.getY() < 0)
        _pos.setY((MAP_HEIGHT - 1) * MAP_TILE);
    if (_pos.getY() >= MAP_HEIGHT * MAP_TILE)
        _pos.setY(0);
}

void MovableEntity::setDirection(int x, int y)
{
    _x = x;
    _y = y;
}