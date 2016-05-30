/*
** Snake.hh for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/include
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Thu Mar 31 09:48:57 2016 pyre
** Last update Thu Mar 31 10:00:43 2016 pyre
*/

#ifndef SNAKE_HH_
# define SNAKE_HH_

#include <list>
#include "Entity.hh"
#include "AEngine.hh"

class Snake {
private:
    std::list<Entity> _snake;
    int _x;
    int _y;
    bool bufferIsSet;
    Buffer<unsigned char> *head;
    Buffer<unsigned char> *body;
    Buffer<unsigned char> *tail;
    bool collide(Point<int> const &, Point<int> const &) const;

public:
    Snake(Point<int> const &, int = 0, int = 0);

    ~Snake();

    //setters
    void eat();

    bool collide(Point<int> const &) const;
    bool collideHead(Point<int> const &) const;
    void whereAmI() const;
    bool touchHimSelf() const;
    size_t getLengh() const;
    void drawSnake(IGui *)const;
    void move();
    void setDirection(int, int);
    void setTextures(Buffer<unsigned char> *head, Buffer<unsigned char> *body, Buffer<unsigned char> *tail);
};

#endif
