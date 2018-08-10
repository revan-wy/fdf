/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:59:01 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/07 20:47:28 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_index
{
	int i;
	int j;
}				t_index;

typedef struct	s_line
{
	float x;
	float y;
	float dx;
	float dy;
}				t_line;

typedef struct	s_coord
{
	float x0;
	float y0;
	float x1;
	float y1;
	float step;
}				t_coord;

typedef struct	s_arr
{
	int colmax;
	int rowmax;
	int max_z;
}				t_arr;

typedef struct	s_env
{
	void	*gsci;
	void	*window;
	int		winx;
	int		winy;
	float	unit;
	int		origin_y;
	int		pron;
	int		i;
	int		j;
}				t_env;

void			col_line_put(t_env *env, int j, int i, int **map);
void			get_size_of_map(t_arr *arr, char **argv);
int				key_event(int keycode, void *param);
void			line_put(t_env *env, t_coord coord);
void			map_line_error(char **argv);
void			print_map(t_arr *arr, int **map, t_env *env);
void			read_map(int **map, char **argv, t_arr *arr,
		t_env *env);
void			row_line_put(t_env *env, int j, int i, int **map);

#endif
