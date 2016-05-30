/*
** my_strtok.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:20:47 2015 Guillaume Pirou
** Last update Sun Apr 12 17:20:48 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

int	is_del(char c, char *del)
{
  int	i;

  i = -1;
  if (del == NULL)
    return (0);
  while (del[++i] != '\0')
    {
      if (c == del[i])
	return (1);
    }
  return (0);
}

int	cnt_tok(char *str, char *del)
{
  int	n;
  int	i;

  if (str == NULL || del == NULL)
    return (-1);
  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
      --i;
      while (str[++i] != '\0' && is_del(str[i], del));
      if (!is_del(str[i], del) && str[i] != '\0')
	++n;
      --i;
      while (str[++i] != '\0' && !is_del(str[i], del));
    }
  return (n);
}

void	my_tokcut(char *str, char *del)
{
  int	i;

  i = -1;
  if (str == NULL || del == NULL)
    return;
  while (str[++i])
    {
      if (is_del(str[i], del))
	str[i] = '\0';
    }
}

char	**my_strtokloop(char **out, char *cpy, int len)
{
  int	i;
  int	j;

  i = 0;
  j = -1;
  while (i < len)
    {
      --i;
      while (cpy[++i] == '\0' && i < len);
      if (i < len)
	out[++j] = my_strdup(cpy + i);
      --i;
      while (cpy[++i] != '\0' && i < len);
    }
  gbgc_free(cpy);
  out[++j] = NULL;
  return (out);
}

char	**my_strtok(char *str, char *del)
{
  int	len;
  int	n;
  char	**out;
  char	*cpy;

  if (str == NULL || del == NULL || (len = my_strlen(str)) <= 0 ||
      (cpy = my_strdup(str)) == NULL || (n = cnt_tok(str, del)) < 1 ||
      (out = gbgc_malloc(sizeof(char *) * (n + 1))) == NULL)
    return (NULL);
  out[0] = cpy;
  my_tokcut(cpy, del);
  return (my_strtokloop(out, cpy, len));
}
