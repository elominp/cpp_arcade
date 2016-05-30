/*
** aplay for PSU_2015_lemipc
**
** Made by pirou_g in /home/pirou_g/ClionProjects/PSU_2015_lemipc
** Login   <pirou_g@epitech.net>
**
** Started on     23/03/16 12:20
** Last update on 23/03/16 12:20
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

#define SYSAPLAY "aplay -q "

void        aplay(const char *wav)
{
#ifndef MOULINETTE
    char    *cmd;

    if (wav != NULL &&
        (cmd = gbgc_malloc(strlen(wav) + strlen(SYSAPLAY) + 1)) != NULL)
    {
        strcpy(cmd, SYSAPLAY);
        strcpy(cmd + strlen(SYSAPLAY), wav);
        cmd[strlen(SYSAPLAY) + strlen(wav)] = 0;
        system(cmd);
    }
#else
    (void)wav
#endif
}