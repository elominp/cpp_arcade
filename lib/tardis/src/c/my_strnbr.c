/*
** my_strnbr.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:19:17 2015 Guillaume Pirou
** Last update Sun Apr 12 17:19:17 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

char	*my_strnbr_b(int nbr, char *tab, char *base, int bs)
{
  int	lp;
  int	len;
  int	sg;

  lp = 0;
  sg = (nbr < 0) ? -1 : 0;
  nbr = (nbr < 0) ? nbr * -1 : nbr;
  len = my_countnb_b(nbr, bs);
  len = (sg  < 0) ? len + 1 : len;
  while (lp < len)
    {
      tab[len - lp - 1] = base[nbr % bs];
      nbr /= bs;
      ++lp;
    }
  tab[lp] = '\0';
  tab[0] = (sg < 0) ? '-' : tab[0];
  return (tab);
}

char	*my_strnbr(int nbr, char *base)
{
  char	*tab;

  if (nbr == 0)
    return ("0");
  if (nbr < 0)
    {
      tab = gbgc_malloc(sizeof(tab) * my_countnb_b(nbr, my_strlen(base)) + 1);
      if (tab == NULL)
	return (NULL);
      tab[0] = '-';
      tab = my_strnbr_b(nbr, tab + 1, base, my_strlen(base));
    }
  else
    {
      tab = gbgc_malloc(sizeof(tab) * my_countnb_b(nbr, my_strlen(base)));
      if (tab == NULL)
	return (NULL);
      tab = my_strnbr_b(nbr, tab, base, my_strlen(base));
    }
  return (tab);
}
