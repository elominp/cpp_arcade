/*
** DL for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     31/03/16 07:59
** Last update on 31/03/16 07:59
*/

#include <dlfcn.h>
#include <stdexcept>
#include "DL.hh"

DL::DL(std::string const &name)
{
    if ((_lib = dlopen(name.c_str(), RTLD_LAZY)) == NULL)
        throw std::runtime_error("Can't load dynamic library");
}

DL::~DL()
{
    dlclose(_lib);
}

void* DL::getSym(std::string const &name)
{
    void *fct = dlsym(_lib, name.c_str());

    if (fct == NULL)
        std::cerr << "dlerror = " << dlerror() << std::endl;
    return fct;
}