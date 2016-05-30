/*
** Sprites for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     29/03/16 15:12
** Last update on 29/03/16 15:12
*/

#ifndef CPP_ARCADE_SPRITES_HH
#define CPP_ARCADE_SPRITES_HH

#include <map>
#include "Buffer.hpp"
#include "sprites.h"

class Sprites
{
public:
    Sprites();
    Sprites(Sprites const &sprites);
    Sprites &operator=(Sprites const &sprites);
    virtual ~Sprites();

    Sprites &operator+=(Sprites const &sprites);

    Buffer<unsigned char> const &operator()(std::size_t idx) const;
    bool operator()(std::size_t idx, CSprite const &sprite);
    bool operator()(std::size_t idx, Buffer<unsigned char> const &sprite);

private:
    std::map<std::size_t, Buffer<unsigned char> > _sprites;

    void copySprites(Sprites const &sprites);
};

#endif //CPP_ARCADE_SPRITES_HH
