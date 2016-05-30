//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_AENGINE_HH
#define CPP_ARCADE_AENGINE_HH

#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
#include <map>
#include "Protocol.hpp"
#include "IGui.hh"
#include "IGame.hh"

#ifndef NULL
# define NULL 0
#endif

#define MAP_SIZE 25
#define MAP_TILE 64
#define MAP_HEIGHT 15
#define MAP_WIDTH 25

typedef struct arcade::GetMap moulinetteMap;

class AEngine : public IGame {
protected:
    IGui *_gui;
    bool _isRunning;
    std::map<std::uint16_t, void (AEngine::*)(void)> _moulinetteFcts;

    enum BackgroundTile
    {
        NO_TILE = 0,
        WALL = 1,
        GROUND = 2
    };
    enum ObjectsTile
    {
        NO_OBJECT = 0,
        POINT = 1,
        POWER_UP = 2,
        FRUIT = 3,
        TRAP = 4
    };

    class Map
    {
    public:
        Map(std::uint32_t width, std::uint32_t height);
        Map(std::string const &pathname);
        Map(Map const &map);
        Map &operator=(Map const &map);
        ~Map();

        std::string const &getPathname(void) const;
        std::uint32_t getWidth(void) const;
        std::uint32_t getHeight(void) const;
        std::uint8_t const *getMap(void) const;
        std::uint8_t const *getObjects(void) const;
        BackgroundTile getBackgroundTile(std::size_t x, std::size_t y) const;
        ObjectsTile getObjectTile(std::size_t x, std::size_t y) const;

        void setPathname(std::string const &pathname);
        void setBackgroundTile(std::size_t x, std::size_t y, BackgroundTile tile);
        void setObjectTile(std::size_t x, std::size_t y, ObjectsTile tile);

        std::pair<std::size_t, char *>* toMoulishitMap(void) const;

    private:
        std::uint32_t _width;
        std::uint32_t _height;
        std::string _pathname;
        std::uint8_t *_map;
        std::uint8_t *_objects;

        Map();
    };

    void dumpMoulishitData(std::pair<std::size_t, char *> const &data, std::ostream &stream);

public:
    AEngine(IGui *gui = NULL);
    virtual ~AEngine();

    virtual IGui *getGui(void) const;
    virtual void setGui(IGui *gui);

    virtual void run(void);

private:

    virtual void update();
    virtual void doEvents(void) = 0; // Update entities based on events : eg. mouse click, keyboard key pressed
    virtual void doIA(void) = 0; // Play IA
    virtual void drawMap(void) = 0; // Draw background of map
    virtual void drawObjects(void) = 0; // Draw objects on map
    virtual void drawEntities(void) = 0; // Draw entities like player or enemies
    virtual void render(void) = 0; // Display the actual frame

    /* Methods and member-functions for moulinette */
    virtual void play(void) = 0;
    virtual void whereAmI(void) = 0;
    virtual void getMap(void) = 0;
    virtual void goUp(void) = 0;
    virtual void goDown(void) = 0;
    virtual void goLeft(void) = 0;
    virtual void goRight(void) = 0;
    virtual void goForward(void) = 0;
    virtual void shoot(void) = 0;
    virtual void illegal(void) = 0;
    virtual void updateMoulishitFrame(void);
    /* End of methods and member-functions for moulinette */

    /* Coplien's form for an engine, not even in your dreams !!! */
    AEngine(AEngine const &engine);
    AEngine &operator=(AEngine const &engine);
    /* Coplien's form for an engine, not even in your dreams !!! */
};

extern "C" {
    void Play(void); // Call update member-function of an AEngine
    void Run(IGui &gui);
}

#endif //CPP_ARCADE_AENGINE_HH
