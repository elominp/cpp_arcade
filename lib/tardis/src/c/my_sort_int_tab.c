/*
** my_sort_int_tab.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:16:54 2015 Guillaume Pirou
** Last update Sun Apr 12 17:16:55 2015 Guillaume Pirou
*/

#include "my.h"

int	*the_litlest(int *tab, int size, int pos)
{
  int	loop;
  int	*var;
  int	var2;

  loop = 0 + pos;
  var2 = 2147483647;
  var = &var2;
  while (loop < size)
    {
      if (tab[loop] < *var)
	var = &tab[loop];
      ++loop;
    }
  return (var);
}

void	my_sort_int_tab(int *tab, int size)
{
  int	loop;
  int	*v2;

  loop = 0;
  while (loop < size)
    {
      v2 = the_litlest(tab, size, loop);
      my_swap(&tab[loop], v2);
      ++loop;
    }
}
