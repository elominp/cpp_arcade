/*
** ADrawableEntity.cpp for  in /home/pyre/projet/tek2/c++/cpp_arcade/src
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Thu Mar 31 10:27:13 2016 pyre
** Last update Thu Mar 31 10:36:45 2016 pyre
*/

#include "DrawableEntity.hh"

DrawableEntity::DrawableEntity(Point<int> const &pos, size_t width, size_t height, Buffer<unsigned char> const&texture):
        MovableEntity(pos, width, height), _texture(texture)
{

}

DrawableEntity::DrawableEntity(DrawableEntity const &other):
        MovableEntity(other),
        _texture(other.getTexture()){

}

DrawableEntity& DrawableEntity::operator=(DrawableEntity const &other) {
  _texture = other.getTexture();
  _height = other.getHeight();
  _pos = other.getPos();
  _width = other.getWidth();
  return *this;
}

DrawableEntity::DrawableEntity(Buffer<unsigned char> const &buffer) :
        MovableEntity(Point<int>(0, 0), buffer.getWidth(), buffer.getHeight()),
        _texture(buffer)
{

}

DrawableEntity::~DrawableEntity() {}

void DrawableEntity::setTextureOnGui(IGui &gui) const
{
  gui.drawBuffer(_pos, _texture);
}

Buffer<unsigned char> const &DrawableEntity::getTexture() const {
    return _texture;
}

void DrawableEntity::setTexture(Buffer<unsigned char> const &buffer) {
  _texture = buffer;
}