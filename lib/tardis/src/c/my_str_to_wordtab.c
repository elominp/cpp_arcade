/*
** my_str_to_wordtab.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:20:58 2015 Guillaume Pirou
** Last update Sun Apr 12 17:20:59 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "str_to_wordtab.h"

int	is_alphanum(char c)
{
  if (c > 32 && c < 127)
    return (1);
  return (0);
}

int		fill_lwd(t_my_lwd *lwd, t_my_wd *wd, int nb_w, int pos)
{
  int		nb_words;
  int		lp;
  t_my_lwd	*next;

  lp = 0;
  while (!(is_alphanum(wd->str[lp + pos])))
    {
      if (wd->str[lp + pos] == '\0')
	return (nb_w);
      wd->str[lp + pos] = '\0';
      ++lp;
    }
  if ((next = gbgc_malloc(sizeof(t_my_lwd))) == NULL)
    return (-1);
  next->prev = lwd;
  lwd->next = next;
  next->str = wd->str + lp + pos;
  while (is_alphanum(wd->str[++lp + pos]));
  nb_words = fill_lwd(next, wd, ++nb_w, lp + pos);
  return (nb_words);
}

void		fill_wordtab(t_my_wd *wd, t_my_lwd *lwd)
{
  int		lp;
  t_my_lwd	*act;
  t_my_lwd	*prev;

  lp = 0;
  act = lwd->next;
  while (lp < wd->nb_words)
    {
      wd->my_wordtab[lp] = act->str;
      prev = act;
      act = act->next;
      gbgc_free(prev);
      ++lp;
    }
  wd->my_wordtab[lp] = 0;
}

char		**my_str_to_wordtab(char *str)
{
  t_my_wd	wd;
  t_my_lwd	lwd;

  lwd.prev = NULL;
  wd.str = my_strdup(str);
  wd.nb_words = fill_lwd(&lwd, &wd, 0, 0);
  wd.my_wordtab = gbgc_malloc(sizeof(char *) * (wd.nb_words + 1));
  fill_wordtab(&wd, &lwd);
  return (wd.my_wordtab);
}
