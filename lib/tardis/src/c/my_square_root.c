/*
** my_square_root.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:17:05 2015 Guillaume Pirou
** Last update Sun Apr 12 17:17:05 2015 Guillaume Pirou
*/

int	my_square_root(int nb)
{
  int	i;

  i = 2;
  if (nb <= 0)
    return (0);
  else if (nb == 1)
    return (1);
  else
    while (1 == 1)
      {
	if ((i * i) == nb)
	  return (i);
	else if (i >= nb)
	  return (0);
	else
	  ++i;
      }
}
