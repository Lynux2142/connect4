/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:34:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/24 19:17:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int		ft_refresh(t_all *all)
{
	int	x;
	int	y;

	all->circle.y = 75;
	all->circle.r = 40;
	y = -1;
	while (++y < 6)
	{
		x = -1;
		all->circle.x = 140;
		while (++x < 7)
		{
			all->circle.col = all->info.tab[y][x];
			ft_round(&all->ptr.game, all->circle);
			all->circle.x += (3 * all->circle.r);
		}
		all->circle.y += (3 * all->circle.r);
	}
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->ptr.game.img, 0, 0);
	mlx_string_put(all->ptr.mlx, all->ptr.win, 135, 725, 0xFFFFFF, "1");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 255, 725, 0xFFFFFF, "2");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 375, 725, 0xFFFFFF, "3");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 495, 725, 0xFFFFFF, "4");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 615, 725, 0xFFFFFF, "5");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 735, 725, 0xFFFFFF, "6");
	mlx_string_put(all->ptr.mlx, all->ptr.win, 855, 725, 0xFFFFFF, "7");
	if (all->info.active_menu == 1)
		ft_make_menu(&all->ptr, &all->info, &all->ptr.menu);
	return (1);
}
