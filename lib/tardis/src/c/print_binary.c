/*
** print_binary.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:21:49 2015 Guillaume Pirou
** Last update Sun Apr 12 17:21:49 2015 Guillaume Pirou
*/

#include "my.h"

int	print_binary(unsigned int nb)
{
  unsigned int	pow;
  int		i;

  pow = 1 << 7;
  i = 0;
  while (i++ < 8)
    {
      my_putchar((nb & pow) ? '1' : '0');
      pow >>= 1;
    }
  my_putchar('\n');
  return (1);
}
