/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:01:15 by cnella            #+#    #+#             */
/*   Updated: 2019/02/22 16:46:45 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**map_generator(int mapsize)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (mapsize + 1));
	i = mapsize + 1;
	while (i--)
	{
		map[i] = ft_strnew(mapsize);
		ft_memset(map[i], '.', mapsize);
	}
	ft_bzero(map[mapsize], mapsize);
	return (map);
}
