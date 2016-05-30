/*
** my_revstr.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:16:02 2015 Guillaume Pirou
** Last update Sun Apr 12 17:16:09 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

char	*my_revstr(char *str)
{
  int	len;
  int	lp;
  char	cp;

  if (str == NULL)
    return (NULL);
  len = my_strlen(str);
  my_put_nbr(len);
  lp = 0;
  while (lp < (len / 2))
    {
      cp = str[lp];
      str[lp] = str[len - lp - 1];
      str[len - lp - 1] = cp;
      ++lp;
    }
  return (str);
}
