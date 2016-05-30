/*
** hashtable.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:41:14 2016 pirou_g
** Last update Thu Mar 17 14:41:14 2016 pirou_g
*/

#ifndef HASHTABLE_H_
# define HASHTABLE_H_
#include "listes.h"

struct		s_htb
{
  size_t	size;
  t_mls		**data;
};

struct		s_hdt
{
  size_t  	size;
  void		*data;
  void		*key;
};

typedef struct s_htb t_htb;
typedef struct s_hdt t_hdt;

t_htb	*createhashtable(unsigned int);
void   	destroyhashtable(t_htb *);
void   	*hasht_getel(void *, size_t, t_htb *);
int    	hasht_addel(void *, size_t, t_htb *, void *);
int	hasht_delel(void *, size_t, t_htb *);
void	hasht_del(t_mls *);
int    	hashnoct(void *, size_t, size_t);

#endif /* !HASHTABLE_H_ */
