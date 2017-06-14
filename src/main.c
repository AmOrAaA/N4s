/*
** main.c for main in /home/broscas/CPE_2016_n4s/n4s_package/src
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Fri May  5 11:20:55 2017 Ryan Granet
** Last update Sat May 27 14:16:20 2017 Florian Testu
*/

#include "../include/n4s.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}

char	*my_str_wordstr(char *str)
{
  char	*copy;
  int	i;
  int	j;
  int	x;

  i = x = 0;
  while (str[++i] && str[i] < '0' || str[i] > '9')
    {
      if (str[i] == '\n' && str[i + 1] >= '0' && str[i + 1] <= '9')
	i++;
    }
  j = i;
  while (str[i++] != '\0')
    x++;
  copy = malloc(sizeof(char) * x + 1);
  i = --j;
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

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
   free(tab[i]);
  free(tab);
}

int	my_getfloat(char *str)
{
  int	i;
  int	odg;
  int	nb;

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

int	check_str(char *str)
{
  int	i;

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

char	*my_put_speed(char *val)
{
  int	ret;
  char	*error;

  if ((error = malloc(sizeof(char) * 4096)) != NULL)
    return (NULL);
  my_putstr("CAR_FORWARD:");
  my_putstr(val);
  my_putstr("/n\n");
  ret = read(0, error, 999);
  error[ret] = '\0';
  write(2, error, my_strlen(error));
  free(error);
}

char	*my_put_direct(char *val)
{
  int	ret;
  char	*error;

  if ((error = malloc(sizeof(char) * 4096)) != NULL)
    return (NULL);
  my_putstr("WHEELS_DIR:");
  my_putstr(val);
  my_putstr("/n\n");
  ret = read(0, error, 999);
  error[ret] = '\0';
  write(2, error, my_strlen(error));
  free(error);
}

char	*algo(int midle)
{
  int	ret;
  char	*error;
  if (midle <= 1500)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:1\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 1250)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.8/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 1000)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.6/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 800)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.4/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 600)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.2/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 400)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.1/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
  else if (midle <= 200)
    {
      if ((error = malloc(sizeof(char) * 4096)) == NULL)
	return (NULL);
      my_putstr("CAR_FORWARD:0.1/n\n");
      ret = read(0, error, 999);
      error[ret] = '\0';
      write(2, error, my_strlen(error));
      free(error);
    }
}

void	test()
{
  FILE *fichier = fopen ("test.txt", "w");
  char	*str;
  char	error[4096];
  char	**tab;
  int	begin;
  int	midle;
  int	end;
  int	i;
  int	ret;

  my_putstr("CAR_FORWARD:1\n");
  while (1)
    {
      my_putstr("GET_INFO_LIDAR\n");
      str = get_next_line(0);
      if (check_str(str) != 0);
      else
      	{
      	  str = my_str_wordstr(str);
      	  tab = my_str_to_wordtab(str);
	  i = -1;
	  while (tab[++i] != NULL)
      	  begin = my_getfloat(tab[0]);
      	  midle = my_getfloat(tab[i / 2]);
      	  end = my_getfloat(tab[i - 1]);
	  if (begin > end)
	    {
	      /* my_put_direct("0.20/n\n"); */
	      /* my_put_speed("0.25/n\n"); */
	      my_putstr("WHEELS_DIR:0.20/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	      my_putstr("CAR_FORWARD:0.25/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	    }
	  else if (end > begin)
	    {
	      my_putstr("WHEELS_DIR:-0.20/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	      my_putstr("CAR_FORWARD:0.25/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	    }
	  else if (end > 150)
	    {
	      my_putstr("WHEELS_DIR:0.50/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0'; /*  */
	      write(2, error, my_strlen(error));
	      my_putstr("CAR_FORWARD:0.15/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));

	    }
	  else if (begin < 150)
	    {
	      my_putstr("WHEELS_DIR:-0.50/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	      my_putstr("CAR_FORWARD:0.15/n\n");
	      ret = read(0, error, 999);
	      error[ret] = '\0';
	      write(2, error, my_strlen(error));
	    }
	  /* else */
	  /*   my_putstr("CAR_FORWARD:1\n"); */
      	  free_tab(tab);
      	}
    }
}
