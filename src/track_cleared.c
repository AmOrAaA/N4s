/*
** track_cleared.c for ai in /home/broscas/CPE_2016_n4s/n4s_package/src
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Sat May 27 14:04:14 2017 Ryan Granet
** Last update Sat May 27 14:54:05 2017 Ryan Granet
*/

#include "n4s.h"

int	track_cleared(char *info)
{
  int	i;

  i = 0;
  while (info[i] != '\0')
    {
      if (info[i] == ':' && info[i + 1] == 'T')
	{
	  if ((my_endcmp(&info[++i], "Track Cleared")) == 0)
	    return (1);
	}
      i++;
    }
  return (0);
}

int	my_endcmp(char *info, char *end_mess)
{
  int	i;

  i = 0;
  while (end_mess[i] != '\0')
    {
      if (info[i] != end_mess[i])
	return (1);
      i++;
    }
  return (0);
}
