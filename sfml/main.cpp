/*
** main.cpp for tek2 in /home/pyre/projet/tek2/c++/cpp_arcade/sfml
**
** Made by pyre
** Login   <pyre@epitech.net>
**
** Started on  Tue Mar 29 16:49:57 2016 pyre
** Last update Thu Mar 31 09:46:15 2016 pyre
*/

#include "SfmlWrapperGui.hh"
#include "CacaWrapperGui.hh"
#include "AEvents.hh"
#include "SnakeEngine.hh"
#include "DLLoader.hh"

int main(int ac, char **av)
{
    DLLoader dlLoader(ac, av);
    dlLoader.doArcade();
    /*IGui* gui = Init();
    std::list<int> event;
    Buffer<unsigned char> pomme(apple);
    Point<int> pos;
    Color<unsigned char> color(255, 255, 255);
    SnakeEngine snakeEngine;

    snakeEngine.run();*/
    return(0);
}
