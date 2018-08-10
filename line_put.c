/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 19:31:22 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/07 19:59:48 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_put(t_env *env, t_coord coord)
{
	t_line	line;
	int		i;

	i = 0;
	line.dx = (coord.x1 - coord.x0);
	line.dy = (coord.y1 - coord.y0);
	if (fabs(line.dx) >= fabs(line.dy))
		coord.step = fabs(line.dx);
	else
		coord.step = fabs(line.dy);
	line.dx = line.dx / coord.step;
	line.dy = line.dy / coord.step;
	line.x = coord.x0;
	line.y = coord.y0;
	i = 1;
	while (i <= coord.step)
	{
		mlx_pixel_put(env->gsci, env->window, line.x, line.y, 0x00FFFFFF);
		line.x = line.x + line.dx;
		line.y = line.y + line.dy;
		i++;
	}
}

void	row_line_put(t_env *env, int j, int i, int **map)
{
	t_coord coord;

	coord.x0 = (j + i) * (env->unit / tan(30 * 0.0174533)) + 100;
	coord.y0 = (i - j) * env->unit - env->unit * map[i][j] * env->pron / 100
		+ env->origin_y;
	coord.x1 = (j + i + 1) * (env->unit / tan(30 * 0.0174533)) + 100;
	coord.y1 = (i - j + 1) * env->unit - env->unit * map[i + 1][j] * env->pron /
		100 + env->origin_y;
	line_put(env, coord);
}

void	col_line_put(t_env *env, int j, int i, int **map)
{
	t_coord coord;

	coord.x0 = (j + i) * (env->unit / tan(30 * 0.0174533)) + 100;
	coord.y0 = (i - j) * env->unit - env->unit * map[i][j] * env->pron / 100 +
		env->origin_y;
	coord.x1 = (j + i + 1) * (env->unit / tan(30 * 0.0174533)) + 100;
	coord.y1 = (i - j - 1) * env->unit - env->unit * map[i][j + 1] * env->pron /
		100 + env->origin_y;
	line_put(env, coord);
}
