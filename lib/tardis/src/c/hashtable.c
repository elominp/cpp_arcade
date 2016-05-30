/*
** hashtable.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:48:29 2016 pirou_g
** Last update Thu Mar 17 14:48:30 2016 pirou_g
*/

#include <stdlib.h>
#include "hashtable.h"
#include "listes.h"
#include "my_mem.h"

void		destroyhashtable(t_htb *tab)
{
  unsigned int	i;

  if (tab == NULL || tab->data == NULL)
    return;
  i = 0;
  while (i < tab->size)
    freelist(tab->data[i++], hasht_del);
}

void		init_idata(t_mls *first, void *size)
{
  size_t	len;

  if (first == NULL || size == NULL)
    return;
  len = *((size_t *)size);
  first->item = gbgc_calloc(len);
}

void		init_fdata(t_htb *hash, unsigned int count)
{
  unsigned int	i;

  if (hash == NULL)
    return;
  i = 0;
  if ((hash->data = gbgc_malloc(sizeof(t_htb) * count)) == NULL)
    return;
  while (i < count)
    hash->data[i++] = createlist(NULL, NULL);
}

t_htb	*createhashtable(unsigned int count)
{
  t_htb	*hash;

  if (!count || (hash = gbgc_malloc(sizeof(t_htb))) == NULL)
    return (NULL);
  init_fdata(hash, count);
  if (hash->data == NULL)
    return (NULL);
  hash->size = count;
  return (hash);
}
