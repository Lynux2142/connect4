/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:02:44 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 19:48:28 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	check_line(t_info *inf, t_coord i)
{
	if (i.x <= 3 && inf->tab[i.y][i.x] == inf->tab[i.y][i.x + 1]
			&& inf->tab[i.y][i.x + 1] == inf->tab[i.y][i.x + 2]
			&& inf->tab[i.y][i.x + 2] == inf->tab[i.y][i.x + 3])
	{
		print_win(inf, (inf->tab[i.y][i.x] == 0xFFFF00) ? 1 : 2);
		return (1);
	}
	return (0);
}

static int	check_column(t_info *inf, t_coord i)
{
	if (	i.y <= 2 && inf->tab[i.y][i.x] == inf->tab[i.y + 1][i.x]
			&& inf->tab[i.y + 1][i.x] == inf->tab[i.y + 2][i.x]
			&& inf->tab[i.y + 2][i.x] == inf->tab[i.y + 3][i.x])
	{
		print_win(inf, (inf->tab[i.y][i.x] == 0xFFFF00) ? 1 : 2);
		return (1);
	}
	return (0);
}

static int	check_diagonal_left(t_info *inf, t_coord i)
{
	if (i.x >= 3 && i.y <= 2 && inf->tab[i.y][i.x] == inf->tab[i.y + 1][i.x - 1]
			&& inf->tab[i.y + 1][i.x - 1] == inf->tab[i.y + 2][i.x - 2]
			&& inf->tab[i.y + 2][i.x - 2] == inf->tab[i.y + 3][i.x - 3])
	{
		print_win(inf, (inf->tab[i.y][i.x] == 0xFFFF00) ? 1 : 2);
		return (1);
	}
	return (0);
}

static int	check_diagonal_right(t_info *inf, t_coord i)
{
	if (i.x <= 3 && i.y <= 2 && inf->tab[i.y][i.x] == inf->tab[i.y + 1][i.x + 1]
			&& inf->tab[i.y + 1][i.x + 1] == inf->tab[i.y + 2][i.x + 2]
			&& inf->tab[i.y + 2][i.x + 2] == inf->tab[i.y + 3][i.x + 3])
	{
		print_win(inf, (inf->tab[i.y][i.x] == 0xFFFF00) ? 1 : 2);
		return (1);
	}
	return (0);
}

int			ft_parse_win(t_info *info)
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 7)
	{
		i.x = -1;
		while (++i.x < 6)
		{
			if (info->tab[i.y][i.x] != 0xFFFFFF)
			{
				if (check_line(info, i)
				|| check_column(info, i)
				|| check_diagonal_left(info, i)
				|| check_diagonal_right(info, i))
					return (1);
			}
		}
	}
	return (0);
}
