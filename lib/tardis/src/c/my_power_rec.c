/*
** my_power_rec.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:07:07 2015 Guillaume Pirou
** Last update Sun Apr 12 17:07:08 2015 Guillaume Pirou
*/

int my_power_rec(int nb, int power)
{
  if (nb == 1)
    return (1);
  if (power == 0)
    return (1);
  if (power < 0 || power > 30)
    return (0);
  if (power == 1)
    return (nb);
  return (nb * my_power_rec(nb, power - 1));
}
