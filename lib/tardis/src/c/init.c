/*
** init for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     17/03/16 14:28
** Last update on 17/03/16 14:28
*/

#ifndef __cplusplus
# include <stdlib.h>
#else
# include <cstdlib>
#endif /* __cplusplus */
#include "my_mem.h"
#include "my.h"

static int _initialised = 0;

void    TARDIS_Init(void)
{
    gbgc_init();
    atexit(TARDIS_CleanUP);
    _initialised = 1;
}

void    TARDIS_CleanUP(void)
{
    gbgc_erase();
}

int     isInitialised(void)
{
    return _initialised;
}