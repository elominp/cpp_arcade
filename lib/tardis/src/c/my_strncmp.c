/*
** my_strncmp.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:19:46 2015 Guillaume Pirou
** Last update Sun Apr 12 17:19:52 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int   lp;

  if (s1 == NULL || s2 == NULL || n <= 0)
    return (0);
  lp = 0;
  while (*s1 != '\0' && *s2 != '\0' && (*s1++ == *s2++) && lp < n)
    ++lp;
  s1--;
  s2--;
  if (*s1 < *s2)
    return (-1);
  else if (*s1 == *s2)
    {
      if (my_strlen(s1) < my_strlen(s2))
        return (-1);
      else if (my_strlen(s1) > my_strlen(s2))
        return (1);
      else
        return (0);
    }
  else
    return (1);
}
