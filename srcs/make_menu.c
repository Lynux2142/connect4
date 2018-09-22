/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:07:43 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/22 10:16:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void		ft_make_menu(t_mlx *ptr, t_info *info, t_img *menu)
{
	int		player;

	info->menu.back.x = 0;
	info->menu.back.y = 0;
	info->menu.back.width = MENUX;
	info->menu.back.lenght = MENUY;
	info->menu.back.col = 0;
	ft_rect(menu, info->menu.back);
	info->menu.button1.width = 150;
	info->menu.button1.lenght = 50;
	info->menu.button1.x = 30;
	info->menu.button1.y = MENUY - info->menu.button1.lenght - 30;
	info->menu.button1.col = 0xFFFFFF;
	ft_rect(menu, info->menu.button1);
	info->menu.button2.width = 150;
	info->menu.button2.lenght = 50;
	info->menu.button2.x = MENUX - info->menu.button2.width - 30;
	info->menu.button2.y = MENUY - info->menu.button2.lenght - 30;
	info->menu.button2.col = 0xFFFFFF;
	ft_rect(menu, info->menu.button2);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->menu.img,
		MENU_POSX, MENU_POSY);
	mlx_string_put(ptr->mlx, ptr->win, MENU_POSX + info->menu.button1.x + 55,
		MENU_POSY + info->menu.button1.y + 15, 0, "QUIT");
	mlx_string_put(ptr->mlx, ptr->win, MENU_POSX + info->menu.button2.x + 40,
		MENU_POSY + info->menu.button2.y + 15, 0, "RESTART");
	if ((player = ft_parse_win(info)))
	{
		if (player == 0xFFFF00)
			mlx_string_put(ptr->mlx, ptr->win, MENU_POSX + 110, MENU_POSY + 50,
				0xFFFFFF, "WELL ! YELLOW WIN !");
		else
			mlx_string_put(ptr->mlx, ptr->win, MENU_POSX + 125, MENU_POSY + 50,
				0xFFFFFF, "WELL ! RED WIN !");
	}
	else
		mlx_string_put(ptr->mlx, ptr->win, MENU_POSX + 175, MENU_POSY + 50,
			0xFFFFFF, "PAUSE");
	info->tour = info->first;
}
