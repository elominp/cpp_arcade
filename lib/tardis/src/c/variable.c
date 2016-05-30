/*
** variable for PSU_2015_philo
**
** Made by pirou_g in /home/pirou_g/ClionProjects/PSU_2015_philo
** Login   <pirou_g@epitech.net>
**
** Started on     09/03/16 11:38
** Last update on 09/03/16 11:38
*/

#include <stdlib.h>

void            cleanup_ptr(void* ptr)
{
    void*       ref;

    if (ptr == NULL || (ref = *((void **)ptr)) == NULL)
        return;
    free(ref);
}