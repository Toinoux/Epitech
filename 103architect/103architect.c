/*
** 103architect.c for architect in /home/lyliya/rendu/maths/103architect
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Tue Dec  6 13:44:20 2016 Guillaume
** Last update Sun Dec 18 19:39:23 2016 Guillaume
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	init_struct(s_struct *s)
{
  int	i;
  int	j;

  i = 0;
  s->x = 0;
  s->y = 0;
  s->r1 = 0;
  s->t1 = 0;
  s->t2 = 0;
  s->h1 = 0;
  s->h2 = 0;
  s->s1 = 0;
  s->res = malloc(sizeof(float) * 2);
  s->identity = malloc(sizeof(float *) * 2);
  if (s->res == NULL)
    exit(84);
  while (i != 3)
    {
      j = 0;
      while (j != 3)
	{
	  s->identity[i] = malloc(sizeof(float) * 2);
	  if (s->identity[i] == NULL)
	    exit(84);
	  s->identity[i][j++] = 0;
	}
      i += 1;
    }
  s->identity[0][0] = 1;
  s->identity[1][1] = 1;
  s->identity[2][2] = 1;
  s->res_identity = malloc(sizeof(float *) * 2);
  if (s->res == NULL)
    exit(84);
  i = 0;
  while (i != 3)
    {
      j = 0;
      while (j != 3)
	{
	  s->res_identity[i] = malloc(sizeof(float) * 2);
	  if (s->res_identity == NULL)
	    exit(84);
	  s->res_identity[i][j++] = 0;
	}
      i += 1;
    }
  s->res_identity[0][0] = 1;
  s->res_identity[1][1] = 1;
  s->res_identity[2][2] = 1;
}

void	print_matrice(float **matrice)
{
  int	i;
  int	j;

  i = 0;
  while (i != 3)
    {
      j = 0;
      while (j != 3)
	{
	  if (matrice[i][j] > -0.01 && matrice[i][j] < 0)
	    matrice[i][j] *= -1;
	  printf("%.2f", matrice[i][j++]);
	  if (j != 3)
	    printf("\t");
	}
      printf("\n");
      i += 1;
    }
}

void	hom(s_struct *s)
{
  float	**matrice;

  matrice = malloc(sizeof(void));
  matrice = create_matrice_hom(matrice, s->h1, s->h2);
  calcul_matrice_id(matrice, s);
  matrice_x_coord(s);
  printf("Homothety by the ratios %i and %i\n", (int) s->h1, (int) s->h2);
}

void	translation(s_struct *s)
{
  float	**matrice;

  matrice = malloc(sizeof(void));
  matrice = create_matrice_trans(matrice, s->t1, s->t2);
  calcul_matrice_id(matrice, s);
  matrice_x_coord(s);
  printf("Translation by the vector (%i, %i)\n", (int) s->t1, (int) s->t2);
}

void	rotation(s_struct *s)
{
  float	**matrice;

  matrice = malloc(sizeof(void));
  matrice = create_matrice_rot(matrice, s->r1);
  calcul_matrice_id(matrice, s);
  matrice_x_coord(s);
  printf("Rotation at a %i degree angle\n", (int) s->r1);
}

void	sym(s_struct *s)
{
  float	**matrice;
  
  matrice = malloc(sizeof(void));
  matrice = create_matrice_sym(matrice, s->s1);
  calcul_matrice_id(matrice, s);
  matrice_x_coord(s);
  printf("Symmetry about an axis inclined with an angle of %i degrees\n", (int) s->s1);
}

int	check_nb(char **argv, int pos)
{
  int	i;

  i = 0;
  if (argv[pos][0] == '-')
    i += 1;
  while (argv[pos][i] != '\0')
    {
      if (argv[pos][i] >= '0' && argv[pos][i] <= '9')
	i += 1;
      else
	exit(84);
    }
  return (0);
}

int	check_argc(int argc, char **argv)
{
  int	i;

  i = 1;
  while (i != argc)
    {
      if (argv[i][0] == '-')
	{
	  if (argv[i][1] == 'r' && i + 1 < argc)
	    {
	      check_nb(argv, i + 1);
	      if (i + 2 < argc)
		{
		  if (argv[i + 2][0] != '-')
		    exit(84);
		}
	      i += 1;
	    }
	  else if (argv[i][1] == 't' && i + 1 < argc && i + 2 < argc)
	    {
	      check_nb(argv, i + 1);
	      check_nb(argv, i + 2);
	      if (i + 3 < argc)
		{
		  if (argv[i + 3][0] != '-')
		    exit(84);
		}
	      i += 1;
	    }
	  else if (argv[i][1] == 's' && i + 1 < argc)
	    {
	      check_nb(argv, i + 1);
	      if (i + 2 < argc)
		{
		  if (argv[i + 2][0] != '-')
		    exit(84);
		}
	      i += 1;
	    }
	  else if (argv[i][1] == 'h' && i + 1 < argc && i + 2 < argc)
	    {
	      check_nb(argv, i + 1);
	      check_nb(argv, i + 2);
	      if (i + 3 < argc)
		{
		  if (argv[i + 3][0] != '-')
		    exit(84);
		}
	      i += 1;
	    }
	  else
	    {
	      check_nb(argv, i);
	      i += 1;
	    }
	}
      else
	{
	  check_nb(argv, i);
	  i += 1;
	}
    }
  return (0);
}

int	exec(s_struct *s, int argc, char **argv)
{
  int	i;

  i = 3;
  while (i != argc)
    {
      if (argv[i][0] == '-')
	{
	  if (argv[i][1] == 'r')
	    {
	      s->r1 = atof(argv[i + 1]);
	      rotation(s);
	      i += 2;
	    }
	  else if (argv[i][1] == 't')
	    {
	      s->t1 = atof(argv[i + 1]);
	      s->t2 = atof(argv[i + 2]);
	      translation(s);
	      i += 3;
	    }
	  else if (argv[i][1] == 's')
	    {
	      s->s1 = atof(argv[i + 1]);
	      sym(s);
	      i += 2;
	    }
	  else if (argv[i][1] == 'h')
	    {
	      s->h1 = atof(argv[i + 1]);
	      s->h2 = atof(argv[i + 2]);
	      hom(s);
	      i += 3;
	    }
	  else
	    exit(84);
	}
      else
	exit(84);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  s_struct	s;

  if (argc < 5)
    return (84);
  check_nb(argv, 1);
  check_nb(argv, 2);
  init_struct(&s);
  s.x = atof(argv[1]);
  s.y = atof(argv[2]);
  s.xres = atof(argv[1]);
  s.yres = atof(argv[2]);
  check_argc(argc, argv);
  exec(&s, argc, argv);
  print_matrice(s.res_identity);
  if (s.xres > -0.01 && s.xres < 0)
    s.xres *= -1;
  if (s.yres > -0.01 && s.yres < 0)
    s.yres *= -1;
  printf("(%i,%i) => (%.2f,%.2f)\n", (int) s.x, (int) s.y, s.xres, s.yres);
  return (0);
}
