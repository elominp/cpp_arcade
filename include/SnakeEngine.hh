//
// Created by pyre on 31/03/16.
//

#ifndef CPP_ARCADE_SNAKEENGINE_HH
#define CPP_ARCADE_SNAKEENGINE_HH

#include "AEngine.hh"
#include "AEvents.hh"
#include "DrawableEntity.hh"
#include "Buffer.hpp"
#include "sprites.h"
#include "Snake.hh"

class SnakeEngine : public AEngine{
private:
    Map _map;
    Buffer<unsigned char> _pomme;
    DrawableEntity _apple;
    Buffer<unsigned char> _ground;
    Buffer<unsigned char> _wall;
    Buffer<unsigned char> _head;
    Buffer<unsigned char> _body;

    Snake _snake;
    size_t speed;

public:
    SnakeEngine(IGui * = NULL);
    ~SnakeEngine();

private:
    bool collideWithWall();
    void update();
    virtual void doEvents(void); // Update entities based on events : eg. mouse click, keyboard key pressed
    virtual void doIA(void); // Play IA
    virtual void drawMap(void); // Draw background of map
    virtual void drawObjects(void); // Draw objects on map
    virtual void drawEntities(void); // Draw entities like player or enemies
    virtual void render(void); // Display the actual frame

    /* Methods and member-functions for moulinette */
    virtual void whereAmI(void);
    virtual void getMap(void);
    virtual void goUp(void);
    virtual void goDown(void);
    virtual void goLeft(void);
    virtual void goRight(void);
    virtual void goForward(void);
    virtual void shoot(void);
    virtual void illegal(void);
    virtual void play(void);
    //virtual void updateMoulishitFrame(void);
    /* End of methods and member-functions for moulinette */

    void popPomme();
    void viableMap();
};



#endif //CPP_ARCADE_SNAKEENGINE_HH
