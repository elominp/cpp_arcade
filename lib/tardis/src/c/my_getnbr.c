/*
** my_getnbr.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:05:50 2015 Guillaume Pirou
** Last update Sun Apr 12 17:05:51 2015 Guillaume Pirou
*/

#include <stdlib.h>

int		my_string_to_int(char *str, int beg)
{
  int		loop;
  long int	nb;

  if (str == NULL)
    return (0);
  loop = beg;
  while (str[loop] != '\0')
    {
      if (loop == beg)
        nb = str[loop] - 48;
      else if (str[loop] == '0')
        nb *= 10;
      else if (!(str[loop] > 47 && str[loop] < 58))
        return (nb);
      else
        {
          nb *= 10;
          nb += (str[loop] - 48);
        }
      if ((beg == 1 && nb > 2147483648) || (beg == 0 && nb > 2147483647))
	return (0);
      ++loop;
    }
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	begin;

  if (str == NULL)
    return (0);
  if (str[0] == '-')
    begin = 1;
  else
    begin = 0;
  nb = my_string_to_int(str, begin);
  if (str[0] == '-')
    nb *= -1;
  return (nb);
}
