//
// Created by pyre on 31/03/16.
//

#include "SnakeEngine.hh"
#include <unistd.h>

SnakeEngine::SnakeEngine(IGui *gui) : AEngine(gui),
                                        _map(MAP_WIDTH, MAP_HEIGHT),
                                       _pomme(apple),
                                       _apple(_pomme),
                                       _ground(snakeGround),
                                       _wall(snakeWall),
                                      _head(snakeHead),
                                      _body(snakeBody),
                                       _snake(Point<int>(5, 5), 1, 0)
{
    viableMap();
    _isRunning = true;
    _snake.setTextures(&_head, &_body, &_body);
    srand(time(NULL));
    _map.setBackgroundTile(0, 0, WALL);
    _map.setBackgroundTile(0, 1, WALL);
    _map.setBackgroundTile(1, 0, WALL);
    speed = 4;
    popPomme();
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GET_MAP)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::getMap);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::WHERE_AM_I)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::whereAmI);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_UP)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::goUp);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_DOWN)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::goDown);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_LEFT)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::goLeft);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_RIGHT)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::goRight);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_FORWARD)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::goForward);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::SHOOT)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::shoot);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::ILLEGAL)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::illegal);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::PLAY)] = static_cast<void (AEngine::*)(void)>(&SnakeEngine::play);
}

SnakeEngine::~SnakeEngine() {}

void SnakeEngine::doEvents() {
    std::list<int>* events;

    if (_gui != NULL)
    {
        events = _gui->getEvents();
        while (!events->empty())
        {
            if (events->front() == AEvents::DOWN_ARROW)
                goDown();
            else if (events->front() == AEvents::LEFT_ARROW)
                goLeft();
            else if (events->front() == AEvents::RIGHT_ARROW)
                goRight();
            else if (events->front() == AEvents::UP_ARROW)
                goUp();
            else if (events->front() == AEvents::ESCAPE)
            {
                _isRunning = false;
                return;
            }
            events->pop_front();
        }
        delete events;
    }
}

void SnakeEngine::doIA() { }

bool SnakeEngine::collideWithWall() {
    int x;
    int y = -1;

    while (++y < MAP_HEIGHT)
    {
        x = -1;
        while (++x < MAP_WIDTH)
        {
            Point<int> pos(x * MAP_TILE, y * MAP_TILE);

            if (_map.getBackgroundTile(x, y) != GROUND &&_snake.collideHead(pos))
                return true;
        }
    }
    return false;
}

void SnakeEngine::drawMap() {
    int x;
    int y = -1;

    while (++y < MAP_HEIGHT)
    {
        x = -1;
        while (++x < MAP_WIDTH)
        {
            Point<int> pos(x * MAP_TILE, y * MAP_TILE);
            if (_map.getBackgroundTile(x, y) == GROUND)
                _gui->drawBuffer(pos, _ground);
            if (_map.getBackgroundTile(x, y) == WALL)
                _gui->drawBuffer(pos, _wall);
        }
    }
}

void SnakeEngine::popPomme() {
    Point<int> pos((rand() % MAP_WIDTH) * MAP_TILE, (rand() % MAP_HEIGHT) * MAP_TILE);

    _map.setObjectTile(_apple.getPos().getX() / MAP_TILE, _apple.getPos().getY() / MAP_TILE, NO_OBJECT);
    while (_snake.collide(pos) ||
           _map.getBackgroundTile(pos.getX() / MAP_TILE, pos.getY() / MAP_TILE) != GROUND ||
           _map.getObjectTile(pos.getX() / MAP_TILE, pos.getY() / MAP_TILE) != NO_OBJECT)
    {
        pos.setX((rand() % MAP_WIDTH) * MAP_TILE);
        pos.setY((rand() % MAP_HEIGHT) * MAP_TILE);
    }
    _apple.setPos(pos);
    _map.setObjectTile(pos.getX() / MAP_TILE, pos.getY() / MAP_TILE, FRUIT);
}

void SnakeEngine::drawObjects() {
    _gui->drawBuffer(_apple.getPos(), _pomme);
}

void SnakeEngine::drawEntities() {
    _snake.drawSnake(_gui);
}

void SnakeEngine::render() {
    _gui->render();
}

void SnakeEngine::viableMap() {
    size_t x = _map.getWidth();
    size_t y = _map.getHeight();

    for(size_t i = 0; i < y; ++i) {
        for (size_t j = 0; j < x; ++j) {
            _map.setBackgroundTile(j, i, GROUND);
        }
    }
}

void SnakeEngine::whereAmI() {
    _snake.whereAmI();
}

void SnakeEngine::getMap() {
    std::pair<std::size_t, char *> *moulinetteMap = _map.toMoulishitMap();
    if (moulinetteMap == NULL)
        return;
    dumpMoulishitData(*moulinetteMap, std::cout);
    delete moulinetteMap;
}

void SnakeEngine::play() {
    _snake.move();
}

void SnakeEngine::shoot() {
    illegal();
}

void SnakeEngine::illegal() {
    arcade::CommandType tmp = arcade::CommandType::ILLEGAL;
    dumpMoulishitData(std::pair<std::size_t, char *>(sizeof(std::uint16_t), reinterpret_cast<char *>(&tmp)), std::cout);
}

void SnakeEngine::goUp() {
    _snake.setDirection(0, -1);
}

void SnakeEngine::goDown() {
    _snake.setDirection(0, 1);
}

void SnakeEngine::goLeft() {
   _snake.setDirection(-1, 0);
}

void SnakeEngine::goRight() {
    _snake.setDirection(1, 0);
}

void SnakeEngine::goForward() {

}



void SnakeEngine::update() {
    usleep(100000 / speed);
    if (_snake.touchHimSelf() || collideWithWall())
        _isRunning = false;
    if (!_isRunning)
        return;
    doEvents();
    drawMap();
    if (_snake.collideHead(_apple.getPos()))
    {
        _snake.eat();
        speed = _snake.getLengh();
        popPomme();
    }
    else
        _snake.move();
    drawObjects();
    drawEntities();
    render();
}

void Play()
{
    SnakeEngine snakeEngine;

    snakeEngine.run();
}

void Run(IGui &gui)
{
    SnakeEngine snakeEngine(&gui);

    snakeEngine.run();
}