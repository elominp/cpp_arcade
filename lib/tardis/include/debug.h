/*
** debug.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:40:28 2016 pirou_g
** Last update Thu Mar 17 14:40:29 2016 pirou_g
*/

#ifndef DEBUG_H_
# define DEBUG_H_

# ifdef __cplusplus

extern "C" {

# endif /* __cplusplus */

void debug_print(int, const char *, ...);
void hexdump(void *, size_t, size_t);

# ifdef __cplusplus

}

# endif /* __cplusplus */

#  define DPRINT(msg) debug_print(2, msg)
#  define VDPRINT(msg, ...) debug_print(2, msg, __VA_ARGS__)

#endif /* DEBUG_H_ */
