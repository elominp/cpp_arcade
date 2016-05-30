/*
** loops.h for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/include
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:41:30 2016 pirou_g
** Last update Thu Mar 17 14:45:43 2016 pirou_g
*/

#ifndef LOOPS_H_
# define LOOPS_H_

# ifndef __cplusplus

#  include <setjmp.h>
#  include "variable.h"

#  define DO {jmp_buf do_buf; setjmp(do_buf);
#  define WHILE(x) if (x) {longjmp(do_buf, 1);}}

#  define PART_FOR jmp_buf fb; int started = 0; setjmp(fb);
#  define FOR(i, cdt, up) {i; PART_FOR if (started) {up;} if (cdt) {started = 1;
#  define END_FOR longjmp(fb, 1); }}

#  define FRH ssize_t i = s, i < n, i++
#  define FOR_RANGE(t, s, n, f) FOR(FRH) { f(t[i]); } END_FOR

#  define FOR_EACH(t, s, f) FOR(size_t i = 0, i < s, i++) {f(t[i]);} END_FOR

#  define FY3(t, f, n) _tmp[i] = ({f(t[i]);}); } END_FOR _tmp[n] = 0; }_tmp;})
#  define FY2(n) if (_tmp != NULL) { FOR(size_t i = 0, i < n, i++) {
#  define FY(t, n) ({typeof(*t) *_tmp = malloc(sizeof(_tmp) * (n + 1));
#  define FOR_YIELD(t, n, f) FY(t, n) FY2(n) FY3(t, f, n)

#  define ITH typeof(*s) *c = s, c != NULL, c = s->next
#  define ITERATE(s, f) FOR(ITH) { f(c); } END_FOR

# endif /* __cplusplus */

#endif /* LOOPS_H_ */
