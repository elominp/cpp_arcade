/*
** my_putnbr_base2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:14:47 2015 Guillaume Pirou
** Last update Sun Apr 12 17:14:48 2015 Guillaume Pirou
*/

#include "my.h"

int	my_printnbr2(long nb, char *base, int bs)
{
  if (nb > -bs && nb < bs)
    {
      (nb < 0) ? my_putchar2(base[-1 * nb]) : my_putchar2(base[nb]);
      return (0);
    }
  my_printnbr(nb / bs, base, bs);
  (nb < 0) ? my_putchar2(base[-(nb % bs)]) : my_putchar2(base[nb % bs]);
  return (0);
}

int	my_putnbr_base2(long nbr, char *base)
{
  if (nbr == 0)
    {
      my_putchar2('0');
      return (0);
    }
  else if (nbr < 0)
    my_putchar2('-');
  my_printnbr2(nbr, base, my_strlen(base));
  return (0);
}

int	my_printunbr2(unsigned long nb, char *base, unsigned int bs)
{
  if (nb < bs)
    {
      my_putchar2(base[nb]);
      return (0);
    }
  my_printnbr2(nb / bs, base, bs);
  my_putchar2(base[nb % bs]);
  return (0);
}

int	my_putunbr_base2(unsigned long nbr, char *base)
{
  if (nbr == 0)
    {
      my_putchar2('0');
      return (0);
    }
  my_printnbr2(nbr, base, my_strlen(base));
  return (0);
}
