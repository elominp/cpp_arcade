/*
** my_strncat.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:19:30 2015 Guillaume Pirou
** Last update Sun Apr 12 17:19:31 2015 Guillaume Pirou
*/

#include <stdlib.h>

char	*my_strncat(char *dest, char *src, int nb)
{
  int	ct;
  int	lp;

  if (dest == NULL || src == NULL)
    return (NULL);
  ct = -1;
  while (dest[++ct] != '\0');
  lp = 0;
  while (src[lp] != '\0' && lp < nb)
  {
    dest[lp + ct] = src[lp];
    ++lp;
  }
  dest[lp + ct] = '\0';
  return (dest);
}
