/*
** functions.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:40:47 2016 pirou_g
** Last update Thu Mar 17 14:44:57 2016 pirou_g
*/

#ifndef FUNCTIONS_H_
# define FUNCTIONS_H_

# ifndef __cplusplus

#  include "goto.h"

#  define FUNC(ret, name, ...) ret name(__VA_ARGS__) { LABEL("1");
#  define END_FUNC }
#  define REC_CALL(update) update; GOTO("1b")

#  define LAMBDA(type, args, body) ({type __fn__ args body __fn__;})
#  define LAMBDAC(t, a, b) t (*lambda)a = LAMBDA(t, a, b); lambda

# endif /* __cplusplus */

#endif /* FUNCTIONS_H_ */
