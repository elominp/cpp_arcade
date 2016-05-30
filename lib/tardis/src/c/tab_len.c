/*
** tab_len.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:21:55 2015 Guillaume Pirou
** Last update Sun Apr 12 17:21:56 2015 Guillaume Pirou
*/

#include <stdlib.h>

int	tab_len(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}
