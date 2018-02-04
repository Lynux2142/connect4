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

int		parse_win(t_info *info)
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
		{
			if (info->tab[i.y][i.x] != 0)
			{
				check_line(info, i);
				check_column(info, i);
				check_diagonal_left(info, i);
				check_diagonal_right(info, i);
			}
		}
	}
	return (0);
}

void	check_line(t_info *info, t_coord i)
{
	if (i.x <= 3 && info->tab[i.y][i.x] == info->tab[i.y][i.x + 1]
			&& info->tab[i.y][i.x + 1] == info->tab[i.y][i.x + 2]
			&& info->tab[i.y][i.x + 2] == info->tab[i.y][i.x + 3])
		print_win(info, (info->tab[i.y][i.x] == 1) ? 1 : 2);
}

void	check_column(t_info *info, t_coord i)
{
	if (i.y <= 2 && info->tab[i.y][i.x] == info->tab[i.y + 1][i.x]
			&& info->tab[i.y + 1][i.x] == info->tab[i.y + 2][i.x]
			&& info->tab[i.y + 2][i.x] == info->tab[i.y + 3][i.x])
		print_win(info, (info->tab[i.y][i.x] == 1) ? 1 : 2);
}

void	check_diagonal_left(t_info *info, t_coord i)
{
	if (i.x >= 3 && i.y <= 2 && info->tab[i.y][i.x] == info->tab[i.y + 1][i.x - 1]
			&& info->tab[i.y + 1][i.x - 1] == info->tab[i.y + 2][i.x - 2]
			&& info->tab[i.y + 2][i.x - 2] == info->tab[i.y + 3][i.x - 3])
		print_win(info, (info->tab[i.y][i.x] == 1) ? 1 : 2);
}

void	check_diagonal_right(t_info *info, t_coord i)
{
	if (i.x <= 3 && i.y <= 2 && info->tab[i.y][i.x] == info->tab[i.y + 1][i.x + 1]
			&& info->tab[i.y + 1][i.x + 1] == info->tab[i.y + 2][i.x + 2]
			&& info->tab[i.y + 2][i.x + 2] == info->tab[i.y + 3][i.x + 3])
		print_win(info, (info->tab[i.y][i.x] == 1) ? 1 : 2);
}
