/*
** my_putchar2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:08:50 2015 Guillaume Pirou
** Last update Sun Apr 12 17:08:51 2015 Guillaume Pirou
*/

#include <unistd.h>

void	my_putchar2(char c)
{
  write(2, &c, 1);
}
