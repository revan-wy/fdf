/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:05:45 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/09 19:36:45 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_unit_origin_y(t_arr arr, t_env *env)
{
	float posx;
	float posy;

	posx = 0;
	posy = 0;
	while (posx * (arr.rowmax + arr.colmax) / tan(30 * 0.0174533) + 200 <
			env->winx)
		posx += 0.1;
	posx -= 0.1;
	while (posy * (arr.rowmax + arr.colmax) + 200 < env->winy)
		posy += 0.1;
	posy -= 0.1;
	if (posy < posx)
		env->unit = posy;
	else
		env->unit = posx;
	env->origin_y = 1215 - env->unit * arr.rowmax;
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Enter name of one map file\n", 27);
		exit(0);
	}
}

void	set_env(t_env *env, char **argv)
{
	env->winx = 2560;
	env->winy = 1315;
	env->gsci = mlx_init();
	env->window = mlx_new_window(env->gsci, env->winx, env->winy, argv[1]);
}

void	set_pron(t_env *env, t_arr *arr)
{
	env->pron = 0;
	while ((abs(arr->max_z) * env->pron * env->unit / 100) < ((env->winy / 2) -
				100))
		env->pron++;
	env->pron--;
}

int		main(int argc, char **argv)
{
	t_arr	arr;
	int		**map;
	t_env	env;
	t_index	index;

	check_argc(argc);
	//while (1)
	//	ft_putstr("main 71\n");
	get_size_of_map(&arr, argv);
	//while (1)
	//	ft_putstr("main 74\n");
	set_env(&env, argv);
	//while (1)
	//	ft_putstr("main 77\n");
	index.i = 0;
	map = (int **)ft_memalloc(sizeof(int*) * arr.rowmax);
	map[0] = (int *)ft_memalloc(sizeof(int) * arr.rowmax * arr.colmax);
	while (index.i < arr.rowmax)
		map[index.i] = (*map + arr.colmax * index.i++);
	//while (1)
	//	ft_putstr("main 84\n");
	read_map(map, argv, &arr, &env);
	while (1)
		ft_putstr("main 87\n");
	set_unit_origin_y(arr, &env);
	while (1)
		ft_putstr("main 90\n");
	set_pron(&env, &arr);
	while (1)
		ft_putstr("main 93\n");
	print_map(&arr, map, &env);
	//return (0);
	while (1)
		ft_putstr("main 96\n");
	mlx_key_hook(env.window, key_event, 0);
	while (1)
		ft_putstr("main 99\n");
	mlx_loop(env.gsci);
}
