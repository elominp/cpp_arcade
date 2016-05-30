/*
** my_swap.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:21:20 2015 Guillaume Pirou
** Last update Sun Apr 12 17:21:20 2015 Guillaume Pirou
*/

#include <stdlib.h>

void	my_swap(void *a, void *b)
{
  void	*c;

  if (a == NULL || b == NULL)
    return;
  c = *(void **)a;
  *(void **)a = *(void **)b;
  *(void **)b = c;
}
