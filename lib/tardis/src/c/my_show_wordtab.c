/*
** my_show_wordtab.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:37:57 2015 Guillaume Pirou
** Last update Sun Apr 12 17:37:58 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	lp;

  if (tab == NULL)
    return (0);
  lp = -1;
  while (tab[++lp] != 0)
    {
      my_putstr(tab[lp]);
      my_putchar('\n');
    }
  return (0);
}
