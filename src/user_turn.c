/*
** user_turn.c for user in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Feb  9 14:53:40 2016 Antoine Zaczyk
** Last update Sun Feb 21 01:15:05 2016 Antoine Zaczyk
*/

#include	<stdlib.h>
#include	"../include/my.h"
#include	"../include/get_next_line.h"

char		**update_map(char **map, char *str, int line)
{
  int		i;
  int		N;

  i = 8;
  N = my_getnbr(str);
  while (N != 0 && i != 0)
    {
      if (map[line][i] == '|')
	{
	  map[line][i] = ' ';
	  N--;
	}
      i--;
    }
  return (map);
}

char		**do_user(char **map, char *turn, int l)
{
  print_user_turn(turn, l);
  map = update_map(map, turn, l);
  show_my_map(map);
  return (map);
}

char		*recup_line(char *turn, char **map)
{
  turn = get_next_line(0);
  while (check_line(map, turn) == 1)
    {
      my_putstr("\nLine: ");
      turn = get_next_line(0);
    }
  return (turn);
}

char		**user_turn(char **map)
{
  int		l;
  char		*turn;
  int		a;

  turn = '\0';
  my_putstr("\nLine: ");
  turn = recup_line(turn, map);
  if (check_line(map, turn) == 100)
    {
      map = stop_game(map);
      return (map);
    }
  l = my_getnbr(turn);
  my_putstr("Matches: ");
  turn = get_next_line(0);
  if ((a = check_stick(map, turn, l)) == 1)
    map = user_turn(map);
  else if (a == 100)
    map = stop_game(map);
  else
    map = do_user(map, turn, l);
  return (map);
}
