/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:29:12 by cnella            #+#    #+#             */
/*   Updated: 2019/02/26 17:17:09 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char			*is_sum_valid3(unsigned int s)
{
	if (s == 113 || s == 226 || s == 1808 || s == 3616 ||
		s == 28928 || s == 57856)
		return ("#...\n###.\n....\n....\0");
	if (s == 275 || s == 550 || s == 1100 || s == 4400 ||
		s == 8800 || s == 17600)
		return ("##..\n#...\n#...\n....\0");
	return (NULL);
}

static char			*is_sum_valid2(unsigned int s)
{
	if (s == 562 || s == 1124 || s == 2248 || s == 8992 ||
		s == 17984 || s == 35968)
		return (".#..\n##..\n.#..\n....\0");
	if (s == 305 || s == 610 || s == 1220 || s == 4880 ||
		s == 9760 || s == 19520)
		return ("#...\n##.\n#...\n....\0");
	if (s == 785 || s == 1570 || s == 3140 || s == 12560 ||
		s == 25120 || s == 50240)
		return ("#...\n#...\n##..\n....\0");
	if (s == 23 || s == 46 || s == 368 || s == 736 || s == 5888 || s == 11776)
		return ("###.\n#...\n....\n....\0");
	if (s == 547 || s == 1094 || s == 2188 || s == 8752 ||
		s == 17504 || s == 35008)
		return ("##..\n.#..\n.#..\n....\0");
	if (s == 116 || s == 232 || s == 1856 || s == 3712 ||
		s == 29696 || s == 59392)
		return ("..#.\n###.\n....\n....\0");
	if (s == 802 || s == 1604 || s == 3208 || s == 12832 ||
		s == 25664 || s == 51328)
		return (".#..\n.#..\n##..\n....\0");
	if (s == 71 || s == 142 || s == 1136 || s == 2272 || s == 18176 ||
		s == 36352)
		return ("###.\n..#.\n....\n....\0");
	return (is_sum_valid3(s));
}

static char			*is_sum_valid(unsigned int s)
{
	if (s == 51 || s == 102 || s == 204 || s == 816 || s == 1632 ||
		s == 3264 || s == 13056 || s == 26112 || s == 52224)
		return ("##..\n##..\n....\n....\0");
	if (s == 4369 || s == 8738 || s == 17476 || s == 34952)
		return ("#...\n#...\n#...\n#...\0");
	if (s == 15 || s == 240 || s == 3840 || s == 61440)
		return ("####\n....\n....\n....\0");
	if (s == 114 || s == 228 || s == 1824 || s == 3648 || s == 29184 ||
		s == 58368)
		return (".#..\n###.\n....\n....\0");
	if (s == 39 || s == 78 || s == 624 || s == 1248 || s == 9984 || s == 19968)
		return ("###.\n.#..\n....\n....\0");
	if (s == 99 || s == 198 || s == 1584 || s == 3168 || s == 25344 ||
		s == 50688)
		return ("##..\n.##.\n....\n....\0");
	if (s == 54 || s == 108 || s == 864 || s == 1728 || s == 13824 ||
		s == 27648)
		return (".##.\n##..\n....\n....\0");
	if (s == 306 || s == 612 || s == 1224 || s == 4896 || s == 9792 ||
		s == 19584)
		return (".#..\n##..\n#...\n....\0");
	if (s == 561 || s == 1122 || s == 2244 || s == 8976 || s == 17952 ||
		s == 35904)
		return ("#...\n##..\n.#..\n....\0");
	return (is_sum_valid2(s));
}

static int			figure_type(char line[4][5], char *arr[20])
{
	int				i;
	int				j;
	unsigned int	flag;
	unsigned int	sum;

	i = 0;
	flag = 1;
	sum = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (line[i][j++] == '#')
				sum += flag;
			flag *= 2;
		}
		i++;
	}
	if (!(*arr = is_sum_valid(sum)))
		return (0);
	return (1);
}

int					validation(const int fd, char *arr[20], int size)
{
	int		i;
	int		rfd;
	char	line[4][5];

	i = 0;
	while (i < 4)
	{
		rfd = read(fd, line[i++], 5);
		if (line[i - 1][4] != '\n')
			return (0);
		rfd = 0;
		while (rfd < 4)
		{
			if (line[i - 1][rfd] != '.' && line[i - 1][rfd] != '#')
				return (0);
			rfd++;
		}
	}
	ERR((rfd = figure_type(line, arr)));
	if (!(rfd = read(fd, &(line[0][0]), 1)) || line[0][0] == '\0')
		return (++size);
	else if (line[0][0] == '\n')
		return (validation(fd, ++arr, ++size));
	else
		return (0);
}
