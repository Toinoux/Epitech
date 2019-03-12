/*
** my.h for my.h in /home/lyliya/rendu/maths/103architect
** 
** Made by Guillaume
** Login   <lyliya@epitech.net>
** 
** Started on  Wed Dec 14 18:43:12 2016 Guillaume
** Last update Fri Dec 16 16:39:25 2016 Guillaume
*/

#ifndef MY_H_
# define MY_H_

typedef struct	t_struct
{
  float	x;
  float	y;
  float xres;
  float	yres;
  float r1;
  float t1;
  float t2;
  float h1;
  float h2;
  float s1;
  float	*res;
  float	**identity;
  float	**res_identity;
}		s_struct;

float	**create_matrice_trans(float **, float, float);
float	**create_matrice_hom(float **, float, float);
float	**create_matrice_sym(float **, float);
float	**create_matrice_rot(float **, float);
void	calcul_matrice_id(float **, s_struct *);
void	matrice_x_coord(s_struct *);

#endif /* !MY_H_ */
