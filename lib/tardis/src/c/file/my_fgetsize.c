/*
** my_fgetsize.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:22:54 2015 Guillaume Pirou
** Last update Sun Apr 12 17:22:55 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

long	my_fgetsize(char *path)
{
  long	i;
  int	j;
  int	fd;
  char	buff[4096];

  if (path == NULL)
    return (-1);
  i = 0;
  if ((fd = open(path, O_RDONLY)) < 0)
    return (-1);
  while ((j = read(fd, buff, 4096)) > 0)
    i += j;
  close(fd);
  return (i);
}
