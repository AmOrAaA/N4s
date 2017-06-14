/*
** all_str_to_word.c for  in /home/amoraa/Delivery/CPE_2016_n4s/n4s_package/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat May 27 14:03:39 2017 Florian Testu
** Last update Sat May 27 14:52:55 2017 Florian Testu
*/

#include "../include/n4s.h"

int	take_size(char *str, int *i)
{
  int	x;
  int	j;
  
  i[0] = x = 0;
  while (str[++i[0]] < '0' || str[i[0]] > '9')
    {
      if (str[i[0]] == '\n' && str[i[0] + 1] >= '0' && str[i[0] + 1] <= '9')
        i[0]++;
    }
  j = i[0];
  while (str[i[0]++] != '\0')
    x++;
  i[0] = --j;
  return (x);
}

char    *my_str_wordstr(char *str)
{
  char  *copy;
  int   i;
  int   j;

  j = take_size(str, &i);
  copy = malloc(sizeof(char) * j + 1);
  j = -1;
  while (str[i++] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        {
          if (str[i] == '.' || str[i] == ':')
            copy[++j] = str[i];
          else
	    break;
        }
      else
        copy[++j] = str[i];
    }
  copy[j] = '\0';
  free(str);
  return (copy);
}

int     my_strlen_at_the_line(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ':')
        j = j + 1;
      i = i + 1;
    }
  return (j + 1);
}

int     my_len_space(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0' && str[i] != ':')
    i = i + 1;
  return (i);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   i;
  int   j;
  int   a;

  a = j = 0;
  if ((tab = malloc(sizeof(char*) * my_strlen_at_the_line(str) + 1)) == NULL)
    return (NULL);
  while (str[a] == ' ' || str[a] == '\t')
    a++;
  while (str[a] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * my_len_space(&str[a]) + 2)) == NULL)
        return (NULL);
      i = -1;
      while (my_len_space(&str[a]) != 0)
        tab[j][++i] = str[a++];
      tab[j][i + 1] = '\0';
      j = j + 1;
      if (str[a] != '\0')
        a = a + 1;
    }
  tab[j] = NULL;
  free(str);
  return (tab);
}
