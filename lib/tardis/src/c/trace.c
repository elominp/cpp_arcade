/*
** main.c for PSU_2015_philo in /home/pirou_g/ClionProjects/PSU_2015_philo
**
** Made by pirou_g
** Login   <pirou_g@epitech.net>
**
** Started on  Mon Feb 29 11:14:43 2016 pirou_g
** Last update Mon Feb 29 11:14:43 2016 pirou_g
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

const char* what = NULL;
const char* file = NULL;
int         line = -1;

void            trace(int exception)
{
#ifdef DEBUG
    fprintf(stderr, "Program aborted by exception %d\n", exception);
    if (what != NULL)
        fprintf(stderr, "%s occurred", what);
    if (file != NULL)
        fprintf(stderr, "%sin %s", (what != NULL) ? " " : "", file);
    if (line >= 0)
        fprintf(stderr, "%sline %d", (what != NULL || file != NULL) ? " " : "",
                line);
    fprintf(stderr, "\n");
#else
    (void)exception;
#endif
}

void            debug_print(int fd, const char* str, ...)
{
    va_list args;

    va_start(args, str);
    if (fd < 0 || str == NULL)
        return;
#ifdef DEBUG
        vdprintf(fd, str, args);
#endif
    va_end(args);
}