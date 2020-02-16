/*
** map.c for map in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Mon Feb  8 15:13:57 2016 Antoine Zaczyk
** Last update Sun Feb 21 00:38:24 2016 Antoine Zaczyk
*/

#include	<stdlib.h>
#include	"../include/my.h"

char		**create_my_map(void)
{
  char		*tmp;
  char		**map;

  tmp = "*********\n*   |   *\n*  |||  *\n* ||||| *\n*|||||||*\n*********\n";
  map = str_to_wordtab(tmp);
  return (map);
}

int		show_my_map(char **map)
{
  int		i;

  i = 0;

  if (map[0][0] == '\0')
    return (0);
  while (i < 6)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
}

char		**stop_game(char **map)
{
  free(map);
  map = malloc(sizeof(char**));
  map = '\0';
  return (map);
}

int		check_my_map(char **map)
{
  int		i;
  int		c;
  int		baton;

  baton = 0;
  i = 1;
  c = 0;
  if (map == '\0' || map == NULL)
    {
      i = 100;
      return (i);
    }
  while (i < 6)
    {
      while (map[i][c] != '\0')
	{
	  if (map[i][c] == '|')
	    baton++;
	  c++;
	}
      i++;
      c = 0;
    }
  return (baton);
}
