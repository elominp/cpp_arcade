//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_AEVENTS_HH
#define CPP_ARCADE_AEVENTS_HH

#include <vector>
#include <list>
#include "Point.hpp"

class AEvents {
public:
    enum Event {
        NO_EVENT = 0,
        LEFT_ARROW = 1,
        RIGHT_ARROW = 2,
        UP_ARROW = 3,
        DOWN_ARROW = 4,
        SPACE = 5,
        ESCAPE = 6,
        ENTER = 7,
        BACKSPACE = 8,
        LEFT_CLICK = 9,
        RIGHT_CLICK = 10,
        MIDDLE_CLICK = 11,
        PREVIOUS_GAME = 12,
        NEXT_GAME = 13,
        PREVIOUS_GRAPHIC = 14,
        NEXT_GRAPHIC = 15,
        RESTART_GAME = 16,
        MENU = 17
    };

    AEvents(AEvents const &event);
    AEvents(Event event);
    AEvents &operator=(AEvents const &events);
    AEvents &operator=(Event event);
    virtual ~AEvents() {};

    virtual std::vector<std::pair<Point<int>, Event> > getMouseEvent(void) const = 0;
    virtual std::vector<Event> getKeyboardEvent(void) const = 0;
private:
    AEvents();
    std::vector<Event> _event;
    Point<int> _point;
};

#endif //CPP_ARCADE_AEVENTS_HH
