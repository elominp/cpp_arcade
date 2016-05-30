/*
** my_getnbr_base.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:05:43 2015 Guillaume Pirou
** Last update Sun Apr 12 17:05:44 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

int	my_check(char *nbr)
{
  int	lp;
  int	sg;

  sg = 0;
  lp = 0;
  while (nbr[lp] != '\0')
    {
      if (nbr[lp] == '+' || nbr[lp] == '-')
	{
	  if (sg == 1)
	    return (0);
	}
      else if ((nbr[lp] != '+' || nbr[lp] != '-') && sg == 0)
	sg = 1;
      ++lp;
    }
  return (1);
}

char	*get_begin(char *nbr, int *sg)
{
  int	lp;
  int	sign;

  lp = 0;
  sign = 1;
  while (nbr[lp] == '+' || nbr[lp] == '-')
    {
      if (nbr[lp] == '-')
	sign *= -1;
      ++lp;
    }
  *sg = sign;
  return (nbr + lp);
}

int	my_getnbr_base(char *nbr, char *base)
{
  int	bs;
  int	nb;
  int	lp;
  int	sg;

  if (nbr == NULL || base == NULL)
    return (0);
  bs = my_strlen(base);
  if (!my_check(nbr))
    return (0);
  lp = 0;
  nb = 0;
  nbr = get_begin(nbr, &sg);
  while (nbr[lp] != '\0')
    {
      if (my_get_el(nbr[lp], base) == -1)
	return (nb);
      nb *= bs;
      nb += my_get_el(nbr[lp], base);
      ++lp;
    }
  nb = (sg < 0) ? nb * -1 : nb;
  return (nb);
}
