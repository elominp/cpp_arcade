/*
** GhostBuster for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     01/04/16 20:46
** Last update on 01/04/16 20:46
*/

#include "Pacman.hh"

Pacman::GhostBuster::GhostBuster(Point<int> const &pos, size_t width, size_t height):
        DrawableEntity(pos, width, height, Buffer<unsigned char>(pacman))
{

}

Pacman::GhostBuster::GhostBuster(GhostBuster const &ghostBuster):
        DrawableEntity(ghostBuster)
{

}

Pacman::GhostBuster& Pacman::GhostBuster::operator=(GhostBuster const &ghostBuster)
{
    DrawableEntity::operator=(ghostBuster);
    return *this;
}

Pacman::GhostBuster::~GhostBuster()
{

}