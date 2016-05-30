/*
** my_strlen.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:18:55 2015 Guillaume Pirou
** Last update Sun Apr 12 17:18:55 2015 Guillaume Pirou
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	loop;

  loop = 0;
  if (str == NULL)
    return (-1);
  while (str[loop] != '\0')
    ++loop;
  return (loop);
}
