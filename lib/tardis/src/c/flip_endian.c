/*
** flip_endian.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:47:48 2016 pirou_g
** Last update Thu Mar 17 14:47:49 2016 pirou_g
*/

char	flip_endian(char nb)
{
  int	i;
  char	res;

  res = 0;
  i = 0;
  while (i < 7)
    {
      res |= (nb & 1);
      res <<= 1;
      nb >>= 1;
      i++;
    }
  res |= (nb & 1);
  return (res);
}
