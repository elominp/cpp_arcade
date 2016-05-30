/*
** my_malloc3 for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     16/03/16 18:36
** Last update on 16/03/16 18:36
*/

# include <stdlib.h>
# include "my_mem.h"

void    *gbgc_malloc(size_t size)
{
    return (_gbgc_malloc(NULL, size));
}

void    *gbgc_free(void *ptr)
{
    return (_gbgc_free(NULL, ptr));
}

void    *gbgc_add(void *ptr)
{
    return (_gbgc_add(NULL, ptr));
}

void    gbgc_erase(void)
{
    _gbgc_erase(NULL);
}