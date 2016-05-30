//
// Created by pirou_g on 28/03/16.
//

#ifndef CPP_ARCADE_IGAME_HH
#define CPP_ARCADE_IGAME_HH

#include "IGui.hh"

class IGame {
public:
    virtual void play(void) = 0;
    virtual void run(void) = 0;
};

#endif //CPP_ARCADE_IGAME_HH
