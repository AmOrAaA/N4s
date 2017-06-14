/*
** wordtab.c for wordtab in /home/Broscas/CPE_2016_stumper3
** 
** Made by Ryan Granet
** Login   <Broscas@epitech.net>
** 
** Started on  Wed May  3 16:25:42 2017 Ryan Granet
** Last update Sat May 27 14:24:27 2017 Florian Testu
*/

#include <stdlib.h>
#include "n4s.h"

int	cnt_sep(char sep, char *str)
{
  int	i;
  int	s;

  i = -1;
  s = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == sep)
	s++;
    }
  return (s + 1);
}

int	strlen_sep(char *str, char sep)
{
  int	i;

  i = 0;
  while (str[i] != sep && str[i] != 0)
    i++;
  return (i);
}

void    my_putchar_save(char c, int fd)
{
  write(fd, &c, 1);
}

int     my_putnbr_save(int nb, int fd)
{
  if (nb < 0)
    {
      my_putchar_save('-', fd);
      nb = nb * -1;
    }
  if (nb >= 10)
    my_putnbr_save(nb / 10, fd);
  my_putchar_save((nb % 10) + 48, fd);
  return (0);
}

char	**wordtab_sep(char *str, char sep, int	fd)
{
  char **tab;
  int	i;
  int	x;
  int	y;
  int	a;

  x = y = i = 0;
  tab = malloc(sizeof(char *) * (cnt_sep(sep, str) + 1));
  my_putnbr_save(cnt_sep(sep, str) + 1, fd);
  while (y != cnt_sep(sep, str))
    {
      x = 0;
      a = strlen_sep(&str[i], sep);
      tab[y] = malloc(sizeof(char) * a + 2);
      while (x != a)
	{
	  tab[y][x] = str[i];
	  x++;
	  i++;
	}
      tab[y][x] = '\0';
      y++;
      i++;
    }
  tab[y] = NULL;
  return (tab);
}
