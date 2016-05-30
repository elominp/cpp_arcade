/*
** listes.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:41:21 2016 pirou_g
** Last update Thu Mar 17 14:45:18 2016 pirou_g
*/

#ifndef LISTES_H_
# define LISTES_H_

# ifndef __cplusplus

#  define MERROR -1
#  define MFALSE  0
#  define MTRUE   1

struct		s_mls
{
  void		*item;
  struct s_mls	*next;
  struct s_mls	*prev;
};

typedef struct s_mls t_mls;

int	list_freeel(t_mls *, void (*)(t_mls *));
int	list_addel(t_mls *, void *, void (*)(t_mls *, void *));
int	list_delel(t_mls *, void (*)(t_mls *));
t_mls	*createlist(void *, void (*)(t_mls *, void *));
int	freelist(t_mls *, void (*)(t_mls *));
int	printlist(t_mls *, void (*)(t_mls *));
int	ilistsort(t_mls *, int (*)(t_mls *, t_mls *));

# endif /* __cplusplus */

#endif /* !LISTES_H_ */
