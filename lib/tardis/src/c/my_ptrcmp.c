/*
** my_ptrcmp.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:07:25 2015 Guillaume Pirou
** Last update Sun Apr 12 17:07:26 2015 Guillaume Pirou
*/

#include <stdlib.h>

int		my_ptrcmp(void *ptr1, void *ptr2, size_t size)
{
  size_t	i;
  char		*tab1;
  char		*tab2;

  if (ptr1 == NULL || ptr2 == NULL || !size)
    return (0);
  i = 0;
  tab1 = (char *)ptr1;
  tab2 = (char *)ptr2;
  while (i < size)
    {
      if (tab1[i] != tab2[i])
	return (0);
      i++;
    }
  return (1);
}
