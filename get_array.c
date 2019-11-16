/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:11:38 by cnella            #+#    #+#             */
/*   Updated: 2019/02/21 21:22:40 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	****get_array(char ***arr_strings, char ****new_array)
{
	char	*block;
	int		k;
	char	*tmp;
	int		i;

	k = 0;
	i = 0;
	block = (char *)malloc(sizeof(char) * 25);
	*new_array = (char ***)malloc(sizeof(char **) * 27);
	k = 0;
	while ((*arr_strings)[k])
	{
		ft_strncpy(block, (*arr_strings)[k], ft_strlen((*arr_strings)[k]) + 1);
		tmp = block;
		block = ft_strjoin(block, "\nXXXX");
		free(tmp);
		(*new_array)[k] = ft_strsplit(block, '\n');
		while ((*new_array)[k][i][0] != 'X')
			i++;
		ft_bzero((*new_array)[k][i], 4);
		k++;
	}
	(*new_array)[k++] = NULL;
	free(block);
	return (new_array);
}
