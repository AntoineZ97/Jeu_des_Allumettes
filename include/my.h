/*
** my.h for my.h in /home/tatanouu/rendu/CPE_2015_Allum1
**
** Made by Antoine Zaczyk
** Login   <tatanouu@epitech.net>
**
** Started on  Tue Feb  9 11:34:08 2016 Antoine Zaczyk
** Last update Sun Feb 21 01:12:18 2016 Antoine Zaczyk
*/

#ifndef		MY_H_
# define	MY_H

char		**create_my_map(void);
char		**str_to_wordtab(char *str);
int		show_my_map(char **map);
void		my_putchar(char c);
void		my_putstr(char *str);
char		*recup_line(char *turn, char **map);
int		my_getnbr(char *str);
char		**stop_game(char **map);
int		my_strlen(char *str);
void		my_put_nbr(int nb);
char		**user_turn(char **map);
int		check_my_map(char **map);
int		check_line(char **map, char *turn);
int		check_stick(char **map, char *str, int line);
int		my_getnbr(char *str);
int		check_number(char *str);
int		my_strlen(char *str);
void		print_ia_turn(int l, int c);
void		print_user_turn(char *str, int l);

#endif		/* MY_H_ */
