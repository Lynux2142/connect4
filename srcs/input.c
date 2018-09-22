/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:14:47 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/22 10:24:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int		ft_keyboard(int key, t_info *info)
{
	int	y;
	int	x;

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
	y = 5;
	if ((key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 ||
	key == KEY_5 || key == KEY_6 || key == KEY_7) && !info->active_menu && !ft_parse_win(info))
	{
		while (y >= 0 && info->tab[y][x] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[y][x] = (info->tour % 2 == 0) ? 0xFF0000 : 0xFFFF00;
			if (ft_parse_win(info))
			{
				info->active_menu = 1;
				info->first = (info->first == 1) ? 2 : 1;
			}
			++info->tour;
		}
	}
	if (key == 53)
		info->active_menu = (info->active_menu == 1) ? 0 : 1;
	return (1);
}

int		ft_mouse(int button, int x, int y, t_info *info)
{
	if (info->active_menu && button == 1)
	{
		if (x >= MENU_POSX + info->menu.button1.x &&
		x <= MENU_POSX + info->menu.button1.x + info->menu.button1.width &&
		y >= MENU_POSY + info->menu.button1.y &&
		y <= MENU_POSY + info->menu.button1.y + info->menu.button1.lenght)
			exit(1);
		if (x >= MENU_POSX + info->menu.button2.x &&
		x <= MENU_POSX + info->menu.button2.x + info->menu.button2.width &&
		y >= MENU_POSY + info->menu.button2.y &&
		y <= MENU_POSY + info->menu.button2.y + info->menu.button2.lenght)
		{
			ft_creation(info->tab);
			info->active_menu = 0;
		}
	}
	return (1);
}
