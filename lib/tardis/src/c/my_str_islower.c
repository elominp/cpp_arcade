/*
** my_str_islower.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:18:05 2015 Guillaume Pirou
** Last update Sun Apr 12 17:18:06 2015 Guillaume Pirou
*/

#include <stdlib.h>

int	my_str_islower(char *str)
{
  int	lp;

  if (str == NULL)
    return (1);
  lp = 0;
  while (str[lp] != '\0')
    {
      if (str[lp] < 97 || str[lp] > 122)
	return (0);
      ++lp;
    }
  return (1);
}
