/*
** my_print.c for print in /home/tatanouu/verif/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Sun Feb 21 01:06:55 2016 Antoine Zaczyk
** Last update Sun Feb 21 01:14:51 2016 Antoine Zaczyk
*/

#include	"../include/my.h"

void		print_ia_turn(int l, int c)
{
  my_putstr("AI removed ");
  my_put_nbr(c);
  my_putstr(" match(es) from line ");
  my_put_nbr(l);
  my_putchar('\n');
}

void		print_user_turn(char *str, int l)
{
  my_putstr("Player removed ");
  my_putstr(str);
  my_putstr(" match(es) from line ");
  my_put_nbr(l);
  my_putchar('\n');
}
