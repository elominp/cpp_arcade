/*
** my_atoi.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:04:28 2015 Guillaume Pirou
** Last update Sun Apr 12 17:04:29 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int	is_num(char c)
{
  if (c > 47 && c < 58)
    return (1);
  return (0);
}

int	loop_my_atoi(char *str, unsigned int nb, int signe)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '-' && i == 0)
	signe = -1;
      else if (str[i] == '+' && i == 0)
	signe = 1;
      else if (is_num(str[i]) && (nb <= MAX))
	{
	  nb *= 10;
	  if ((nb < MAX) || ((nb >= MAX) && signe && (str[i] - 48 < 8)) ||
	      ((nb >= MAX) && signe == -1 && (str[i] - 48 < 9)))
	      nb += (str[i] - 48);
	}
      else
	return ((int)(nb * signe));
    }
  return ((int)(nb * signe));
}

int	my_atoi(char *str)
{
  if (str == NULL)
    return (0);
  return (loop_my_atoi(str, 0, 1));
}
