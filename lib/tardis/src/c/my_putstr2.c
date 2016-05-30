/*
** my_putstr2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:15:48 2015 Guillaume Pirou
** Last update Sun Apr 12 17:15:49 2015 Guillaume Pirou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	my_putstr2(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
}
