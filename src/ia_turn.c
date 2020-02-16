/*
** user_turn.c for user in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Feb  9 14:53:40 2016 Antoine Zaczyk
** Last update Thu Feb 25 11:38:31 2016 Antoine Zaczyk
*/

#include	<stdlib.h>
#include	<time.h>
#include	"../include/ia.h"
#include	"../include/my.h"

int		check_rand(int n, char **map)
{
  int		i;

  i = 0;
  while (map[n][i] != '\0')
    {
      if (map[n][i] == '|')
	return (1);
      else
	i++;
    }
  return (0);
}

int		check_rand_stick(int n, int x, char **map)
{
  int		i;
  int		v;

  i = 0;
  v = 0;
  if (x == 0)
    return (0);
  while (map[n][i] != '\0')
    {
      if (map[n][i] == '|')
	v++;
      i++;
    }
  if (v >= x)
    return (1);
  else
    return (0);
}

char		**ia_map(int l, int c, char **map)
{
  int		i;

  i = 8;
  while (c != 0 && i != 0)
    {
      if (map[l][i] == '|')
	{
	  map[l][i] = ' ';
	  c--;
	}
      i--;
    }
  return (map);
}

char		**ia_rand(char **map)
{
  int		n;
  int		x;

  srand(time(NULL));
  n = rand() % 6;
  while (check_rand(n, map) == 0)
    n = rand() % 6;
  x = rand() % 9;
  while (check_rand_stick(n, x, map) == 0)
    x = rand() % 9;
  map = ia_map(n, x, map);
  print_ia_turn(n, x);
  return (map);
}

char		**ia_turn(char **map)
{
  my_putstr("\nAI's turn...\n");
  map = ia_rand(map);
  show_my_map(map);
  return (map);
}
