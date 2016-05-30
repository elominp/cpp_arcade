/*
** my_strncpy.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:20:04 2015 Guillaume Pirou
** Last update Sun Apr 12 17:20:04 2015 Guillaume Pirou
*/

#include <stdlib.h>

char	*my_strncpy2(char *dest, char *src, int n)
{
  int	lp;

  if (dest == NULL || src == NULL)
    return (NULL);
  lp = 0;
  while (lp < n && src[lp] != '\0')
    {
      dest[lp] = src[lp];
      ++lp;
    }
  if (lp < n)
    dest[lp] = '\0';
  return (dest);
}
