/*
** my_putstr.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:15:54 2015 Guillaume Pirou
** Last update Sun Apr 12 17:15:55 2015 Guillaume Pirou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
  return (0);
}
