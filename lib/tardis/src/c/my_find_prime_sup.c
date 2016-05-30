/*
** my_find_prime_sup.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:05:02 2015 Guillaume Pirou
** Last update Sun Apr 12 17:05:03 2015 Guillaume Pirou
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
  if (nb < 2)
    nb = 2;
  while (!my_is_prime(nb))
    ++nb;
  return (nb);
}
