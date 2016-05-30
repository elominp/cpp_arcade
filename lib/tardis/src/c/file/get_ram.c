/*
** get_ram.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:22:18 2015 Guillaume Pirou
** Last update Sun Apr 12 17:22:19 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_mem.h"
#include "file.h"

int	get_memunit(char *unit)
{
  if (unit == NULL)
    return (UNIT_ERROR);
  else if (my_strcmp(unit, UBYTE) == 0)
    return (BYTE);
  else if (my_strcmp(unit, UKBYTE) == 0)
    return (KBYTE);
  else if (my_strcmp(unit, UMBYTE) == 0)
    return (MBYTE);
  else if (my_strcmp(unit, UGBYTE) == 0)
    return (GBYTE);
  else
    return (UNIT_ERROR);
}

void	get_raminfoloop(t_ram *ram, char **data, int i)
{
  if (ram == NULL || data == NULL)
    return;
  while (data[++i] != NULL)
    {
      if (my_strcmp(data[i], MEMTOTAL) == 0)
	ram->memtotal = my_atoi(data[i + 1]);
      else if (my_strcmp(data[i], MEMFREE) == 0)
	ram->memfree = my_atoi(data[i + 1]);
      else if (my_strcmp(data[i], MEMAVAILABLE) == 0)
	ram->memavailable = my_atoi(data[i + 1]);
    }
  gbgc_free(data);
}

void	get_raminfo(t_ram *ram)
{
  int	info_size;
  int	fd;
  char	*buffer;
  char	**data;
  int	j;

  if (ram == NULL || (info_size = my_fgetsize("/proc/meminfo")) < 0 ||
      (buffer = gbgc_malloc(info_size + 50)) == NULL)
    return;
  if ((fd = open("/proc/meminfo", O_RDONLY)) < 0 ||
      (j = read(fd, buffer, info_size)) < 0)
    return;
  buffer[j] = '\0';
  close(fd);
  if ((data = my_str_to_wordtab(buffer)) == NULL)
    return;
  gbgc_free(buffer);
  ram->unit = get_memunit(data[2]);
  get_raminfoloop(ram, data, -1);
}
