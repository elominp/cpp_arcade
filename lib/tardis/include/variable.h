/*
** variable.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:46:50 2016 pirou_g
** Last update Thu Mar 17 14:47:06 2016 pirou_g
*/

#ifndef VARIABLE_H_
# define VARIABLE_H_

# ifndef __cplusplus

#  include <stdlib.h>

void     cleanup_ptr(void* ptr);

# define VAL(type, name, value) type name = value
# define CLEANUP_PTR __attribute__((cleanup(cleanup_ptr)))
# define SMART_PTR(type, name, value) CLEANUP_PTR type * name = value
# define PTR(type, name) type * name = NULL
# define CLEAN(val) if (val != NULL) { free(val); val = NULL; }
# define DYN_VAL(type, name) SMART_PTR(type, name, malloc(sizeof(type)))
# define DYN_ARRAY(t, name, n) SMART_PTR(t, name, malloc(sizeof(t) * n))

# endif /* __cplusplus */

#endif /* VARIABLE_H_ */
