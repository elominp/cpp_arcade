/*
** Map for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     30/03/16 13:49
** Last update on 30/03/16 13:49
*/

#include <fstream>
#include <stdexcept>
#include "AEngine.hh"

AEngine::Map::Map(std::uint32_t width, std::uint32_t height):
        _width(width),
        _height(height),
        _pathname("")
{
    _map = new std::uint8_t[width * height];
    _objects = new std::uint8_t[width * height];
}

AEngine::Map::~Map()
{
    std::ofstream map(_pathname, std::ofstream::binary | std::ofstream::trunc);

    if (map.is_open())
    {
        map.write(reinterpret_cast<char *>(&_width), sizeof(std::uint32_t));
        map.write(reinterpret_cast<char *>(&_width), sizeof(std::uint32_t));
        map.write(reinterpret_cast<char *>(_map), _width * _height);
        map.write(reinterpret_cast<char *>(_objects), _width * _height);
    }
    delete[] _map;
    delete[] _objects;
}

AEngine::Map::Map(std::string const &pathname):
        _width(0),
        _height(0),
        _pathname(pathname)
{
    std::ifstream map(pathname, std::ifstream::binary);

    if (!map.is_open())
        throw std::runtime_error("Impossible to open map file");
    map.read(reinterpret_cast<char *>(&_width), sizeof(std::uint32_t));
    map.read(reinterpret_cast<char *>(&_height), sizeof(std::uint32_t));
    _map = new std::uint8_t[_width * _height];
    _objects = new std::uint8_t[_width * _height];
    map.read(reinterpret_cast<char *>(_map), _width * _height);
    map.read(reinterpret_cast<char *>(_objects), _width * _height);
}

AEngine::Map::Map(Map const &map):
        _width(map._width),
        _height(map._height),
        _pathname(map._pathname)
{
    _map = new std::uint8_t[_width * _height];
    _objects = new std::uint8_t[_width * _height];
}

AEngine::Map &AEngine::Map::operator=(Map const &map)
{
    delete[] _map;
    delete[] _objects;
    _width = map._width;
    _height = map._height;
    _pathname = map._pathname;
    _map = new std::uint8_t[_width * _height];
    _objects = new std::uint8_t[_width * _height];
    for (std::size_t i = 0; i < (_width * _height); i++)
    {
        _map[i] = map._map[i];
        _objects[i] = map._objects[i];
    }
    return *this;
}

std::string const &AEngine::Map::getPathname() const
{
    return _pathname;
}

std::uint32_t AEngine::Map::getWidth() const
{
    return _width;
}

std::uint32_t AEngine::Map::getHeight() const
{
    return _height;
}

std::uint8_t const* AEngine::Map::getMap() const
{
    return _map;
}

std::uint8_t const* AEngine::Map::getObjects() const
{
    return _objects;
}

void AEngine::Map::setPathname(std::string const &pathname)
{
    _pathname = pathname;
}

AEngine::BackgroundTile AEngine::Map::getBackgroundTile(std::size_t x, std::size_t y) const
{
    if (x >= _width || y >= _height)
        throw std::out_of_range("Out of map");
    return static_cast<AEngine::BackgroundTile>(_map[(y * _width) + x]);
}

AEngine::ObjectsTile AEngine::Map::getObjectTile(std::size_t x, std::size_t y) const
{
    if (x >= _width || y >= _height)
        throw std::out_of_range("Out of map");
    return static_cast<AEngine::ObjectsTile>(_objects[(y * _width) + x]);
}

void AEngine::Map::setBackgroundTile(std::size_t x, std::size_t y, AEngine::BackgroundTile tile)
{
    if (x >= _width || y >= _height)
        throw std::out_of_range("Out of map");
    _map[(y * _width) + x] = static_cast<std::uint8_t>(tile);
}

void AEngine::Map::setObjectTile(std::size_t x, std::size_t y, AEngine::ObjectsTile tile)
{
    if (x >= _width || y >= _height)
        throw std::out_of_range("Out of map");
    _objects[(y * _width) + x] = static_cast<std::uint8_t>(tile);
}

std::pair<std::size_t, char *>* AEngine::Map::toMoulishitMap() const
{
    std::size_t nbTiles = _width * _height;
    moulinetteMap* shitMap = static_cast<moulinetteMap*>(malloc(sizeof(moulinetteMap) + (nbTiles * sizeof(uint16_t))));
    if (shitMap != NULL)
    {
        shitMap->type = arcade::CommandType::GET_MAP;
        shitMap->width = _width;
        shitMap->height = _height;
        for (std::size_t i = 0; i < nbTiles; i++)
        {
            if (_objects[i])
                shitMap->tile[i] = arcade::TileType::POWERUP;
            else if (_map[i] == AEngine::GROUND)
                shitMap->tile[i] = arcade::TileType::EMPTY;
            else if (_map[i] == AEngine::WALL)
                shitMap->tile[i] = arcade::TileType::BLOCK;
            else
                shitMap->tile[i] = arcade::TileType::OTHER;
        }
        std::pair<std::size_t, char *> *moulinetteData = new std::pair<std::size_t, char *>(sizeof(moulinetteMap) + (nbTiles * sizeof(uint16_t)),
                                                                                           reinterpret_cast<char *>(shitMap));
        return moulinetteData;
    }
    return NULL;
}