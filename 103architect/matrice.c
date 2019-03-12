/*
** matrice.c for matrice.c in /home/lyliya/rendu/maths/102cipher
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Wed Dec 14 18:25:57 2016 Guillaume
** Last update Sun Dec 18 18:57:28 2016 Guillaume
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

float	**create_matrice_trans(float **send, float x, float y)
{
  int   i;
  int   j;

  i = 0;
  send = malloc(sizeof(float *) * 3);
  while (i != 3)
    {
      j = 0;
      send[i] = malloc(sizeof(float) * 3);
      while (j != 3)
	send[i][j++] = 0;
      i += 1;
    }
  send[0][0] = 1;
  send[1][1] = 1;
  send[2][2] = 1;
  send[1][2] = y;
  send[0][2] = x;
  return (send);
}

float	**create_matrice_rot(float **send, float angle)
{
  int   i;
  int   j;

  i = 0;
  send = malloc(sizeof(float *) * 3);
  while (i != 3)
    {
      j = 0;
      send[i] = malloc(sizeof(float) * 3);
      while (j != 3)
	send[i][j++] = 0;
      i += 1;
    }
  send[0][0] = cosf(angle * (M_PI / 180));
  send[0][1] = -sinf(angle * (M_PI / 180));
  send[1][0] = sinf(angle * (M_PI / 180));
  send[1][1] = cosf(angle * (M_PI / 180));
  send[2][2] = 1;
  return (send);
}

float    **create_matrice_hom(float **send, float m, float n)
{
  int   i;
  int   j;

  i = 0;
  send = malloc(sizeof(float *) * 3);
  while (i != 3)
    {
      j = 0;
      send[i] = malloc(sizeof(float) * 3);
      while (j != 3)
	send[i][j++] = 0;
      i += 1;
    }
  send[0][0] = m;
  send[1][1] = n;
  send[2][2] = 1;
  return (send);
}

float    **create_matrice_sym(float **send, float angle)
{
  int   i;
  int   j;

  i = 0;
  send = malloc(sizeof(float *) * 3);
  while (i != 3)
    {
      j = 0;
      send[i] = malloc(sizeof(float) * 3);
      while (j != 3)
	send[i][j++] = 0;
      i += 1;
    }
  send[0][0] = cosf(2 * (angle * (M_PI / 180)));
  send[0][1] = sinf(2 * (angle * (M_PI / 180)));
  send[1][0] = sinf(2 * (angle * (M_PI / 180)));
  send[1][1] = -cosf(2 * (angle * (M_PI / 180)));
  send[2][2] = 1;
  return (send);
}

void	calcul_matrice_id(float **matrice, s_struct *s)
{
  s->res_identity[0][0] = matrice[0][0] * s->identity[0][0] + matrice[0][1] * s->identity[0][1] + matrice[0][2] * s->identity[2][0];
  s->res_identity[0][1] = matrice[0][0] * s->identity[1][0] + matrice[0][1] * s->identity[1][1] + matrice[0][2] * s->identity[2][1];
  s->res_identity[0][2] = matrice[0][0] * s->identity[2][0] + matrice[0][1] * s->identity[2][1] + matrice[0][2] * s->identity[2][2];

  s->res_identity[1][0] = matrice[1][0] * s->identity[0][0] + matrice[1][1] * s->identity[0][1] + matrice[1][2] * s->identity[2][0];
  s->res_identity[1][1] = matrice[1][0] * s->identity[1][0] + matrice[1][1] * s->identity[1][1] + matrice[1][2] * s->identity[2][1];
  s->res_identity[1][2] = matrice[1][0] * s->identity[2][0] + matrice[1][1] * s->identity[2][1] + matrice[1][2] * s->identity[2][2];

  s->res_identity[2][0] = matrice[2][0] * s->identity[0][0] + matrice[2][1] * s->identity[0][1] + matrice[2][2] * s->identity[2][0];
  s->res_identity[2][1] = matrice[2][0] * s->identity[1][0] + matrice[2][1] * s->identity[1][1] + matrice[2][2] * s->identity[2][1];
  s->res_identity[2][2] = matrice[2][0] * s->identity[2][0] + matrice[2][1] * s->identity[2][1] + matrice[2][2] * s->identity[2][2];
}

void	matrice_x_coord(s_struct *s)
{
  int	x;
  int	y;

  y = s->yres;
  x = s->xres;
  s->xres = x * s->res_identity[0][0] + y * s->res_identity[0][1] + 1 * s->res_identity[0][2];
  s->yres = x * s->res_identity[1][0] + y * s->res_identity[1][1] + 1 * s->res_identity[1][2];
}
