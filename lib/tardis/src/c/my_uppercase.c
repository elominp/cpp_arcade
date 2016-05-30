/*
** my_uppercase.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:21:28 2015 Guillaume Pirou
** Last update Sun Apr 12 17:21:29 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

char	*my_uppercase(char *temp)
{
  int	i;
  char	*buff;

  if (temp == NULL)
    return (NULL);
  if ((buff = my_strdup(temp)) == NULL)
    return (NULL);
  i = -1;
  while (buff[++i] != '\0')
    {
      if (buff[i] >= 'a' && buff[i] <= 'z')
	buff[i] -= 32;
    }
  buff[i] = '\0';
  return (buff);
}
