/*
** my_get_el.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:05:32 2015 Guillaume Pirou
** Last update Sun Apr 12 17:05:32 2015 Guillaume Pirou
*/

#include <stdlib.h>

int     my_get_el(char c, char *base)
{
  int   lp;

  if (base == NULL)
    return (-1);
  lp = 0;
  while (base[lp] != '\0')
    {
      if (c == base[lp])
        return (lp);
      ++lp;
    }
  return (-1);
}
