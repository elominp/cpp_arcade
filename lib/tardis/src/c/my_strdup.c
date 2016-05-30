/*
** my_strdup.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:17:45 2015 Guillaume Pirou
** Last update Sun Apr 12 17:17:46 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

char	*my_strdup(char *src)
{
  int	len;
  int	lp;
  char	*dest;

  if (src == NULL)
    return (NULL);
  len = my_strlen(src);
  lp = 0;
  if ((dest = gbgc_malloc(len + 1)) == NULL)
      return (NULL);
  while (lp < len)
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = '\0';
  return (dest);
}
