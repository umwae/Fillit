/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:36:11 by cnella            #+#    #+#             */
/*   Updated: 2019/02/26 16:46:36 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**arr;
	char	***new_array;

	fd = 0;
	i = 0;
	arr = (char **)malloc(sizeof(char *) * 27);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit your_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ERR(fd);
	i = validation(fd, arr, i);
	arr[i] = NULL;
	if (i > 26)
		i = 0;
	close(fd);
	ERR(i);
	ex_program2(&arr);
	get_array(&arr, &new_array);
	return (solver(&new_array));
}
