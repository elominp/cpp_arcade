/*
** get_next_line.c for cpp_arcade in /home/pirou_g/ClionProjects/cpp_arcade/lib/tardis/src/c
** 
** Made by pirou_g
** Login   <pirou_g@epitech.net>
** 
** Started on  Thu Mar 17 14:48:05 2016 pirou_g
** Last update Thu Mar 17 14:48:06 2016 pirou_g
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_mem.h"
#include "file.h"

static int	my_strncpy(char *in, char *dest, int n)
{
  int		i;

  if (in == NULL || dest == NULL)
    return (0);
  i = -1;
  while (++i < n && in[i] != '\0')
    dest[i] = in[i];
  dest[i] = '\0';
  return (1);
}

int	is_line(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '\n') {
	return (i + 1);
      }
    }
  return (0);
}

char   	*extract_line(t_gnl *file, char *str, int len)
{
  char	*out;
  int	i;

  if (file == NULL || str == NULL || (out = gbgc_malloc(len + 1))
      == NULL)
    return (NULL);
  i = -1;
  while (++i < len && str[i] != '\n' && str[i] != '\0')
    out[i] = str[i];
  out[i] = '\0';
  if ((file->status == MEOF && !is_line(file->buff + file->csr)) || !str[i])
    file->csr = BUFFER_SIZE;
  else if ((file->csr + is_line(file->buff + file->csr)) < BUFFER_SIZE)
    file->csr += is_line(file->buff + file->csr);
  else
    file->csr = BUFFER_SIZE;
  gbgc_free(str);
  if (out[0] == '\0' && file->status == MEOF)
    return (NULL);
  return (out);
}

char	*loop_gnl(t_gnl *file, char *line, char *tmp, int len)
{
  int	i;

  if (file == NULL || line == NULL)
    return (NULL);
  while ((!is_line(line) && file->status != MEOF))
    {
      if ((i = my_fread(file->fd, file->buff, BUFFER_SIZE)) < 0 ||
	  (tmp = gbgc_malloc(len + 2)) == NULL ||
	  !my_strncpy(line, tmp, len))
	return (NULL);
      else if (i == 0)
	file->status = MEOF;
      file->buff[i] = '\0';
      gbgc_free(line);
      len += i;
      if ((line = gbgc_malloc(len + 2)) == NULL ||
	  !my_strncpy(tmp, line, len - i) ||
	  !my_strncpy(file->buff, line + (len - i), i))
	return (NULL);
      gbgc_free(tmp);
      file->csr = 0;
    }
  return (extract_line(file, line, len));
}

char		*get_next_line(t_fle *fd)
{
  static t_gnl	*fle;
  char		*line;
  int		len;

  if (fle == NULL || fle->fd != fd)
    {
      gbgc_free(fle);
      if ((fle = gbgc_malloc(sizeof(t_gnl))) == NULL ||
	  (fle->fd = fd) == NULL)
	return (NULL);
      fle->csr = 0;
      fle->buff[0] = '\0';
      fle->status = NEOF;
      fle->buff[my_fread(fd, fle->buff, BUFFER_SIZE)] = '\0';
    }
  len = BUFFER_SIZE - fle->csr;
  if (BUFFER_SIZE <= 0 || (fle->status == MEOF) ||
      (line = gbgc_malloc(len + 2)) == NULL ||
      !(my_strncpy(fle->buff + fle->csr, line, len)))
    return (NULL);
  if (fle->status == MEOF && !is_line(fle->buff + fle->csr))
    return (extract_line(fle, fle->buff + fle->csr, BUFFER_SIZE - fle->csr));
  else if (fle->status == MEOF && fle->csr == BUFFER_SIZE)
    return (NULL);
  return (loop_gnl(fle, line, NULL, len));
}
