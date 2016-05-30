/*
** my_power_it.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:58 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:59 2015 Guillaume Pirou
*/

int		my_power_it(int nb, int power)
{
  int		loop;
  int		cp_nb;
  long int	res;

  loop = 1;
  cp_nb = nb;
  res = nb;
  if (power == 1)
    return (nb);
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  while (loop < power)
    {
      res *= cp_nb;
      if (res > 2147483647)
	return (0);
      ++loop;
    }
  return (res);
}
