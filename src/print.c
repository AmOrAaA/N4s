/*
** print.c for print in /home/broscas/CPE_2016_n4s/n4s_package/src
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Fri May  5 11:00:47 2017 Ryan Granet
** Last update Tue May  9 09:40:29 2017 Ryan Granet
*/

#include "n4s.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
