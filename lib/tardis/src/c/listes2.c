/*
** listes2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:04:19 2015 Guillaume Pirou
** Last update Sun Apr 12 17:04:20 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "listes.h"
#include "my_mem.h"

t_mls	*createlist(void *data, void (*set_data)(t_mls *, void *))
{
  t_mls *n_el;

  if ((n_el = gbgc_malloc(sizeof(t_mls))) == NULL)
    return (NULL);
  if (data != NULL && set_data != NULL)
    set_data(n_el, data);
  else if (data != NULL)
    n_el->item = gbgc_add(data);
  else
    n_el->item = NULL;
  n_el->prev = NULL;
  n_el->next = NULL;
  return (n_el);
}

int	freelist(t_mls *begin, void (*free_data)(t_mls *))
{
  t_mls *cpy;

  if ((cpy = begin) == NULL)
    return (MERROR);
  while (cpy != NULL)
    {
      begin = begin->next;
      if (list_delel(cpy, free_data) == MERROR)
	return (MERROR);
      cpy = begin;
    }
  return (MTRUE);
}

int	list_freeel(t_mls *el, void (*free_data)(t_mls *))
{
  if (el == NULL)
    return (MERROR);
  if (free_data != NULL)
    free_data(el);
  else
    el->item = gbgc_free(el->item);
  gbgc_free(el);
  return (MTRUE);
}

int	list_addel(t_mls *lst, void *data,
		   void (*set_data)(t_mls *, void *))
{
  t_mls	*el;

  if (lst == NULL || ((el = gbgc_malloc(sizeof(t_mls))) == NULL))
    return (MERROR);
  el->prev = lst;
  el->next = lst->next;
  lst->next = el;
  if (data != NULL && set_data != NULL)
    set_data(el, data);
  else if (data != NULL)
    el->item = gbgc_add(data);
  else
    el->item = NULL;
  return (MTRUE);
}

int	list_delel(t_mls *lst, void (*free_data)(t_mls *))
{
  t_mls	*cpy;

  if (lst == NULL)
    return (MERROR);
  cpy = lst;
  if (lst->prev != NULL)
    lst->prev->next = lst->next;
  if (lst->next != NULL)
    lst->next->prev = lst->prev;
  return (list_freeel(cpy, free_data));
}
