/*
** gen_flip_endian.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:47:57 2016 pirou_g
** Last update Thu Mar 17 14:47:57 2016 pirou_g
*/

#include <stdlib.h>

void	swap_oct(char *a, char *b)
{
  char	c;

  if (a == NULL || b == NULL)
    return;
  c = *a;
  *a = *b;
  *b = c;
}

void		nflip_endian(void *ptr, size_t size)
{
  size_t	i;
  char		*tab;

  if (ptr == NULL || size < 2)
    return;
  i = 0;
  tab = (char *)ptr;
  while (i < (size / 2))
    {
      swap_oct(&tab[i], &tab[size - i - 1]);
      i++;
    }
}
