/*
** basic_function.c for basic machin in /home/tatanouu/rendu/PSU/PSU_2015_minishell1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Mon Jan 18 17:14:58 2016 Antoine Zaczyk
** Last update Tue Feb  9 11:36:07 2016 Antoine Zaczyk
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int		my_getnbr(char *str)
{
  int		count;
  int		s;
  int		nbr;

  s = 1;
  count = 0;
  while (str[count] != '\0' && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	{
	  s = s * -1;
	}
      count = count + 1;
    }
  str = str + count;
  nbr = 0;
  count = 0;
  while (str[count] >= '0' && str[count] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[count] - '0');
      count = count + 1;
    }
  return (nbr * s * -1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void		my_put_nbr(int nb)
{
  if (nb > 9)
    my_put_nbr(nb / 10);
  else if (nb < 0)
    {
      nb = nb * -1;
      write(1, "-", 1);
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0');
}
