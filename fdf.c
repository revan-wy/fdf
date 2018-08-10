/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 08:05:45 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/10 17:17:26 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_unit_origin_y(t_arr arr, t_env *env)
{
	float posx;
	float posy;

	posx = 0;
	posy = 0;
	while (posx * (arr.rowmax + arr.colmax) / tan(30 * 0.0174533) + 400 <
			env->winx)
		posx += 0.1;
	posx -= 0.1;
	while (posy * (arr.rowmax + arr.colmax) + 400 < env->winy)
		posy += 0.1;
	posy -= 0.1;
	if (posy < posx)
		env->unit = posy;
	else
		env->unit = posx;
	env->origin_y = env->winy / 2 - env->unit * (arr.rowmax - arr.colmax) / 2;
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
	while ((env->origin_y + (arr->max_z * env->pron * (env->unit / 100))) <
			(env->winy - 100) && (env->origin_y + (arr->max_z * env->pron *
			(env->unit / 100))) > 400)
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
	get_size_of_map(&arr, argv);
	set_env(&env, argv);
	index.i = 0;
	map = (int **)ft_memalloc(sizeof(int*) * arr.rowmax);
	map[0] = (int *)ft_memalloc(sizeof(int) * arr.rowmax * arr.colmax);
	while (index.i < arr.rowmax)
		map[index.i] = (*map + arr.colmax * index.i++);
	read_map(map, argv, &arr, &env);
	set_unit_origin_y(arr, &env);
	set_pron(&env, &arr);
	print_map(&arr, map, &env);
	mlx_key_hook(env.window, key_event, 0);
	mlx_loop(env.gsci);
}
