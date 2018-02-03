/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:23:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/02 14:21:36 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

int		parse_win(int tab[6][7]);
void	check_line(int tab[6][7], t_coord i);
void	check_column(int tab[6][7], t_coord i);
void	check_diagonal_left(int tab[6][7], t_coord i);
void	check_diagonal_right(int tab[6][7], t_coord i);
void	print_win(char joueur);
void	print(int tab[6][7]);
void	print_player_line(int i);
int		check_map(int tab[6][7]);
char	*check_col_num(int tab[6][7], int i);
char	*check_col_choice(int tab[6][7], char *choix, t_coord *i);

#endif
