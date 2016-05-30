/*
** my_strcat.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:17:23 2015 Guillaume Pirou
** Last update Sun Apr 12 17:17:24 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_mem.h"

char	*my_strstick(char *st1, char *st2)
{
  int	len;
  char	*dest;
  int	i;
  int	j;

  if (st1 == NULL || st2 == NULL)
    return (NULL);
  len = my_strlen(st1) + my_strlen(st2) + 1;
  if ((dest = gbgc_malloc(len)) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (st1[++i] != '\0')
    dest[++j] = st1[i];
  i = -1;
  while (st2[++i] != '\0')
    dest[++j] = st2[i];
  dest[++j] = '\0';
  return (dest);
}

char	*my_strcat(char *dest, char *src)
{
  int	lp;
  int	cnt;

  cnt = -1;
  while (dest[++cnt] != '\0');
  lp = 0;
  while (src[lp] != '\0')
    {
      dest[cnt + lp] = src[lp];
      ++lp;
    }
  dest[cnt + lp] = '\0';
  return (dest);
}
