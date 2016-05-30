/*
** my_strlowcase.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:19:05 2015 Guillaume Pirou
** Last update Sun Apr 12 17:19:05 2015 Guillaume Pirou
*/

#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int   lp;

  if (str == NULL)
    return (NULL);
  lp = 0;
  while (str[lp] != '\0')
    {
      if (str[lp] >= 65 && str[lp] <= 90)
        str[lp] += 32;
      ++lp;
    }
  return (str);
}
