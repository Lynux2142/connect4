/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:03 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/06 14:49:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_win(t_info *info, int joueur)
{
	ft_putstr("\n Well ! Player ");
	if (joueur == 1)
	{
		ft_putstr(info->j1);
		ft_putstr(" (x)");
	}
	else if (joueur == 2)
	{
		ft_putstr(info->j2);
		ft_putstr(" (o)");
	}
	ft_putendl(" win !");
}

void	print(int tab[6][7])
{
	t_coord	i;

	ft_putchar('\n');
	print_top();
	i.y = -1;
	while (++i.y < 6)
	{
		print_map();
		i.x = -1;
		while (++i.x < 7)
		{
			if (tab[i.y][i.x] == 0)
				ft_putchar(' ');
			else if (tab[i.y][i.x] == 1)
				print_croix();
			else if (tab[i.y][i.x] == 2)
				print_rond();
			print_map();
		}
		ft_putchar('\n');
	}
	ft_putendl(" 1 2 3 4 5 6 7 ");
}

void	print_player_line(t_info *info, int i)
{
	ft_putstr("\n Player ");
	if (i == 1)
	{
		ft_putstr(info->j1);
		ft_putstr(" (x)");
	}
	else if (i == 2)
	{
		ft_putstr(info->j2);
		ft_putstr(" (o)");
	}
	ft_putstr(": ");
}
