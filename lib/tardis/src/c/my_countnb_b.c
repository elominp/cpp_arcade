/*
** my_countnb_b.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:04:38 2015 Guillaume Pirou
** Last update Sun Apr 12 17:04:39 2015 Guillaume Pirou
*/

int	my_countnb_b(int nb, int bs)
{
  int	lp;

  lp = 0;
  while (nb > 0)
    {
      nb /= bs;
      ++lp;
    }
  return (lp);
}
