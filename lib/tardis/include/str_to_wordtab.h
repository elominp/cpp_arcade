/*
** str_to_wordtab.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:46:33 2016 pirou_g
** Last update Thu Mar 17 14:46:40 2016 pirou_g
*/

#ifndef STR_TO_WORDTAB_H_
# define STR_TO_WORDTAB_H_

struct  s_my_wd
{
  int   nb_words;
  char  *str;
  char  **my_wordtab;
};
struct          s_my_lwd
{
  struct        s_my_lwd *prev;
  struct        s_my_lwd *next;
  char          *str;
};

typedef struct s_my_wd t_my_wd;
typedef struct s_my_lwd t_my_lwd;

#endif /* !STR_TO_WORDTAB_H_ */
