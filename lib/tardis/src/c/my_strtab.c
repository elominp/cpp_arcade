/*
** my_strtab.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:20:33 2015 Guillaume Pirou
** Last update Sun Apr 12 17:20:34 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_mem.h"

int	my_count_strintab(char **tab)
{
  int	i;

  if (tab == NULL)
    return (-1);
  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

char	**my_strtabdup(char **tab)
{
  char	**out;
  int	i;
  int	len;

  if (tab == NULL || (len = my_count_strintab(tab)) <= 0 ||
      (out = gbgc_malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < len)
    out[i] = my_strdup(tab[i]);
  out[i] = NULL;
  return (out);
}

void	free_strtab(char **tab)
{
  int	i;

  if (tab == NULL)
    return;
  i = -1;
  while (tab[++i] != NULL)
    gbgc_free(tab[i]);
  gbgc_free(tab);
}

void	my_putstrtab(char **tab)
{
  int	i;

  if (tab == NULL)
    return;
  i = -1;
  while (tab[++i] != NULL)
    my_printf("%s\n", tab[i]);
}

int	my_strtabsearch(char **tab, char *str)
{
  int	i;

  if (tab == NULL || str == NULL)
    return (0);
  i = -1;
  while (tab[++i] != NULL)
    {
      if (!my_strcmp(tab[i], str))
	return (1);
    }
  return (0);
}
