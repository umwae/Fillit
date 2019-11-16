/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:05:48 by cnella            #+#    #+#             */
/*   Updated: 2019/02/21 20:27:51 by cnella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	clear_map(char ***map, int k)
{
	char	*ptr;
	int		yos2;

	yos2 = 0;
	while ((*map)[yos2][0] != '\0')
	{
		ptr = (*map)[yos2];
		while (*ptr != '\0')
		{
			if (*ptr == 'A' + k)
				*ptr = '.';
			ptr++;
		}
		yos2++;
	}
}
