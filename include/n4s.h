/*
** n4s.h for n4s in /home/broscas/CPE_2016_n4s/n4s_package/include
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Fri May  5 11:04:49 2017 Ryan Granet
** Last update Tue May 30 13:15:25 2017 Ryan Granet
*/

#ifndef NFS_H_
# define NFS_H_

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
//# include "SFML/Audio/Music.h"

typedef	struct		s_val
{
  char			*str;
  char			**tab;
  int			left;
  int			left_second;
  int			right;
  int			right_second;
  int			midle;
}			t_val;

void	my_putchar(char);
void	my_putstr(char *);
void	ai();
void	slow_car(char **);
void	free_tab(char **);
void	check_speed(t_val);
void	check_dir(t_val);
void	my_put_speed(char *);
void	my_put_dir(char *);

float	str_to_float(char *);

int	main();
int	check_wall(int);
int	cnt_sep(char, char *);
int	strlen_sep(char *, char);
int	my_strlen(char *);
int	track_cleared(char *);
int	my_endcmp(char *, char *);
int	my_getfloat(char *);
int	check_str(char *);

char	*my_str_wordstr(char *);

char	**my_str_to_wordtab(char *);
char	**wordtab_sep(char *, char, int);

#endif	/* NFS_H_ */
