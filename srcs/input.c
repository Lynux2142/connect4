/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:14:47 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 20:13:28 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_keyboard(int key, t_info *info)
{
	int	y;
	int	x;

	y = 5;
	if (key == KEY_1)
		x = 0;
	if (key == KEY_2)
		x = 1;
	if (key == KEY_3)
		x = 2;
	if (key == KEY_4)
		x = 3;
	if (key == KEY_5)
		x = 4;
	if (key == KEY_6)
		x = 5;
	if (key == KEY_7)
		x = 6;
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 ||
	key == KEY_5 || key == KEY_6 || key == KEY_7)
	{
		while (y >= 0 && info->tab[y][x] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[y][x] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			if (ft_parse_win(info))
				exit(0);
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 53)
		exit(0);
	return (1);
}
