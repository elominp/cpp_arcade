/*
** my_strcpy.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:17:38 2015 Guillaume Pirou
** Last update Sun Apr 12 17:17:39 2015 Guillaume Pirou
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	lp;

  if (dest == NULL || src == NULL)
    return (NULL);
  lp = 0;
  while (src[lp] != '\0')
    {
      dest[lp] = src[lp];
      ++lp;
    }
  dest[lp] = '\0';
  return (dest);
}
