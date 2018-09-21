/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:07:43 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/21 17:50:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void		ft_make_menu(t_mlx *ptr, t_info *info, t_img *menu)
{
	t_rect	back;
	t_rect	button1;
	t_rect	button2;
	int		player;

	back.x = 0;
	back.y = 0;
	back.width = MENUX;
	back.lenght = MENUY;
	back.col = 0;
	ft_rect(menu, back);
	button1.width = 150;
	button1.lenght = 50;
	button1.x = 30;
	button1.y = MENUY - button1.lenght - 30;
	button1.col = 0xFFFFFF;
	ft_rect(menu, button1);
	button2.width = 150;
	button2.lenght = 50;
	button2.x = MENUX - button2.width - 30;
	button2.y = MENUY - button2.lenght - 30;
	button2.col = 0xFFFFFF;
	ft_rect(menu, button2);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->menu.img, 300, 275);
	mlx_string_put(ptr->mlx, ptr->win, 385, 410, 0, "QUIT");
	mlx_string_put(ptr->mlx, ptr->win, 560, 410, 0, "RESTART");
	if ((player = ft_parse_win(info)))
	{
		if (player == 0xFFFF00)
			mlx_string_put(ptr->mlx, ptr->win, 385, 325, 0xFFFFFF, "WELL ! YELLOW WIN !");
		else
			mlx_string_put(ptr->mlx, ptr->win, 385, 325, 0xFFFFFF, "WELL ! RED WIN !");
	}
	info->tour = info->first;
}
