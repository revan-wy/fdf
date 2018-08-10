/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:02:19 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/10 16:38:14 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_size_of_map(t_arr *arr, char **argv)
{
	int		fd;
	char	*pnl;
	int		res;

	if (!(fd = open(argv[1], O_RDONLY)) || fd == -1)
	{
		write(1, "File name not valid\n", 20);
		exit(0);
	}
	res = 1;
	while (res)
	{
		res = get_next_line(fd, &pnl);
		if (ft_strlen(pnl))
			arr->rowmax++;
		if (!arr->colmax)
			arr->colmax = ft_getwcntsd(pnl, ' ');
		else if (res)
			if (ft_getwcntsd(pnl, ' ') != arr->colmax)
				map_line_error(argv);
		free(pnl);
	}
	close(fd);
}

void	map_line_error(char **argv)
{
	ft_putstr("Map size inconsistent across lines of map file: ");
	ft_putstr(argv[1]);
	ft_putchar('\n');
	exit(0);
}

void	print_map(t_arr *arr, int **map, t_env *env)
{
	t_index index;

	index.i = 0;
	index.j = 0;
	while (index.i < arr->rowmax)
	{
		index.j = 0;
		while (index.j < arr->colmax)
		{
			if (index.j < arr->colmax - 1)
				col_line_put(env, index.j, index.i, map);
			if (index.i < arr->rowmax - 1)
				row_line_put(env, index.j, index.i, map);
			index.j++;
		}
		index.i++;
	}
}

void	read_map(int **map, char **argv, t_arr *arr, t_env *env)
{
	int		fd;
	char	*pnl;
	int		res;
	char	**one_line_fields;

	env->i = -1;
	env->j = 0;
	fd = open(argv[1], O_RDONLY);
	res = 1;
	while (res && ++env->i < arr->rowmax)
	{
		env->j = 0;
		res = get_next_line(fd, &pnl);
		one_line_fields = ft_strsplit(pnl, ' ');
		while (*one_line_fields != NULL && env->j < arr->colmax)
		{
			map[env->i][env->j] = ft_atoi(one_line_fields[env->j]);
			free(one_line_fields[env->j]);
			if (abs(env->i - env->j - map[env->i][env->j++]) >
					abs(arr->max_z))
				arr->max_z = env->i - (env->j - 1) - map[env->i][env->j - 1];
		}
		free(pnl);
		free(one_line_fields);
	}
}
