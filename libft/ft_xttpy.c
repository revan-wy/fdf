/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xttpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:41:57 by revan-wy          #+#    #+#             */
/*   Updated: 2018/05/31 10:41:45 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xttpy(int x, int y)
{
	int res;
	int ay;

	if (y == 0)
		return (1);
	ay = ft_absval(y);
	res = 1;
	while (ay-- > 0)
		res = res * x;
	return (res);
}
