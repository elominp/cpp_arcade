/*
** my_malloc.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:23 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:25 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my_mem.h"

void		*gbgc_calloc(size_t n)
{
  unsigned char	*ptr;
  unsigned int	i;

  if (n <= 0 || (ptr = _gbgc_malloc(NULL, n)) == NULL)
    return (NULL);
  i = 0;
  while (i++ < n)
    ptr[i - 1] = 0;
  return (ptr);
}

void		*_gbgc_free(t_gbl *lst, void *ptr)
{
  static t_gbl	*gbg;
  t_gbl		*cpy;

  gbg = (lst != NULL) ? lst : gbg;
  if ((cpy = gbg) != NULL && lst == NULL && ptr != NULL)
    {
      while (cpy != NULL && cpy->ptr != ptr)
	cpy = cpy->next;
      if (cpy != NULL)
	{
	  if (cpy->prev != NULL)
	    cpy->prev->next = cpy->next;
	  if (cpy->next != NULL)
	    cpy->next->prev = cpy->prev;
	  free(cpy->ptr);
	  free(cpy);
	}
    }
  return (NULL);
}

void		*gbgc_realloc(void *ptr, size_t oldsize, size_t newsize)
{
  unsigned char	*nptr;
  unsigned char	*cpy;
  unsigned int	i;

  if ((cpy = ptr) == NULL || oldsize <= 0 || newsize <= 0 ||
      (nptr = _gbgc_malloc(NULL, newsize)) == NULL)
    return (NULL);
  i = 0;
  while (i++ < oldsize)
    nptr[i - 1] = cpy[i - 1];
  _gbgc_free(NULL, ptr);
  return (nptr);
}

void		_gbgc_erase(t_gbl *ptr)
{
  static t_gbl	*gbg;
  t_gbl		*cpy;

  gbg = (ptr != NULL) ? ptr : gbg;
  if (ptr == NULL && gbg != NULL)
    {
      cpy = gbg;
      while (cpy->next != NULL)
	cpy = cpy->next;
      while (cpy->prev != NULL)
	{
	  cpy = cpy->prev;
	  free(cpy->next->ptr);
	  free(cpy->next);
	}
      free(cpy);
    }
}
