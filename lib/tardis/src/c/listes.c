/*
** listes.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:04:13 2015 Guillaume Pirou
** Last update Sun Apr 12 17:04:14 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "listes.h"
#include "my.h"

int	printlist(t_mls *begin, void (*put_item)(t_mls *))
{
  t_mls	*cpy;

  if ((cpy = begin) == NULL)
    return (MERROR);
  while (cpy != NULL)
    {
      put_item(cpy);
      cpy = cpy->next;
    }
  return (MTRUE);
}

int	countlist(t_mls *begin)
{
  t_mls	*cpy;
  int	i;

  if ((cpy = begin) == NULL)
    return (-1);
  i = 0;
  while (cpy != NULL)
    {
      ++i;
      cpy = cpy->next;
    }
  return (i);
}

int	ilistsort(t_mls *begin, int (*el_cmp)(t_mls *, t_mls *))
{
  int	n;
  int	i;
  int	j;
  int	k;
  t_mls	*cpy;

  if (begin == NULL || el_cmp == NULL || (n = countlist(begin)) <= 0)
    return (MERROR);
  i = 0;
  while (++i < n)
    {
      j = i;
      cpy = begin;
      k = -1;
      while (++k != i)
	cpy = cpy->next;
      while (cpy->prev != NULL && j > 0 && el_cmp(cpy, cpy->prev) < 0)
	{
	  my_swap(cpy, cpy->prev);
	  --j;
	  cpy = cpy->prev;
	}
    }
  return (MTRUE);
}
