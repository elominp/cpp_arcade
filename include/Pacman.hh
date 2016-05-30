/*
** Pacman for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     01/04/16 13:46
** Last update on 01/04/16 13:46
*/

#ifndef CPP_ARCADE_PACMAN_HH
#define CPP_ARCADE_PACMAN_HH

#include "MovableEntity.hh"
#include "DrawableEntity.hh"
#include "AEngine.hh"
#include "Buffer.hpp"
#include "sprites.h"
#include "AEvents.hh"

class Pacman : public AEngine
{
public:
    Pacman(IGui* gui = NULL);
    virtual ~Pacman();

private:
    class GhostBuster : public DrawableEntity
    {
    public:
        GhostBuster(Point<int> const &pos, size_t width, size_t height);
        virtual ~GhostBuster();
        GhostBuster(GhostBuster const &ghostBuster);
        GhostBuster &operator=(GhostBuster const &ghostBuster);
        Point<int> *getNextPos() const;
    };

    class Ghost : public DrawableEntity
    {
    public:
        Ghost(Point<int> const &pos, size_t width, size_t height, AEngine::Map* map, GhostBuster* buster);
        virtual ~Ghost();
        Ghost(Ghost const &dup);
        Ghost &operator=(Ghost const &dup);

        virtual void move();

    private:
        AEngine::Map* _map;
        GhostBuster* _buster;

        /*enum Direction
        {
            STOP = 0,
            LEFT = 1,
            RIGHT = 2,
            UP = 3,
            DOWN = 4
        };

        Direction _direction;*/
    };

    AEngine::Map *_map;
    Buffer<unsigned char> _ground;
    Buffer<unsigned char> _wall;
    Buffer<unsigned char> _ghostBuster;
    Buffer<unsigned char> _ghost;
    DrawableEntity        _dote;
    DrawableEntity        _powerUp;
    GhostBuster        _pacman;
    std::vector<Ghost>  _ghosts;

    virtual void doEvents(void);
    virtual void doIA(void);
    virtual void drawMap(void);
    virtual void drawObjects(void);
    virtual void drawEntities(void);
    virtual void render(void);

    virtual void play(void);

    virtual void update(void);
    virtual void whereAmI(void);
    virtual void getMap(void);
    virtual void goUp(void);
    virtual void goDown(void);
    virtual void goLeft(void);
    virtual void goRight(void);
    virtual void goForward(void);
    virtual void shoot(void);
    virtual void illegal(void);

    void pacWall(size_t x, size_t y);
    bool touchGhost();
    void viableMap();
    Pacman(Pacman const &);
    Pacman& operator=(Pacman const &);
};

#endif //CPP_ARCADE_PACMAN_HH
