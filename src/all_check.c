/*
** all_check.c for  in /home/AmOrAA/Delivery/CPE_2016_n4s/n4s_package/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon May 29 18:36:19 2017 Florian Testu
** Last update Mon May 29 18:39:16 2017 Florian Testu
*/

#include "../include/n4s.h"

void	check_speed(t_val n4s)
{
  if (n4s.midle <= 1500 && n4s.right > 400 && n4s.left > 450)
    {
      my_put_dir("0\n");
      my_put_speed("0.8\n");
    }
  else if (n4s.midle <= 1250 && n4s.right > 400 && n4s.left > 450)
    {
      my_put_dir("0\n");
      my_put_speed("0.7/n\n");
    }
  else if (n4s.midle <= 1000 && n4s.right > 400 && n4s.left > 350)
    {
      my_put_dir("0\n");
      my_put_speed("0.6/n\n");
    }
  else if (n4s.midle <= 800 && n4s.right > 400 && n4s.left > 350)
    my_put_speed("0.3/n\n");
  else if (n4s.midle <= 600 && n4s.right > 350 && n4s.left > 300)
    my_put_speed("0.25/n\n");
  else if (n4s.midle <= 400 && n4s.right > 300 && n4s.left > 250)
    my_put_speed("0.2/n\n");
  else if (n4s.midle <= 200 && n4s.right > 200 && n4s.left > 200)
    my_put_speed("0.1/n\n");
}

void	check_dir(t_val n4s)
{
  if (n4s.left > n4s.right)
    {
      my_put_dir("0.2/n\n");
      my_put_speed("0.25/n\n");
    }
  else if (n4s.right > n4s.left)
    {
      my_put_dir("-0.2/n\n");
      my_put_speed("0.25/n\n");
    }
  if (n4s.midle <= 500 && n4s.right > n4s.left)
    {
      my_put_dir("-0.4/n\n");
      my_put_speed("0.05/n\n");
    }
  else if (n4s.midle <= 500 && n4s.right < n4s.left)
    {
      my_put_dir("0.4/n\n");
      my_put_speed("0.05/n\n");
    }
}
