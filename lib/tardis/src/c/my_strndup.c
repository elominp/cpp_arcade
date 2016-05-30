/*
** my_strndup.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:20:14 2015 Guillaume Pirou
** Last update Sun May 10 18:49:11 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

char	*my_strndup(char *src, size_t to)
{
  size_t	lp;
  char		*dest;

  if (src == NULL)
    return (NULL);
  lp = 0;
  if ((dest = gbgc_malloc(to + 1)) == NULL)
      return (NULL);
  while (lp < to && src[lp])
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = '\0';
  return (dest);
}
