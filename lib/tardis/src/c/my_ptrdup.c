/*
** my_ptrdup.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:07:34 2015 Guillaume Pirou
** Last update Sun Apr 12 17:07:35 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

void   	*my_ptrdup(void *ptr, size_t size)
{
  char 	*dest;

  if (ptr == NULL || !size || (dest = gbgc_malloc(size)) == NULL ||
      (dest = my_memcpy(dest, ptr, size)) == NULL)
    return (NULL);
  return ((void *)dest);
}
