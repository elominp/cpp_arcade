/*
** Sprites for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     29/03/16 15:47
** Last update on 29/03/16 15:47
*/

#include <stdexcept>
#include "Sprites.hh"

Sprites::Sprites()
{

}

Sprites::Sprites(Sprites const &sprites)
{
    copySprites(sprites);
}

Sprites &Sprites::operator=(Sprites const &sprites)
{
    _sprites.clear();
    copySprites(sprites);
    return *this;
}

Sprites& Sprites::operator+=(Sprites const &sprites)
{
    for (auto it = sprites._sprites.cbegin(); it != sprites._sprites.cend(); it++)
    {
        try
        {
            _sprites.at(it->first);
        }
        catch (std::out_of_range)
        {
            _sprites[it->first] = it->second;
        }
    }
    return *this;
}

void Sprites::copySprites(Sprites const &sprites)
{
    for (auto it = sprites._sprites.cbegin(); it != sprites._sprites.cend(); it++)
        _sprites[it->first] = it->second;
}

Buffer<unsigned char> const& Sprites::operator()(std::size_t idx) const
{
    return _sprites.at(idx);
}

bool Sprites::operator()(size_t idx, CSprite const &sprite)
{
    try
    {
        _sprites.at(idx);
        return false;
    }
    catch (std::out_of_range)
    {
        _sprites[idx] = Buffer<unsigned char>(sprite);
    }
    return true;
}

bool Sprites::operator()(std::size_t idx, Buffer<unsigned char> const &sprite)
{
    try
    {
        _sprites.at(idx);
        return false;
    }
    catch (std::out_of_range)
    {
        _sprites[idx] = sprite;
    }
    return true;
}

Sprites::~Sprites()
{

}