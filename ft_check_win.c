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

#include "puissance4.h"

int		parse_win(int tab[6][7])
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
		{
			if (tab[i.y][i.x] != 0)
			{
				check_line(tab, i);
				check_column(tab, i);
				check_diagonal_left(tab, i);
				check_diagonal_right(tab, i);
			}
		}
	}
	return (0);
}

void	check_line(int tab[6][7], t_coord i)
{
	if (i.x <= 3 && tab[i.y][i.x] == tab[i.y][i.x + 1]
			&& tab[i.y][i.x + 1] == tab[i.y][i.x + 2]
			&& tab[i.y][i.x + 2] == tab[i.y][i.x + 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_column(int tab[6][7], t_coord i)
{
	if (i.y <= 2 && tab[i.y][i.x] == tab[i.y + 1][i.x]
			&& tab[i.y + 1][i.x] == tab[i.y + 2][i.x]
			&& tab[i.y + 2][i.x] == tab[i.y + 3][i.x])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_diagonal_left(int tab[6][7], t_coord i)
{
	if (i.x >= 3 && i.y <= 2 && tab[i.y][i.x] == tab[i.y + 1][i.x - 1]
			&& tab[i.y + 1][i.x - 1] == tab[i.y + 2][i.x - 2]
			&& tab[i.y + 2][i.x - 2] == tab[i.y + 3][i.x - 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_diagonal_right(int tab[6][7], t_coord i)
{
	if (i.x <= 3 && i.y <= 2 && tab[i.y][i.x] == tab[i.y + 1][i.x + 1]
			&& tab[i.y + 1][i.x + 1] == tab[i.y + 2][i.x + 2]
			&& tab[i.y + 2][i.x + 2] == tab[i.y + 3][i.x + 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}
