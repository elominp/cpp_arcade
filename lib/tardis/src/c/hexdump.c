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
#include <stdint.h>
#include <stdlib.h>
#include "debug.h"
#include "loops.h"

void            fpadding(FILE* stream, char ref, size_t n)
{
    if (stream == NULL)
        return;
    FOR(size_t i = 0, i < n, i++)
    {
        fprintf(stream, "%c", ref);
    }
    END_FOR
}

void            hexdump(void* mem, size_t size, size_t offset)
{
    char        c;
    size_t      i;
    size_t      j;
    uint8_t     tmp;

    if (mem == NULL)
        return;
    FOR(i = 0, i < size, i += 16)
    {
        printf(" %lx ", offset + i);
        FOR(j = 0, (i + j) < size && j < 16, j++)
        {
            tmp = *((uint8_t*)(mem + (i + j)));
            printf((!((j + 1) % 4)) ? "%02x " : "%02x", tmp);
        }
        END_FOR
                fpadding(stdout, ' ', ((16 - j) * 2) + ((16 - j) / 4));
        FOR(j = 0, (i + j) < size && j < 16, j++)
        {
            c = *(((char *)mem) + (i + j));
            printf("%c", ((c >= ' ' && c <= '~') ? c : '.'));
        }
        END_FOR
                fpadding(stdout, ' ', 16 - j);
        printf("\n");
    }
    END_FOR
}