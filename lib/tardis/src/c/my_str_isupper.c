/*
** my_str_isupper.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:18:36 2015 Guillaume Pirou
** Last update Sun Apr 12 17:18:36 2015 Guillaume Pirou
*/

#include <stdlib.h>

int	my_str_isupper(char *str)
{
  int	lp;

  if (str == NULL)
    return (1);
  lp = 0;
  while (str[lp] != '\0')
    {
      if (str[lp] < 65 || str[lp] > 90)
	return (0);
      ++lp;
    }
  return (1);
}
