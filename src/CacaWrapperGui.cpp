//
// Created by ferryl on 3/29/16.
//

#include "CacaWrapperGui.hh"



CacaWrapperGui::CacaWrapperGui() {
    _dp = caca_create_display(NULL);
    _cv = caca_get_canvas(_dp);
    caca_set_display_title(_dp, "THE GAME!");
    initEventType();
}

void CacaWrapperGui::initEventType() {
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_LEFT, AEvents::LEFT_ARROW));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_RIGHT, AEvents::RIGHT_ARROW));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_UP, AEvents::UP_ARROW));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_DOWN, AEvents::DOWN_ARROW));
    _eventKeyboard.insert(std::pair<int, int> (32, AEvents::SPACE));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_ESCAPE, AEvents::ESCAPE));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_RETURN, AEvents::ENTER));
    _eventKeyboard.insert(std::pair<int, int> (CACA_KEY_BACKSPACE, AEvents::BACKSPACE));
    _eventKeyboard.insert(std::pair<int, int> (52, AEvents::PREVIOUS_GAME));
    _eventKeyboard.insert(std::pair<int, int> (53, AEvents::NEXT_GAME));
    _eventKeyboard.insert(std::pair<int, int> (50, AEvents::PREVIOUS_GRAPHIC));
    _eventKeyboard.insert(std::pair<int, int> (51, AEvents::NEXT_GRAPHIC));
    _eventKeyboard.insert(std::pair<int, int> (56, AEvents::RESTART_GAME));
    _eventKeyboard.insert(std::pair<int, int> (57, AEvents::MENU));
}

CacaWrapperGui::~CacaWrapperGui() {
}

void CacaWrapperGui::drawPixel(Point<int> const &point,
                               Color<unsigned char> const &color) {
    unsigned char moy = 0;
    moy += color.getRed();
    moy += color.getBlue();
    moy += color.getGreen();
    moy %= 26;
    caca_set_color_ansi(_cv, CACA_BLACK, CACA_WHITE);
    caca_put_char(_cv, point.getX() / MAP_TILE, point.getY() / MAP_TILE, moy + 'A');

}

void CacaWrapperGui::drawBuffer(Point<int> const &point,
                                Buffer<unsigned char> const &buffer) {
    size_t width = buffer.getWidth();
    size_t height = buffer.getHeight();
    int nbPixBuff = 0;
    uint32_t moyR = 0;
    uint32_t moyG = 0;
    uint32_t moyB = 0;
    uint16_t color;

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            Color<unsigned char> color = buffer.getPixel(j, i);
            moyR += color.getRed() / (255 / 16);
            moyB += color.getBlue() / (255 / 16);
            moyG += color.getGreen() / (255 / 16);
            nbPixBuff++;
        }
    }
    moyR /= nbPixBuff;
    moyB /= nbPixBuff;
    moyG /= nbPixBuff;
    color = 15;
    color <<= 4;
    color += moyR;
    color <<= 4;
    color += moyG;
    color <<= 4;
    color += moyB;
    moyG %= 26;

    caca_set_color_argb(_cv, color, CACA_BLACK);
    caca_put_char(_cv, point.getX() / MAP_TILE, point.getY() / MAP_TILE, moyG + 'A');
}

void CacaWrapperGui::render() {
    caca_refresh_display(_dp);
}

std::list<int>* CacaWrapperGui::getEvents() const{
    std::list<int>* events = new std::list<int>();
    int search;
    int retKey;
    int retok = 0;
    caca_event_t     _ev;

  retok = caca_get_event(_dp, CACA_EVENT_KEY_PRESS, &_ev, 0);
   retKey = caca_get_event_key_ch(&_ev);
    search = this->_eventKeyboard.find(retKey)->second;
    if (search != 0 && retok)
        events->push_back(search);
  return events;

}

IGui* Init(void)
{
    IGui* gui = new CacaWrapperGui;
    return gui;
}