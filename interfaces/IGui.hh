//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_IGUI_HH
#define CPP_ARCADE_IGUI_HH

#include <list>
#include "Point.hpp"
#include "Buffer.hpp"

class IGui {
public:
    virtual ~IGui() {};
    virtual void drawPixel(Point<int> const &point, Color<unsigned char> const &color) = 0;
    virtual void drawBuffer(Point<int> const &point, Buffer<unsigned char> const &buffer) = 0;
    virtual void render(void) = 0;
    virtual std::list<int>* getEvents(void) const = 0;
};

#ifdef __cplusplus
extern "C" {
    IGui* Init(void);
};
#endif

#endif //CPP_ARCADE_IGUI_HH
