/*
** my_mem for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     16/03/16 18:24
** Last update on 16/03/16 18:24
*/

#include <iostream>
#include "my_mem.h"
#include "debug.h"
#include "my.h"

void*       operator new(std::size_t size)
{
    VDPRINT("Allocate %lu\n", size);
    if (!isInitialised())
    {
        DPRINT("Initialize libtardis\n");
        TARDIS_Init();
    }
    return (gbgc_malloc(size));
}

void        operator delete(void *ptr) noexcept
{
    VDPRINT("Delete %p\n", ptr);
    if (!isInitialised())
    {
        DPRINT("Initialize libtardis\n");
        TARDIS_Init();
    }
    gbgc_free(ptr);
}