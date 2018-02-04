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

static void	creation(int tab[6][7])
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
			tab[i.y][i.x] = 0;
	}
}

static void	player_creation(t_info *info)
{
	ft_putstr("pseudo joueur 1: ");
	get_next_line(0, &info->j1);
	ft_putstr("pseudo joueur 2: ");
	get_next_line(0, &info->j2);
}

int			main(void)
{
	t_info	info;
	t_coord	i;

	info.round = -1;
	i.x = 1;
	player_creation(&info);
	creation(info.tab);
	print(info.tab);
	while (!check_map(info.tab))
	{
		if (++info.round > 6)
			parse_win(&info);
		i.y = 5;
		print_player_line(&info, i.x);
		info.choix = check_col_num(&info, &i);
		while (info.tab[i.y][ft_atoi(info.choix) - 1] != 0)
				info.choix = check_col_choice(&info, &i);
		info.tab[i.y][ft_atoi(info.choix) - 1] = i.x;
		free(info.choix);
		print(info.tab);
		i.x = (i.x++ % 2 == 0) ? 1 : i.x;
	}
	return (0);
}
