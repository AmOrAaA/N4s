/*
** my_ai.c for  in /home/amoraa/Delivery/CPE_2016_n4s/n4s_package/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat May 27 13:50:49 2017 Florian Testu
** Last update Sat Jun  3 00:16:50 2017 Florian Testu
*/

#include "../include/n4s.h"
//# include "SFML/Audio/Music.h"

void	my_put_speed(char *val)
{
  int   ret;
  char  error[4096];

  my_putstr("CAR_FORWARD:");
  my_putstr(val);
  ret = read(0, error, 999);
  error[ret] = '\0';
  write(2, error, my_strlen(error));
}

void	my_put_dir(char *val)
{
  int   ret;
  char  error[4096];

  my_putstr("WHEELS_DIR:");
  my_putstr(val);
  ret = read(0, error, 999);
  error[ret] = '\0';
  write(2, error, my_strlen(error));
}

int	racing(t_val n4s)
{
  int	i;
  
  n4s.str = my_str_wordstr(n4s.str);
  n4s.tab = my_str_to_wordtab(n4s.str);
  i = -1;
  while (n4s.tab[++i] != NULL);
  n4s.left = my_getfloat(n4s.tab[0]);
  n4s.midle = my_getfloat(n4s.tab[i / 2]);
  n4s.right = my_getfloat(n4s.tab[i - 1]);
  check_speed(n4s);
  check_dir(n4s);
  free_tab(n4s.tab);
  return (0);
}

int		loop()
{
  t_val		n4s;
  int		ret;
  char		error[4096];

  my_putstr("CAR_FORWARD:1\n");
  ret = read(0, error, 999);
  error[ret] = '\0';
  write(2, error, my_strlen(error));  
  while (1)
    {
      my_putstr("GET_INFO_LIDAR\n");
      n4s.str = get_next_line(0);
      if (track_cleared(n4s.str) == 1)
	{
	  my_putstr("CAR_FORWARD:0\n");
	  ret = read(0, error, 999);
	  error[ret] = '\0';
	  write(2, error, my_strlen(error));
	  return (0);
	}
      if (check_str(n4s.str) != 0);
      else
	racing(n4s);
    }
  return (0);
}

int		main()
{
  sfMusic       *music;

  music = sfMusic_createFromFile("SFA_Gran_turismo_3_2_1_Go_sound_effect.ogg");
  sfMusic_play(music);
  sleep(4);
  music = sfMusic_createFromFile("GBA_Mario_Circuit_-_Mario_Kart_8_Music_Extended.ogg");
  sfMusic_play(music);
  my_putstr("START_SIMULATION\n");
  loop();
  my_putstr("STOP_SIMULATION\n");
  return (0);
}
