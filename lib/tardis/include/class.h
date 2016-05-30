/*
** class.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:40:18 2016 pirou_g
** Last update Thu Mar 17 14:40:19 2016 pirou_g
*/

#ifndef CLASS_H_
# define CLASS_H_

# ifndef __cplusplus

#  include "my_mem.h"

#  define MCAT(p1, p2) p1##p2
#  define STR(obj) obj->__str__(obj)
#  define NEW(t) MCAT(class_, t)()

#  define CLASS_HEADER(name) typedef struct name
#  define END_CLASS_HEADER(name) name;

#  define C1(n) n* MCAT(class_, n)(void) { n* obj = gbgc_malloc(sizeof(n));
#  define C2 if (obj == NULL) { return (NULL); };
#  define CLASS(n) C1(n) C2
#  define END_CLASS }

#  define FUNC(ret, name, ...) { ret name(__VA_ARGS__) {;
#  define END_FUNC(name) } obj->name = name; }

# endif /* __cplusplus */

#endif /* CLASS_H_ */
