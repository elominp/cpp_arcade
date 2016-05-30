/*
** hashtable2.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:48:40 2016 pirou_g
** Last update Thu Mar 17 14:48:41 2016 pirou_g
*/

#include <stdlib.h>
#include "hashtable.h"
#include "listes.h"
#include "my_printf.h"
#include "my_mem.h"
#include "my.h"

int		hashnoct(void *ptr, size_t len, size_t ref)
{
  unsigned int	i;
  unsigned int	key;
  char		*tab;

  if (ptr == NULL || !len || !ref)
    return (-1);
  i = 0;
  key = 0;
  tab = (char *)ptr;
  while (i < len)
    key += (((i / 2) * 2) == i) ? tab[i++] : -tab[i++];
  return (key % ref);
}

void   	hasht_wel(t_mls *lst, void *data)
{
  if (data == NULL || data == NULL)
    return;
  lst->item = data;
}

int    	hasht_addel(void *key, size_t size_key, t_htb *htab, void *data)
{
  int  	idx;
  t_hdt	*hdata;

  if (key == NULL || data == NULL || htab == NULL || !htab->size || !size_key
      || (idx = hashnoct(key, size_key, htab->size)) < 0 ||
      (hdata = gbgc_malloc(sizeof(t_hdt))) == NULL)
    return (MERROR);
  hdata->data = data;
  hdata->key = my_ptrdup(key, size_key);
  hdata->size = size_key;
  return (list_addel(htab->data[idx], hdata, hasht_wel));
}

void   	*hasht_getel(void *key, size_t size_key, t_htb *htab)
{
  t_mls	*cpy;
  int  	idx;
  t_hdt	*data;

  if (key == NULL || !size_key || htab == NULL || htab->data == NULL ||
      (idx = hashnoct(key, size_key, htab->size)) < 0)
    return (NULL);
  if ((cpy = htab->data[idx]->next) == NULL)
    return (NULL);
  while (cpy != NULL)
    {
      data = cpy->item;
      if (cpy->item != NULL && (data->size == size_key) &&
	  my_ptrcmp(data->key, key, size_key))
	return (data->data);
      cpy = cpy->next;
    }
  return (NULL);
}
