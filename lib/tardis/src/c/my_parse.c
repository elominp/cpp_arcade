/*
** my_parse.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:06:48 2015 Guillaume Pirou
** Last update Sun Apr 12 17:06:49 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "my.h"

int	my_putdata(t_data *data, va_list *list)
{
  char c;

  if (data == NULL || list == NULL)
    return (-1);
  c = data->specifier;
  if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
    return (my_putinteger(data, list));
  else if (c == 's' || c == 'S')
    return (my_putstring(data, list));
  else if (c == 'c')
    {
      my_putchar((char)va_arg(*list, int));
      return (1);
    }
  else if (c == 'p')
    return (my_putpointer(data, list));
  else
      return (-1);
  return (1);
}

int	init_data(t_data *data)
{
  if (data == NULL)
    return (0);
  data->specifier = ' ';
  data->width = 0;
  data->precision = 0;
  data->flag = 0;
  return (1);
}

int	my_isalpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int		my_parse_loop(const char *fmt, va_list *list)
{
  t_data	data;
  int		i;

  if (fmt == NULL || list == NULL || !(init_data(&data)))
    return (-1);
  i = 0;
  while (!is_specifier(fmt[++i]))
    {
      if (is_flags(fmt[i]))
	i += get_flags(fmt + i, &data) - 1;
      if (is_width(fmt[i]))
	i += get_width(fmt + i, &data, list);
      if (is_precision(fmt[i], fmt[i + 1]))
	i += get_precision(fmt + i, &data, list) - 1;
      if (fmt[i] == '\0' || (my_isalpha(fmt[i]) && !is_specifier(fmt[i])))
	{
	  my_putchar('%');
	  my_putchar(fmt[i]);
	  return (i);
	}
    }
  get_specifier(fmt[i], &data);
  if (is_specifier(data.specifier))
    my_putdata(&data, list);
  return (i);
}

int		my_parse_format(const char *fmt, va_list *list)
{
  int		i;

  if (fmt == NULL)
    return (-1);
  i = 0;
  if (fmt[1] == '%')
    {
      my_putchar('%');
      ++i;
    }
  else
    i += my_parse_loop(fmt, list);
  return (i);
}
