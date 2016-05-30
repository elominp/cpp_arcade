//
// Created by pyre on 02/04/16.
//

#include <stdexcept>
#include "DLLoader.hh"

DLLoader::DLLoader(int ac, char **libs) {
    int i = 0;


    std::string game("./games/");
    std::string graphic = "./lib";

    while (++i < ac) {
        std::string current = libs[i];
        if (current.compare(0, game.length(), game) == 0)
            _games.push_back(libs[i]);
        if (current.compare(0, graphic.length(), graphic) == 0)
            _graphics.push_back(libs[i]);
    }
    _currentGame = 0;
    _currentGraphic = 0;
}

DLLoader::~DLLoader() {

}

void DLLoader::doArcade() {
    DL *currentGame = NULL;
    DL *currentGraphic = NULL;
    void (*play)(void);
    void (*run)(IGui *);
    IGui *(*init)(void);

    try {
        if (_graphics.size() > 0)
            currentGraphic = new DL(_graphics[_currentGame]);
    }
    catch  (std::runtime_error) {
        std::cerr << "Graphic lib loading failed" << std::endl;
        currentGraphic = NULL;
    }
    try {
        if (_games.size() > 0)
            currentGame = new DL(_games[_currentGraphic]);
    }
    catch (std::runtime_error) {
        std::cerr << "No gaming lib " << _games[_currentGame] << std::endl;
        return;
    }
    if (currentGraphic && currentGame) {
        init = reinterpret_cast<IGui *(*)(void)>(currentGraphic->getSym("Init"));
        run = reinterpret_cast<void (*)(IGui*)>(currentGame->getSym("Run"));
        if (run == NULL ||  init == NULL)
            return;
        try {
            IGui *gui = init();
            run(gui);
        }
        catch (std::exception){
        }
    }
    else if (currentGame)
    {
        play = reinterpret_cast<void (*)()>(currentGame->getSym("Play"));
        if (play == NULL)
            return;
        play();
    }
    if (currentGame)
        delete(currentGame);
    if (currentGraphic)
        delete(currentGraphic);
}