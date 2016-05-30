/*
** Snake.cpp for  in /home/pyre/projet/tek2/c++/cpp_arcade/src
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Thu Mar 31 09:48:31 2016 pyre
** Last update Thu Mar 31 09:56:54 2016 pyre
*/

#include "Snake.hh"
#include "Protocol.hpp"

Snake::Snake(const Point<int> &pos, int x, int y) : _x(x), _y(y) {

    Point<int> position(pos.getX() * MAP_TILE, pos.getY() * MAP_TILE);

    _snake.push_back(Entity(position, 1, 1));
    for (int i = 0; i < 4; ++i)
        eat();
    bufferIsSet = false;
}

Snake::~Snake() { }

void Snake::whereAmI() const{
    void *where;

    if ((where = malloc(sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position) * (_snake.size() - 1))) == NULL)
        return;
    ((struct arcade::WhereAmI *)where)->type = arcade::CommandType::WHERE_AM_I;
    //((struct arcade::WhereAmI *)where)->lenght = sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position) * (_snake.size() - 1);
    ((struct arcade::WhereAmI *)where)->lenght = _snake.size() - 1;
    struct arcade::Position *pos = ((struct arcade::WhereAmI *)where)->position;
    int i = -1;
    std::_List_const_iterator<Entity> it = _snake.begin();
    while (it != _snake.end())
    {
        pos[++i].x = (uint16_t)((*it).getPos().getX() / MAP_TILE);
        pos[i].y = ((uint16_t)(*it).getPos().getY() / MAP_TILE);
        it++;
    }
    std::cout.write((char *)where, sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position) * (_snake.size() - 1));
    free(where);
}

void Snake::move() {
    std::list<Entity>::iterator it = _snake.begin();
    Point<int> headPos = (*it).getPos();

    headPos.setX(headPos.getX() + _x * MAP_TILE);
    headPos.setY(headPos.getY() + _y * MAP_TILE);
    if (headPos.getX() < 0)
        headPos.setX((MAP_WIDTH - 1) * MAP_TILE);
    if (headPos.getX() >= MAP_WIDTH * MAP_TILE)
        headPos.setX(0);
    if (headPos.getY() < 0)
        headPos.setY((MAP_HEIGHT - 1) * MAP_TILE);
    if (headPos.getY() >= MAP_HEIGHT * MAP_TILE)
        headPos.setY(0);
    _snake.push_front(Entity(headPos, 1, 1));
    _snake.pop_back();
}

bool Snake::collide(Point<int> const &pos) const {
    std::_List_const_iterator<Entity> it = _snake.begin();

    while (it != _snake.end())
        if (collide((*it++).getPos(), pos))
            return true;
    return false;
}

bool Snake::collideHead(Point<int> const &object) const {
    std::_List_const_iterator<Entity> it = _snake.begin();

    if ((*it).getPos().getX() == object.getX())
        if ((*it).getPos().getY() == object.getY())
            return true;
    return false;
}

bool Snake::touchHimSelf() const {
    std::_List_const_iterator<Entity> it = _snake.begin();
    std::_List_const_iterator<Entity> head = _snake.begin();

    while (++it != _snake.end())
        if (collide((*it).getPos(), (*head).getPos()))
            return true;
    return false;
}

size_t Snake::getLengh() const {
    return _snake.size();
}

void Snake::drawSnake(IGui *gui) const {
    std::_List_const_iterator<Entity> it = _snake.begin();
    size_t i = 0;

    if (bufferIsSet) {
        gui->drawBuffer((*it).getPos(), *head);
        while (++it != _snake.end()) {
            if (++i <= _snake.size())
                gui->drawBuffer((*it).getPos(), *body);
            else
                gui->drawBuffer((*it).getPos(), *tail);
        }
    }
}

void Snake::setDirection(int x, int y) {
    if (_x == -x && _y == -y)
        return;
    _x = x;
    _y = y;
}

void Snake::setTextures(Buffer<unsigned char>  *head, Buffer<unsigned char> *body,
                        Buffer<unsigned char> *tail) {
    this->head = head;
    this->tail = tail;
    this->body = body;
    bufferIsSet = true;
}

void Snake::eat() {
    std::list<Entity>::iterator it = _snake.begin();
    Point<int> headPos = (*it).getPos();

    headPos.setX(headPos.getX() + _x * MAP_TILE);
    headPos.setY(headPos.getY() + _y * MAP_TILE);
    if (headPos.getX() < 0)
        headPos.setX((MAP_WIDTH - 1) * MAP_TILE);
    if (headPos.getX() >= MAP_WIDTH * MAP_TILE)
        headPos.setX(0);
    if (headPos.getY() < 0)
        headPos.setY((MAP_HEIGHT - 1) * MAP_TILE);
    if (headPos.getY() >= MAP_HEIGHT * MAP_TILE)
        headPos.setY(0);
    _snake.push_front(Entity(headPos, 1, 1));
}

bool Snake::collide(Point<int> const &first, Point<int> const &second) const{
    if (first.getX() == second.getX())
        if (first.getY() == second.getY())
            return true;
    return false;
}