/*
** get_next_line.c for get_next_line in /home/tatanouu/rendu/CPE/CPE_2015_getnextline
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Fri Jan  8 16:49:03 2016 Antoine Zaczyk
** Last update Tue Feb 16 11:06:07 2016 Antoine Zaczyk
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/stat.h>
#include	 <fcntl.h>
#include	"get_next_line.h"
#include	"../include/my.h"

char		*my_malloc(char *line, int size)
{
  int		i;
  char		*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * (my_strlen(line) + (size + 1)));
  if (tmp == NULL)
    return (NULL);
  while (line[i] != '\0')
    {
      tmp[i] = line[i];
      i++;
    }
  free(line);
  return (tmp);
}

char		*create_my_buff(char *new, char *buffer)
{
  int		i;

  i = 0;

  new = malloc(sizeof(char) * READ_SIZE);
  if (new == NULL)
    return (NULL);
  while (i < my_strlen(buffer))
    {
      new[i] = buffer[i];
      i++;
    }
  return (new);
}

char		find_c(const int fd, char c)
{
  static char	buffer[READ_SIZE];
  static char	*new_buff;
  static int	rd = 0;
  static int	i = 0;

  if (fd == -1)
    return ('\0');
  if (rd == 0)
    {
      i = 0;
      while (i < READ_SIZE)
	buffer[i++] = 0;
      i = 0;
      rd = read(fd, buffer, READ_SIZE);
      if (rd <= 0)
	return ('\0');
      buffer[rd] = '\0';
      new_buff = create_my_buff(new_buff, buffer);
    }
  c = new_buff[i];
  rd--;
  i++;
  return (c);
}

char		*get_next_line(const int fd)
{
  char		c;
  char		*line;
  int		i;

  i = 0;
  c = 0;
  line = malloc(sizeof(char) * READ_SIZE + 1);
  if (line == NULL)
    return (NULL);
  c = find_c(fd, c);
  if (c == '\0')
    return (NULL);
  while (c != '\0' && c != '\n')
    {
      if (i % READ_SIZE == 0 && i != 0)
	line = my_malloc(line, READ_SIZE);
      line[i] = c;
      i++;
      c = find_c(fd, c);
    }
  line[i] = '\0';
  return (line);
}
