/*
** DL for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     31/03/16 07:54
** Last update on 31/03/16 07:54
*/

#ifndef CPP_ARCADE_DL_HH
#define CPP_ARCADE_DL_HH

#include <string>
#include "IGui.hh"

#ifndef NULL
# define NULL 0
#endif

class DL
{
public:
    DL(std::string const &name);
    ~DL();
    void *getSym(std::string const &name);

protected:

private:
    void *_lib;

    DL();
    DL(DL const &);
    DL &operator=(DL const &);
};

#endif //CPP_ARCADE_DL_HH
