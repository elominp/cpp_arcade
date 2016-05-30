//
// Created by pirou_g on 28/03/16.
//

#include <unistd.h>
#include <map>
#include "AEngine.hh"

AEngine::AEngine(IGui *gui):
        _gui(gui),
        _isRunning(true)
{

}

AEngine::~AEngine()
{

}

void AEngine::update()
{
    doEvents();
    doIA();
    drawMap();
    drawObjects();
    drawEntities();
    render();
}

void AEngine::setGui(IGui  *gui)
{
    _gui = gui;
}

IGui *AEngine::getGui() const
{
    return _gui;
}

void AEngine::run()
{
    if (_gui == NULL)
        updateMoulishitFrame();
    else
    {
        while (_isRunning)
        {
            update();
            usleep(16666);
        }
    }
}

void AEngine::dumpMoulishitData(std::pair<std::size_t, char *> const &data, std::ostream &stream)
{
    if (data.second == NULL)
    {
        return;
    }
    stream.write(data.second, data.first);
}

void AEngine::updateMoulishitFrame()
{
    std::uint16_t moulinetteCmd;
    void (AEngine::* moulinetteFct)(void) = NULL;

    while (std::cin.good())
    {
        std::cin.read(reinterpret_cast<char *>(&moulinetteCmd), sizeof(std::uint16_t));
        if (!std::cin.good())
            break;
        try
        {
            moulinetteFct = _moulinetteFcts.at(moulinetteCmd);
        }
        catch (std::out_of_range)
        {
            return;
        }
        (this->*moulinetteFct)();
    }
}