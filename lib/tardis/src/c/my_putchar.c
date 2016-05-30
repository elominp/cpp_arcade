/*
** my_putchar.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:08:40 2015 Guillaume Pirou
** Last update Sun Apr 12 17:08:42 2015 Guillaume Pirou
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
