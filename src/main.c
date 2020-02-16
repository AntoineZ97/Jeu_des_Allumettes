/*
** main.c for main in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Mon Feb  8 15:27:13 2016 Antoine Zaczyk
** Last update Thu Feb 25 11:38:04 2016 Antoine Zaczyk
*/

#include	<stdlib.h>
#include	"../include/my.h"
#include	"../include/ia.h"

void		print_winner(int a)
{
  if (a == 1)
    my_putstr("You lost, too bad..\n");
  else
    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
}

int		main()
{
  char		**map;
  int		i;
  int		a;

  map = create_my_map();
  show_my_map(map);
  i = check_my_map(map);
  while (i != 0 && i != 100)
    {
      my_putstr("\nYour turn:");
      map = user_turn(map);
      i = check_my_map(map);
      a = 1;
      if (i != 0 && i != 100)
	{
	  map = ia_turn(map);
	  i = check_my_map(map);
	  a = 0;
	}
    }
  free(map);
  if (i == 100)
    return (0);
  print_winner(a);
  return (0);
}
