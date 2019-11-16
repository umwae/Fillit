/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:08:03 by cnella            #+#    #+#             */
/*   Updated: 2019/02/26 17:30:12 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ex_program2(char ***arr)
{
	static char		***ptr;

	if (!arr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	ptr = arr;
}

void		ex_program(char ***map, char ****arr_figures)
{
	int				i;

	i = 0;
	while ((*map)[i][0])
	{
		ft_putstr((*map)[i++]);
		ft_putchar('\n');
	}
	ft_arrfree(map, i + 1);
	i = 0;
	while ((*arr_figures)[i])
		ft_arrfree(&((*arr_figures)[i++]), 5);
	free(*arr_figures);
	ex_program2(NULL);
	exit(0);
}
