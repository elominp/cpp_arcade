/*
** my_malloc2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:33 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:34 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my_mem.h"

int	ptr_exist(t_gbl *lst, void *ptr)
{
  t_gbl	*cpy;

  if ((cpy = lst) == NULL || ptr == NULL)
    return (0);
  while (cpy != NULL)
    {
      if (cpy->ptr == ptr)
	return (1);
      cpy = cpy->next;
    }
  return (0);
}

void		*_gbgc_add(t_gbl *lst, void *ptr)
{
  static t_gbl	*gbg;
  t_gbl		*el;
  t_gbl		*cpy;

  gbg = (lst != NULL) ? lst : gbg;
  if (ptr != NULL && gbg != NULL && lst == NULL)
    {
      if (ptr_exist(gbg, ptr))
	return (ptr);
      if ((el = malloc(sizeof(t_gbl))) == NULL)
	return (NULL);
      cpy = gbg;
      while (cpy->next != NULL)
	cpy = cpy->next;
      el->prev = cpy;
      el->next = NULL;
      cpy->next = el;
      el->ptr = ptr;
    }
  return (ptr);
}

void   	gbgc_init()
{
  t_gbl	*gbg;

  if ((gbg = malloc(sizeof(t_gbl))) == NULL)
    return;
  gbg->prev = NULL;
  gbg->next = NULL;
  gbg->ptr = NULL;
  _gbgc_malloc(gbg, -1);
  _gbgc_free(gbg, NULL);
  _gbgc_erase(gbg);
  _gbgc_add(gbg, NULL);
  return;
}

void		*_gbgc_malloc(t_gbl *lst, size_t size)
{
  static t_gbl	*gbg;
  void		*ptr;

  if (lst != NULL)
    gbg = lst;
  if (lst == NULL && gbg != NULL && size > 0)
    {
      if ((ptr = malloc(size)) != NULL)
	{
	  _gbgc_add(NULL, ptr);
	  return (ptr);
	}
    }
  return (NULL);
}
