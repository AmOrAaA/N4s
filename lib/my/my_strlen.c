/*
** my_strlen.c for my_strlen in /home/Nyavenger/CPool_Day04
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Thu Oct  6 11:28:36 2016 Jonathan Delestre
** Last update Fri May  5 13:48:51 2017 Ryan Granet
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	lenght;

  if (str == NULL)
    return (0);
  lenght = 0;
  while (str[lenght] != '\0')
    lenght = lenght + 1;
  return (lenght);
}
