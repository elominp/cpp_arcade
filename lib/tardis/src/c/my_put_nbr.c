/*
** my_put_nbr.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:15:28 2015 Guillaume Pirou
** Last update Sun Apr 12 17:15:29 2015 Guillaume Pirou
*/

#include "my.h"

int	my_pow(int nb, int pw)
{
  int	loop;
  int	cp_nb;

  loop = 1;
  cp_nb = nb;
  while (loop < pw)
    {
      nb *= cp_nb;
      ++loop;
    }
  return (nb);
}

int	my_count_nb(int nb)
{
  int	loop;
  int	count;

  loop = 0;
  count = 0;
  while (!loop)
    {
      if (nb == 0 || nb == -1)
	++loop;
      else
	{
	  nb /= 10;
	  ++count;
	}
    }
  return (count);
}

int	my_put_nbr(int nb)
{
  my_putnbr_base(nb, "0123456789");
  my_putchar('\n');
  return (0);
}
