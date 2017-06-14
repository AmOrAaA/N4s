/*
** parse_str.c for  in /home/amoraa/Delivery/CPE_2016_n4s/n4s_package/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat May 27 15:24:45 2017 Florian Testu
** Last update Sat May 27 15:25:20 2017 Florian Testu
*/

#include "../include/n4s.h"

int     check_str(char *str)
{
  int   i;

  i = 0;
  while (str[++i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
        return (0);
      if (str[24] < '0' || str[24] > '9')
        return (84);
    }
  return (84);
}

int     my_getfloat(char *str)
{
  int   i;
  int   odg;
  int   nb;

  i = 0;
  nb = 0;
  odg = 1;
  if (str == NULL)
    return (0);
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
        odg = odg * -1;
      i++;
    }
  while (str[i] != '.' && str[i] >= '0' && str[i] <= '9')
    {
      if (str[i] == '\0')
        break;
      nb = nb * 10 + str[i] - 48;
      i++;
    }
  nb = nb * odg;
  return (nb);
}

void    free_tab(char **tab)
{
  int   i;

  i = -1;
  while (tab[++i] != NULL)
   free(tab[i]);
  free(tab);
}
