/*
** my_is_prime.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:13 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:14 2015 Guillaume Pirou
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb < 2)
    return (0);
  else
    {
      while (i < nb)
	{
	  if (nb % i == 0)
	    return (0);
	  ++i;
	}
      return (1);
    }
}
