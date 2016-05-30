/*
** Pacman for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     02/04/16 10:51
** Last update on 02/04/16 10:51
*/

#include "Pacman.hh"
#include <unistd.h>

Pacman::Pacman(IGui *gui) :
        AEngine(gui),
        _ground(pacmanGround),
        _wall(pacmanWall),
        _ghostBuster(pacman),
        _ghost(ghost),
        _dote(Buffer<unsigned char>(pacmanDot)),
        _powerUp(Buffer<unsigned char>(pacmanPowerUp)),
        _pacman(Point<int>(12 * MAP_TILE, 7 * MAP_TILE), 1, 1)
{
    _pacman.setDirection(MAP_TILE, 0);
    _isRunning = true;
    _map = new AEngine::Map(MAP_WIDTH, MAP_HEIGHT);
    viableMap();

    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GET_MAP)] = static_cast<void (AEngine::*)(void)>(&Pacman::getMap);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::WHERE_AM_I)] = static_cast<void (AEngine::*)(void)>(&Pacman::whereAmI);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_UP)] = static_cast<void (AEngine::*)(void)>(&Pacman::goUp);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_DOWN)] = static_cast<void (AEngine::*)(void)>(&Pacman::goDown);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_LEFT)] = static_cast<void (AEngine::*)(void)>(&Pacman::goLeft);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_RIGHT)] = static_cast<void (AEngine::*)(void)>(&Pacman::goRight);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::GO_FORWARD)] = static_cast<void (AEngine::*)(void)>(&Pacman::goForward);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::SHOOT)] = static_cast<void (AEngine::*)(void)>(&Pacman::shoot);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::ILLEGAL)] = static_cast<void (AEngine::*)(void)>(&Pacman::illegal);
    _moulinetteFcts[static_cast<std::uint16_t>(arcade::CommandType::PLAY)] = static_cast<void (AEngine::*)(void)>(&Pacman::play);
}

Pacman::~Pacman() {
    delete _map;
}

void Pacman::pacWall(size_t x, size_t y)
{
    _map->setBackgroundTile(x, y, WALL);
    _map->setObjectTile(x, y, NO_OBJECT);
}

void Pacman::viableMap() {
    size_t x = _map->getWidth();
    size_t y = _map->getHeight();

    for(size_t i = 0; i < y; ++i) {
        for (size_t j = 0; j < x; ++j) {
            _map->setBackgroundTile(j, i, GROUND);
            _map->setObjectTile(j, i, POINT);
        }
    }
    for (size_t i = 0; i < MAP_WIDTH; ++i){
        pacWall(i, 0);
        pacWall(i, MAP_HEIGHT - 1);
    }
    for (size_t k = 1; k < 7; ++k) {
        pacWall(0, k);
        pacWall(0, (MAP_HEIGHT - 8) + k);
        pacWall(MAP_WIDTH - 1, k);
        pacWall(MAP_WIDTH - 1, (MAP_HEIGHT - 8) + k);
    }
    for (size_t l = 2; l <= 5; ++l) {
        pacWall(l,2);
        pacWall((MAP_WIDTH - 8) + l, 2);
    }

    for (size_t l = 7; l <= 10; ++l) {
        pacWall(l,2);
        pacWall((MAP_WIDTH - 18) + l,2);
    }

    pacWall(12, 1);
    pacWall(12, 2);

    for (size_t l = 2; l <= 5; ++l) {
        pacWall(l, 4);
        pacWall((MAP_WIDTH - 8) + l, 4);
    }

    for (size_t m = 9; m <= 15 ; ++m) {
        pacWall(m, 4);
    }

    pacWall(12, 5);
    pacWall(12, 6);

    for (size_t l = 8; l <= 10; ++l) {
        pacWall(l,6);
        pacWall((MAP_WIDTH - 19) + l, 6);
    }

    for (size_t n = 4; n <= 8 ; ++n) {
        pacWall(7, n);
        pacWall(17, n);
    }

    for (size_t m = 8; m <= 16 ; ++m) {
        pacWall(m, 8);
    }

    for (size_t m = 8; m <= 16 ; ++m) {
        pacWall(m, 10);
    }

    for (size_t n = 10; n <= 12 ; ++n) {
        pacWall(12, n);
    }

    for (size_t i = 0; i <= 5; ++i){
        pacWall(i, 8);
        pacWall(i, 6);
    }



    _ghosts.push_back(Ghost(Point<int>(MAP_TILE, MAP_TILE), 1, 1, _map, &_pacman));
    _ghosts.push_back(Ghost(Point<int>(MAP_TILE * (MAP_WIDTH - 1), MAP_TILE), 1, 1, _map, &_pacman));
}

void Pacman::doEvents() {
    std::list<int> *events;
    if (_gui != NULL) {
        events = _gui->getEvents();
        while (!events->empty()) {
            if (events->front() == AEvents::DOWN_ARROW)
                goDown();
            else if (events->front() == AEvents::LEFT_ARROW)
                goLeft();
            else if (events->front() == AEvents::RIGHT_ARROW)
                goRight();
            else if (events->front() == AEvents::UP_ARROW)
                goUp();
            else if (events->front() == AEvents::ESCAPE) {
                _isRunning = false;
                return;
            }
            events->pop_front();
        }
        delete events;
    }
}

void Pacman::doIA() {
    unsigned int i = 0;

    while (i < _ghosts.size())
        _ghosts[i++].move();
}

void Pacman::drawMap() {
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            Point<int> pos(x * MAP_TILE, y * MAP_TILE);
            if (_map->getBackgroundTile(x, y) == GROUND)
                _gui->drawBuffer(pos, _ground);
            if (_map->getBackgroundTile(x, y) == WALL)
                _gui->drawBuffer(pos, _wall);
        }
    }
}

void Pacman::play() {
    _pacman.move();
}

void Pacman::drawObjects() {
    size_t x = _map->getWidth();
    size_t y = _map->getHeight();

    for(size_t i = 0; i < y; ++i) {
        for (size_t j = 0; j < x; ++j) {
            Point<int> pos(j * MAP_TILE, i * MAP_TILE);
            if (_map->getObjectTile(j, i) == POINT)
                _gui->drawBuffer(pos, _dote.getTexture());
            else if (_map->getObjectTile(j, i) == POWER_UP)
                _gui->drawBuffer(pos, _powerUp.getTexture());
        }
    }
}

Point<int> *Pacman::GhostBuster::getNextPos() const {
    Point<int> *pos = new Point<int>(0, 0);
    pos->setX(_pos.getX() + _x);
    pos->setY(_pos.getY() + _y);

    if (pos->getX() < 0)
        pos->setX((MAP_WIDTH - 1) * MAP_TILE);
    if (pos->getX() >= MAP_WIDTH * MAP_TILE)
        pos->setX(0);
    if (pos->getY() < 0)
        pos->setY((MAP_HEIGHT - 1) * MAP_TILE);
    if (pos->getY() >= MAP_HEIGHT * MAP_TILE)
        pos->setY(0);

    return pos;
}

void Pacman::drawEntities() {
    unsigned int i = 0;

    while (i < _ghosts.size()) {
        _gui->drawBuffer(_ghosts[i].getPos(), _ghosts[i].getTexture());
        i++;
    }
    _gui->drawBuffer(_pacman.getPos(), _pacman.getTexture());
}

void Pacman::render() {
    _gui->render();
}

void Pacman::whereAmI() {

    std::pair<std::size_t, char *>* moulinetteWhereAmI = _pacman.toMoulishitWhereAmI();
    dumpMoulishitData(*moulinetteWhereAmI, std::cout);
    delete moulinetteWhereAmI;
}

void Pacman::getMap() {

    std::pair<std::size_t, char *> *moulinetteMap = _map->toMoulishitMap();
    if (moulinetteMap == NULL)
        return;
    arcade::GetMap* moulinette = reinterpret_cast<arcade::GetMap*>(moulinetteMap->second);
    moulinette->tile[0] = arcade::TileType::EVIL_DUDE;
    moulinette->tile[1] = arcade::TileType::POWERUP;
    dumpMoulishitData(*moulinetteMap, std::cout);
    delete moulinetteMap;
}

void Pacman::goUp() {
    _pacman.setDirection(0, -1 * MAP_TILE);
}

void Pacman::goDown() {
    _pacman.setDirection(0, 1 * MAP_TILE);
}

void Pacman::goLeft() {
    _pacman.setDirection(-1 * MAP_TILE, 0);
}

void Pacman::goRight() {
    _pacman.setDirection(1 * MAP_TILE, 0);
}

void Pacman::goForward() {}

void Pacman::shoot() {
    illegal();
}

void Pacman::illegal() {
    arcade::CommandType tmp = arcade::CommandType::ILLEGAL;
    dumpMoulishitData(std::pair<std::size_t, char *>(sizeof(std::uint16_t), reinterpret_cast<char *>(&tmp)), std::cout);
}

bool Pacman::touchGhost() {
    unsigned int i =  0;

    while (i < _ghosts.size())
        if (_ghosts[i++].collide(_pacman))
            return true;
    return false;
}

void Pacman::update() {
    usleep(10000);
    doEvents();
    drawMap();
    doIA();
    drawObjects();
    drawEntities();

    Point<int> *nextPos = _pacman.getNextPos();

    if (touchGhost())
        _isRunning = false;
    if (!_isRunning) {
        render();
        return;
    }
    if (_map->getBackgroundTile(nextPos->getX() / MAP_TILE, nextPos->getY() / MAP_TILE) == GROUND) {
        _pacman.move();
        if (_map->getObjectTile(nextPos->getX() / MAP_TILE, nextPos->getY() / MAP_TILE) == POINT)
            _map->setObjectTile(nextPos->getX() / MAP_TILE, nextPos->getY() / MAP_TILE, NO_OBJECT);
        if (_map->getObjectTile(nextPos->getX() / MAP_TILE, nextPos->getY() / MAP_TILE) == POWER_UP)
            _map->setObjectTile(nextPos->getX() / MAP_TILE, nextPos->getY() / MAP_TILE, NO_OBJECT);
    }

    delete(nextPos);
    render();
}

void Play()
{
    Pacman pacman;

    pacman.run();
}

void Run(IGui &gui)
{
    Pacman pacman(&gui);

    pacman.run();
}