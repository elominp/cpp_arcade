/*
** my_round.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:16:18 2015 Guillaume Pirou
** Last update Sun Apr 12 17:16:19 2015 Guillaume Pirou
*/

#include "my.h"

long	my_round(double in)
{
  int	i;

  i = in;
  if ((in - in) < 0.5)
    return (i);
  return (i + 1);
}
