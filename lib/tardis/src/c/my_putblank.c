/*
** my_putblank.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:07:44 2015 Guillaume Pirou
** Last update Sun Apr 12 17:07:45 2015 Guillaume Pirou
*/

#include "my.h"

void	my_putblank(int nb)
{
  int	i;

  i = -1;
  if (nb < 0)
    return;
  while (++i < nb)
    my_putchar(' ');
}

void	my_putzero(int nb)
{
  int	i;

  i = -1;
  if (nb < 0)
    return;
  while (++i < nb)
    my_putchar('0');
}
