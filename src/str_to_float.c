/*
** str_to_float.c for nfs in /home/broscas/CPE_2016_n4s/n4s_package/src
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Mon May  8 23:23:59 2017 Ryan Granet
** Last update Sat May 27 14:25:55 2017 Florian Testu
*/

#include "n4s.h"

float	str_to_float(char *str)
{
  float	result;
  int	x;
  int	i;

  i = x = 0;
  result = 0.0;
  while (str[x] != '\0' && str[x] <= '9' && str[x] >= '0')
    {
      result = result * 10.0 + (str[x] - 48);
      x++;
      printf("lil = %f\n", result);
    }
  if (str[x++] == '.')
    {
      while (str[x] != '\0' && str[x] <= '9' && str[x] >= '0')
  	{
  	  result = result * 10.0 + (str[x] - 48);
  	  i++;
  	  x++;
  	  printf("lel = %f\n", result);
  	}
      printf("i = %d\n", i);
      while (i-- != 0)
  	{
  	  printf("lol = %f\n", result);
  	  result = result / 10;
  	}
    }
  return (result);
}
