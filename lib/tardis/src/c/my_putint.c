/*
** my_putint.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:14:28 2015 Guillaume Pirou
** Last update Sun Apr 12 17:14:29 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "my.h"

int	my_putdecint(t_data *data, va_list *list, int taille)
{
  long	nb;

  if (data == NULL || list == NULL)
    return (-1);
  if (taille == 4)
    nb = (long)va_arg(*list, int);
  else if (taille == 8)
    nb = va_arg(*list, long);
  else
    return (-1);
  if (data->width > 0)
    {
      if (data->flag == '0')
	my_putzero(data->width - my_nbchiff(nb, 10));
      else
	my_putblank(data->width - my_nbchiff(nb, 10));
    }
  my_putnbr_base(nb, "0123456789");
  return (1);
}

int		my_putudecint(t_data *data, va_list *list, int taille)
{
  unsigned long	nb;

  if (data == NULL || list == NULL)
    return (-1);
  if (taille == 4)
    nb = (unsigned long)va_arg(*list, unsigned int);
  else if (taille == 8)
    nb = va_arg(*list, unsigned long);
  else
    return (-1);
  if (data->width > 0)
    my_putblank(data->width - my_nbchiff(nb, 10));
  my_putunbr_base(nb, "0123456789");
  return (1);
}

int		my_putuoctint(t_data *data, va_list *list)
{
  unsigned long	nb;

  if (data == NULL || list == NULL)
    return (-1);
  nb = (unsigned long)va_arg(*list, unsigned int);
  if (data->width > 0)
    {
      if (data->flag == '0')
	my_putzero(data->width - my_nbchiff(nb, 8));
      else
	my_putblank(data->width - my_nbchiff(nb, 8));
    }
  my_putunbr_base(nb, "01234567");
  return (1);
}

int		my_putuhexint(t_data *data, va_list *list, int taille)
{
  unsigned long	nb;

  if (data == NULL || list == NULL)
    return (-1);
  if (taille == 4)
    nb = (unsigned long)va_arg(*list, unsigned int);
  else if (taille == 8)
    nb = va_arg(*list, unsigned long);
  else
    return (-1);
  if (data->width > 0)
    {
      if (data->flag == '0')
	my_putzero(data->width - my_nbchiff(nb, 16));
      else
	my_putblank(data->width - my_nbchiff(nb, 16));
    }
  my_putnbr_base(nb, "0123456789ABCDEF");
  return (1);
}
