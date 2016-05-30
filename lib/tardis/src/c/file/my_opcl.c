/*
** my_opcl.c for  in /home/guigui/Bureau/Projets Epitech/PSU_2014_42sh
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 28 16:10:15 2015 guigui
** Last update Thu May 28 16:10:16 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "file.h"
#include "my_mem.h"

int	my_fclose(t_fle *file)
{
  if (file == NULL)
    return (0);
  gbgc_free(file->name);
  if ((file->fmode & O_WRONLY) || (file->fmode & O_RDWR))
    my_flush(file);
  if (file->fd >= 0)
    {
      if (close(file->fd) < 0)
	{
	  gbgc_free(file);
	  return (0);
	}
    }
  gbgc_free(file);
  return (1);
}

int	is_dir(char *path)
{
  int	fd;

  if (path == NULL)
    return (0);
  if ((fd = open(path, O_RDONLY | O_DIRECTORY)) < 0)
    return (0);
  close(fd);
  my_putstr2("Error : input is a folder\n");
  return (1);
}

void	my_create_file(char *name)
{
  int	fd;

  if (name == NULL)
    return;
  if ((fd = open(name, O_RDONLY)) >= 0)
    {
      close(fd);
      return;
    }
  if ((fd = open(name, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP |
		 S_IROTH)) < 0)
    return;
  close(fd);
}

t_fle	*my_fopen(char *name, int mode)
{
  t_fle	*out;

  if (name == NULL || (out = gbgc_malloc(sizeof(t_fle))) == NULL ||
      is_dir(name))
    return (NULL);
  if ((mode & O_WRONLY) || (mode & O_RDWR))
    my_create_file(name);
  if ((out->name = my_strdup(name)) == NULL || (out->fd = open(name, mode)) < 0)
    return (NULL);
  out->fmode = mode;
  out->csr = 0;
  out->buff[0] = 0;
  out->buff[BUFF_SZ] = 0;
  out->status = NEOF;
  out->state = FLUSHED;
  return (out);
}
