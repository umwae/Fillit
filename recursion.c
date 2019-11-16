/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:29:12 by cnella            #+#    #+#             */
/*   Updated: 2019/02/22 17:29:39 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	checker(char ****arr_figures, char ***map, int tmp[2], int k)
{
	int		x;
	int		y;
	int		o[2];

	y = 0;
	o[1] = tmp[1];
	o[0] = tmp[0];
	if (!(*arr_figures)[k])
		ex_program(map, arr_figures);
	while ((*arr_figures)[k][y][0] != '\0')
	{
		x = 0;
		o[0] = tmp[0];
		while ((*arr_figures)[k][y][x] != '\0')
		{
			if ((*arr_figures)[k][y][x] == '#' &&
				(ft_isalpha((*map)[o[1]][o[0]]) || (*map)[o[1]][o[0]] == '\0'))
				return (1);
			x++;
			(o[0])++;
		}
		y++;
		(o[1])++;
	}
	return (0);
}

static int	printer(char ****arr_figures, char ***map, int tmp[2], int k)
{
	int		x;
	int		y;
	int		yos;
	int		xos;

	y = 0;
	yos = tmp[1];
	xos = tmp[0];
	while ((*arr_figures)[k][y][0] != '\0' && (*map)[yos][0] != '\0')
	{
		x = 0;
		xos = tmp[0];
		while ((*arr_figures)[k][y][x] != '\0' && (*map)[yos][xos] != '\0')
		{
			if ((*arr_figures)[k][y][x] == '#')
			{
				(*map)[yos][xos] = 'A' + k;
			}
			x++;
			xos++;
		}
		y++;
		yos++;
	}
	return (0);
}

int			bt_func2(char ****arr_figures, char ***map, int os[2], int k)
{
	int		tmp[2];

	tmp[0] = os[0];
	tmp[1] = os[1];
	if (checker(arr_figures, map, tmp, k) == 0)
	{
		printer(arr_figures, map, tmp, k);
		tmp[0] = 0;
		tmp[1] = 0;
		if (!(bt_func(arr_figures, map, tmp, k + 1)))
		{
			tmp[0] = os[0] + 1;
			tmp[1] = os[1];
			return (bt_func(arr_figures, map, tmp, k - 2));
		}
	}
	tmp[0] = os[0] + 1;
	tmp[1] = os[1];
	return (bt_func(arr_figures, map, tmp, k));
}

int			bt_func(char ****arr_figures, char ***map, int os[2], int k)
{
	int		tmp[2];

	tmp[0] = os[0];
	tmp[1] = os[1];
	if ((*map)[os[1]][0] != '\0')
	{
		if ((*map)[os[1]][os[0]] != '\0')
		{
			return (bt_func2(arr_figures, map, tmp, k));
		}
		tmp[0] = 0;
		tmp[1] = os[1] + 1;
		return (bt_func(arr_figures, map, tmp, k));
	}
	if (!(*arr_figures)[k])
		return (2);
	clear_map(map, k - 1);
	return (1);
}

int			solver(char ****arr_figures)
{
	int		k;
	int		mapsize;
	char	**map;
	int		os[2];

	k = 0;
	os[0] = 0;
	os[1] = 0;
	while ((*arr_figures)[k])
		k++;
	mapsize = get_mapsize(k);
	if (k == 1)
		mapsize = 2;
	map = map_generator(mapsize);
	while (bt_func(arr_figures, &map, os, 0) == 1)
		map = map_generator(++mapsize);
	return (0);
}
