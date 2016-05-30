/*
** Ghost for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     01/04/16 21:31
** Last update on 01/04/16 21:31
*/

#include <stdexcept>
#include "Pacman.hh"

Pacman::Ghost::Ghost(Point<int> const &pos, size_t width, size_t height, AEngine::Map* map, GhostBuster *buster):
        DrawableEntity(pos, width, height, Buffer<unsigned char>(ghost))
{
    if (map == NULL || buster == NULL)
        throw std::logic_error("Pointers of ghosts can't be null");
    _map = map;
    _buster = buster;
}

Pacman::Ghost::Ghost(Ghost const &dup):
        DrawableEntity(dup)
{
    _map = dup._map;
    _buster = dup._buster;
}

Pacman::Ghost& Pacman::Ghost::operator=(Ghost const &dup)
{
    DrawableEntity::operator=(dup);
    _map = dup._map;
    _buster = dup._buster;
    return *this;
}

Pacman::Ghost::~Ghost()
{

}

void Pacman::Ghost::move()
{
    if (_buster->getPos().getX() < _pos.getX() &&
        (_pos.getX() - MAP_TILE) >= 0 &&
        _map->getBackgroundTile(static_cast<std::size_t>((_pos.getX() - MAP_TILE) / MAP_TILE),
                                static_cast<std::size_t>(_pos.getY() / MAP_TILE)) == AEngine::BackgroundTile::GROUND)
        _pos.setX(_pos.getX() - MAP_TILE);
    else if (_buster->getPos().getX() > _pos.getX() &&
            ((_pos.getX() + MAP_TILE) / MAP_TILE) < static_cast<long>(_map->getWidth()) &&
            _map->getBackgroundTile(static_cast<std::size_t>((_pos.getX() + MAP_TILE) / MAP_TILE),
                                    static_cast<std::size_t>(_pos.getY() + MAP_TILE) / MAP_TILE) == AEngine::BackgroundTile::GROUND)
        _pos.setX(_pos.getX() + MAP_TILE);
    else if (_buster->getPos().getY() < _pos.getY() &&
            (_pos.getY() - MAP_TILE) >= 0 &&
             _map->getBackgroundTile(static_cast<std::size_t>(_pos.getX() / MAP_TILE),
                                     static_cast<std::size_t>((_pos.getY() - MAP_TILE) / MAP_TILE)) == AEngine::BackgroundTile::GROUND)
        _pos.setY(_pos.getY() - MAP_TILE);
    else if (_buster->getPos().getY() > _pos.getY() &&
            ((_pos.getY() + MAP_TILE) / MAP_TILE) < static_cast<long>(_map->getHeight()) &&
            _map->getBackgroundTile(static_cast<std::size_t>(_pos.getX() / MAP_TILE),
                                    static_cast<std::size_t>((_pos.getY() + MAP_TILE) / MAP_TILE)) == AEngine::BackgroundTile::GROUND)
        _pos.setY(_pos.getY() + MAP_TILE);
}