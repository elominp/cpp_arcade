//
// Created by ferryl on 3/29/16.
//

#ifndef CPP_ARCADE_CACAWRAPPERGUI_HH
#define CPP_ARCADE_CACAWRAPPERGUI_HH

#include <map>
#include <caca.h>
#include "IGui.hh"
#include "AEvents.hh"
#include "AEngine.hh"

class CacaWrapperGui :public IGui{
public:
    CacaWrapperGui();
    ~CacaWrapperGui();

    virtual void drawPixel(Point<int> const &point, Color<unsigned char> const &color);
    virtual void drawBuffer(Point<int> const &point, Buffer<unsigned char> const &buffer);
    virtual void render(void);
    void         initEventType();
    virtual std::list<int>* getEvents(void) const;

private:
    caca_canvas_t       *_cv;
    caca_display_t      *_dp;
    std::map<int, int>  _eventKeyboard;
};

#endif //CPP_ARCADE_CACAWRAPPERGUI_HH
