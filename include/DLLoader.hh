//
// Created by pyre on 02/04/16.
//

#ifndef CPP_ARCADE_DLLOADER_HH
#define CPP_ARCADE_DLLOADER_HH

#include <vector>
#include "DL.hh"

class DLLoader{
public:
    DLLoader(int ac, char **graphicsLib);
    ~DLLoader();

    void doArcade();
private:
    std::vector<std::string> _games;
    int _currentGame;
    std::vector<std::string> _graphics;
    int _currentGraphic;
};


#endif //CPP_ARCADE_DLLOADER_HH
