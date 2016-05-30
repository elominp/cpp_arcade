/*
** ADrawableEntity.hh for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/include
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Thu Mar 31 10:01:12 2016 pyre
** Last update Thu Mar 31 10:31:01 2016 pyre
*/

#ifndef ADRAWABLEENTITY_HH_
# define ADRAWABLEENTITY_HH_

#include "IGui.hh"
#include "MovableEntity.hh"

class DrawableEntity : public MovableEntity
{
protected:
    Buffer<unsigned char> _texture;

public:
    DrawableEntity(Point<int> const &, size_t, size_t, Buffer<unsigned char> const &);
    DrawableEntity(Buffer<unsigned char> const &);
    DrawableEntity(DrawableEntity const &);
    DrawableEntity &operator=(DrawableEntity const &);
    virtual ~DrawableEntity();

    //setTexture on graphic lib
    void setTextureOnGui(IGui &) const;
    void setTexture(Buffer<unsigned char> const &);

    Buffer<unsigned char> const &getTexture() const;
};

#endif
