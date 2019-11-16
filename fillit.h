/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnella <cnella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:42:17 by cnella            #+#    #+#             */
/*   Updated: 2019/02/26 16:47:28 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define ERR(x) if (x == 0) ft_putstr("error\n"); if (x == 0) exit(0);

int			validation(const int fd, char **arr, int i);
int			solver(char ****arr_figures);
char		****get_array(char ***arr_strings, char ****new_array);
int			get_mapsize(int size);
char		**map_generator(int mapsize);
void		clear_map(char ***map, int k);
void		ex_program(char ***map, char ****arr_figures);
void		ex_program2(char ***arr);
char		****get_array(char ***arr_strings, char ****new_array);
int			bt_func(char ****arr_figures, char ***map, int os[2], int k);

#endif
