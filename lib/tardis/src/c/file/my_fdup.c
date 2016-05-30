/*
** my_fdup.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:22:47 2015 Guillaume Pirou
** Last update Sun Apr 12 17:22:47 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_printf.h"

int	my_fdup(char *path, char *npath)
{
  int	fdf1;
  int	fdf2;
  char	buff[4096];
  int	i;

  if (path == NULL || npath == NULL || (fdf1 = open(path, O_RDONLY)) < 0 ||
      (fdf2 = open(npath, O_CREAT | O_WRONLY)) < 0)
    {
      my_printf("fdf1 = %d\nfdf2 = %d\n", fdf1, fdf2);
      return (0);
    }
  while ((i = read(fdf1, buff, 4096)) > 0)
    {
      if (write(fdf2, buff, i) < 0)
	return (0);
    }
  return (1);
}
