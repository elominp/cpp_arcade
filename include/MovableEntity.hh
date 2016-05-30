//
// Created by pyre on 31/03/16.
//

#ifndef CPP_ARCADE_MOVABLEENTITY_HH
#define CPP_ARCADE_MOVABLEENTITY_HH

#include "Entity.hh"

class MovableEntity : public Entity {
protected:
    int _x;
    int _y;
public:
    MovableEntity(Point<int> const &, size_t, size_t);
    virtual ~MovableEntity();

    virtual void move();
    virtual void setDirection(int, int);
};


#endif //CPP_ARCADE_MOVABLEENTITY_HH
