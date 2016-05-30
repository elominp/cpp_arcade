/*
** my_memcpy.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:40 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:41 2015 Guillaume Pirou
*/

#include <stdlib.h>

void		*my_memcpy(void *dest, void *src, size_t size)
{
  char		*des;
  char		*tab;
  size_t	i;

  if (dest == NULL || src == NULL || !size)
    return (NULL);
  des = (char *)dest;
  tab = (char *)src;
  i = 0;
  while (i < size)
    {
      des[i] = tab[i];
      i++;
    }
  return ((void *)des);
}
