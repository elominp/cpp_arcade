/*
** except.h for cpp_arcade in lib/tardis/include
**
** Made by pirou_g
** Login   <pirou_g@epitech.net>
**
** Started on  Thu Mar 17 14:40:38 2016 pirou_g
** Last update Mon Mar 21 15:47:18 2016 querat_g
*/

#ifndef EXCEPT_H_
# define EXCEPT_H_

# ifndef __cplusplus

#  include <setjmp.h>
#  include <stdio.h>
#  include <stdlib.h>

extern const char* what;
extern const char* file;
extern int line;

typedef struct      s_exc
{
    struct s_exc*   next;
    jmp_buf         frame;
    const char*     func_name;
    unsigned long   caller_line;
}                   t_exc;

#  define FOUT fflush(stdout)
#  define FERR fflush(stderr)

#  define TRY {jmp_buf tb; int cth = 0; int e; if (!(e = setjmp(tb)))
#  define THW_INFOS file = __FILE__; line = __LINE__;
#  define THROW(x) if (x != 1) {THW_INFOS longjmp(tb, x);}
#  define THROW_MSG(x, msg) if (x != 1) {THW_INFOS what = msg; longjmp(tb, x);}
#  define CATCH(x) if (!cth && e) {(cth = (x == e) ? 1 : 0);} if (x == e && e)
/* #define TRACE(x) ERR("Program aborted by exception %d\n", x); FERR; */
#  define TRACE trace
#  define ENDTRY if (!cth && e) {TRACE(e); abort();}}

/* Exceptions Values */

/* static const char *what[4294967295] = {NULL}; */

#  define EXCEPTION          0
/*what[EXCEPTION] =         "Standard Exception";*/

#  define LOGIC_ERROR        -10
/*what[LOGIC_ERROR] =       "Logic Error";*/
#   define INVALID_ARGUMENT   -11
/*what[INVALID_ARGUMENT] =  "Invalid Argument";*/
#   define DOMAIN_ERROR      -12
/*what[DOMAIN_ERROR] =      "Domain Error";*/
#   define LENGTH_ERROR      -13
/*what[LENGTH_ERROR] =      "Length Error";*/
#   define OUT_OF_RANGE      -14
/*what[OUT_OF_RANGE] =      "Out of Range";*/
#   define FUTURE_ERROR      -15
/*what[FUTURE_ERROR] =      "Future Error";*/

#  define RUNTIME_ERROR      -20
/*what[RUNTIME_ERROR] =     "Runtime Error";*/
#   define RANGE_ERROR       -21
/*what[RANGE_ERROR] =       "Range Error";*/
#   define OVERFLOW_ERROR    -22
/*what[OVERFLOW_ERROR] =    "Overflow Error";*/
#   define UNDERFLOW_ERROR   -23
/*what[UNDERFLOW_ERROR] =   "Underflow Error";*/
#   define REGEX_ERROR       -24
/*what[REGEX_ERROR] =       "Regex Error";*/
#   define SYSTEM_ERROR      -25
/*what[SYSTEM_ERROR] =      "System Error";*/

#  define MEMORY_ERROR       -30
/*what[MEMORY_ERROR] =      "Memory Error";*/
#   define BAD_ALLOC         -31
/*what[BAD_ALLOC] =         "Bad Dynamic Allocation";*/
#   define BAD_FREE          -32
/*what[BAD_FREE] =          "Bad dynamic memory liberation";*/
#   define BAD_ALLOCA        -33
/*what[BAD_ALLOCA] =        "Bad Stack memory allocation";*/

#  define IO_ERROR           -40
/*what[IO_ERROR] =          "IO Error";*/
#   define OPEN_ERROR        -41
/*what[OPEN_ERROR] =        "Opening file error";*/
#   define CREATE_ERROR      -42
/*what[CREATE_ERROR] =      "Create file error";*/

# endif /* __cplusplus */

#endif /* EXCEPT_H_ */
