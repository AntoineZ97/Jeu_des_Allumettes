/*
** check.c for check in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Feb  9 15:00:42 2016 Antoine Zaczyk
** Last update Sun Feb 21 01:17:45 2016 Antoine Zaczyk
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"../include/my.h"

int		check_mystick(char **map, char *str, int line)
{
  int		i;
  int		N;
  int		c;

  c = 0;
  i = 0;
  N = my_getnbr(str);
  while (map[line][i])
    {
      if (map[line][i] == '|')
	c++;
      i++;
    }
  if (N > c || N == 0 || my_strlen(str) > 1)
    return (0);
  return (1);
}

int		check_stick(char **map, char *str, int line)
{
  if (str == '\0')
    return (100);
  if (check_number(str) == 1)
    {
      if (my_getnbr(str) == 0)
	{
	  if (str[0] == '\0')
	    my_putstr("Error: invalid input (positive number expected)");
	  else
	    my_putstr("Error: you have to remove at least one match");
	  return (1);
	}
      if (check_mystick(map, str, line) == 1)
	return (0);
      else
	my_putstr("Error: not enough matches on this line");
      return (1);
    }
  else if (check_number(str) == 2)
    my_putstr("Error: invalid input (positive number expected)");
  else
    my_putstr("Error: invalid input (positive number expected)");
  return (1);
}

int		check_col(char **map, char *str)
{
  int		l;
  int		i;

  i = 0;
  l = my_getnbr(str);
  if (l > 4 || l == 0)
    return (0);
  while (map[l][i])
    {
      if (map[l][i] == '|')
	return (1);
      else
	i++;
    }
  if (l >= 1 && l <= 4)
    return (2);
  return (0);
}

int		check_number(char *str)
{
  int		i;

  i = 0;
  if (my_strlen(str) > 10)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else if (str[i] == '-')
	return (2);
      else
	return (0);
    }
  return (1);
}

int		check_line(char **map, char *turn)
{

  if (turn == '\0')
    return (100);
  if (check_number(turn) == 1 && turn[0] != '\0')
    {
      if (check_col(map, turn) == 1)
	return (0);
      else if (check_col(map, turn) == 2)
	my_putstr("Error: this line is empty");
      else
	my_putstr("Error: this line is out of range");
      return (1);
    }
  else if (check_number(turn) == 2)
    my_putstr("Error: invalid input (positive number expected)");
  else
    my_putstr("Error: invalid input (positive number expected)");
  return (1);
}
