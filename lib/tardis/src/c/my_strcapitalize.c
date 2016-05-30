/*
** my_strcapitalize.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:17:13 2015 Guillaume Pirou
** Last update Sun Apr 12 17:17:14 2015 Guillaume Pirou
*/

#include "my.h"

int	my_capitalize(char *str, int index)
{
  if (str[index] >= 97 && str[index] <= 122)
    {
      str[index] -= 32;
      return (0);
    }
  else
    return (my_verifc(str, ++index));
}

int	my_verifc(char *str, int index)
{
  if ((str[index] >= 48 && str[index] <= 57) ||
      (str[index] >= 65 && str[index] <= 90) ||
      (str[index] >= 97 && str[index] <= 122))
    return (0);
  else
    return (1);
}

char	*my_strcapitalize(char *str)
{
  int	cdt;
  int	lp;

  lp = 0;
  cdt = 0;
  while (str[lp] != '\0')
    {
      if (str[lp] >= 97 && str[lp] <= 122)
	{
	  if (lp == 0 || cdt)
	    cdt = my_capitalize(str, lp);
	}
      else
	cdt = my_verifc(str, lp);
      ++lp;
    }
  return (str);
}
