/*
** convert_base.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:47:39 2016 pirou_g
** Last update Thu Mar 17 14:47:40 2016 pirou_g
*/

#include "my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	nb;
  char	*tab;

  nb = my_getnbr_base(nbr, base_from);
  tab = (char *)my_strnbr(nb, base_to);
  return (tab);
}
