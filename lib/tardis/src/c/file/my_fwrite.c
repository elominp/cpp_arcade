/*
** my_fwrite.c for  in /home/querat_g/42sh/lib_src/file
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Thu Apr 23 11:02:39 2015 gwendal querat
** Last update Thu Apr 23 11:02:40 2015 gwendal querat
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "file.h"

void	my_flush(t_fle *file)
{
  int	i;

  if (file == NULL)
    return;
  if (file->state != FLUSHED)
    write(file->fd, file->buff, file->csr);
  file->csr = 0;
  i = -1;
  while (++i < BUFF_SZ)
    file->buff[i] = 0;
}

size_t		my_fwrite(const void *ptr, size_t size,
			  size_t count, t_fle *file)
{
  size_t       	i;
  size_t       	j;
  const char	*tab;

  if (ptr == NULL || file == NULL || (size * count) > FILE_SZ_MAX ||
      (!(file->fmode & O_WRONLY) && !(file->fmode & O_RDWR)))
    return (-1);
  i = 0;
  j = 0;
  tab = ptr;
  while (j < (count * size))
    {
      while (((i + file->csr) < BUFF_SZ) && j < (count * size))
	file->buff[i++ + file->csr] = tab[j++];
      file->csr += i;
      file->state = NOT_FLUSHED;
      if (file->csr >= BUFF_SZ)
	{
	  my_flush(file);
	  i = 0;
	}
    }
  return ((size_t)j);
}
