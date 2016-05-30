/*
** hashtable3.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:57 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:58 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "listes.h"
#include "hashtable.h"
#include "my_mem.h"
#include "my.h"

void	hasht_del(t_mls *lst)
{
  t_hdt	*data;

  if (lst == NULL || lst->item == NULL)
    return;
  data = lst->item;
  if (data->key != NULL)
    gbgc_free(data->key);
}

int	hasht_delel(void *key, size_t size_key, t_htb *htab)
{
  t_mls	*cpy;
  int	idx;
  t_hdt	*data;

  if (key == NULL || !size_key || htab == NULL || htab->data == NULL ||
      (idx = hashnoct(key, size_key, htab->size)) < 0 ||
      (cpy = htab->data[idx]->next) == NULL)
    return (MERROR);
  while (cpy != NULL)
    {
      data = cpy->item;
      if (cpy->item != NULL && (data->size == size_key) &&
	  my_ptrcmp(data->key, key, size_key))
	{
	  list_delel(cpy, hasht_del);
	  return (1);
	}
      cpy = cpy->next;
    }
  return (MERROR);
}
