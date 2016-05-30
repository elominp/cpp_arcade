/*
** my_isneg.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:04 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:05 2015 Guillaume Pirou
*/

#include "my.h"

int my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  my_putchar('\n');
  return (0);
}
