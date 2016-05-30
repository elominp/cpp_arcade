/*
** my_printf.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:07:17 2015 Guillaume Pirou
** Last update Sun Apr 12 17:07:18 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "my.h"

int		my_printf(const char *format, ...)
{
  int		i;
  va_list	list;
  int		cp;

  if (format == NULL)
    return (-1);
  i = -1;
  va_start(list, format);
  while (format[++i] != '\0')
    {
      if (format[i] != '%')
	my_putchar(format[i]);
      else
	{
	  cp = i;
	  i += my_parse_format(format + i, &list);
	  if (i < cp)
	    return (-1);
	}
    }
  va_end(list);
  return (0);
}
