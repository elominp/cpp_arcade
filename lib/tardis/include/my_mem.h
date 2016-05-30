/*
** my_mem.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:41:51 2016 pirou_g
** Last update Thu Mar 17 14:41:51 2016 pirou_g
*/

#ifndef MY_MEM_H_
# define MY_MEM_H_

# ifndef __cplusplus

#  include <stdlib.h>

# else

#  include <cstdlib>

void*   operator new(std::size_t);
void    operator delete(void* ptr) noexcept;

# endif /* __cplusplus */

struct		s_gbgl
{
    void		*ptr;
    struct s_gbgl *next;
    struct s_gbgl *prev;
};

struct	s_arg
{
    int   nfiles;
    char	**name;
};

typedef struct s_arg t_arg;
typedef struct s_gbgl t_gbl;

# ifdef __cplusplus

extern "C" {

# endif /* __cplusplus */

void *gbgc_malloc(size_t);
void *_gbgc_malloc(t_gbl *, size_t);
void *gbgc_calloc(size_t);
void gbgc_freeptr(t_gbl *);
void *gbgc_free(void *);
void *_gbgc_free(t_gbl *, void *);
void *gbgc_realloc(void *, size_t, size_t);
void *_gbgc_add(t_gbl *, void *);
void *gbgc_add(void *);
void gbgc_init(void);
void gbgc_erase(void);
void _gbgc_erase(t_gbl *);

# ifdef __cplusplus

};

# endif /* __cplusplus */

#endif /* !MY_MEM_H_ */
