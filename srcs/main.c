/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:19 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 20:12:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	creation(int tab[6][7])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 6)
	{
		x = -1;
		while (++x < 7)
			tab[y][x] = 0xFFFFFF;
	}
}

static void	player_creation(t_info *info)
{
	ft_putstr("Pseudo player 1: ");
	get_next_line(0, &info->j1);
	ft_putstr("Pseudo player 2: ");
	get_next_line(0, &info->j2);
}

int			main(void)
{
	t_all		all;
	t_mlx		ptr;
	t_rect		rect;

	creation(all.info.tab);
	player_creation(&all.info);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WINX, WINY, "connect 4");
	ptr.game.img = mlx_new_image(ptr.mlx, GAMEX, GAMEY);
	ptr.game.width = GAMEX;
	ptr.game.lenght = GAMEY;
	ptr.game.data = mlx_get_data_addr(ptr.game.img, &ptr.game.bpp, &ptr.game.sl,
			&ptr.game.endian);
	ptr.hud1.img = mlx_new_image(ptr.mlx, HUD1X, HUD1Y);
	ptr.hud1.width = HUD1X;
	ptr.hud1.lenght = HUD1Y;
	ptr.hud1.data = mlx_get_data_addr(ptr.hud1.img, &ptr.hud1.bpp, &ptr.hud1.sl,
			&ptr.hud1.endian);
	ptr.hud2.img = mlx_new_image(ptr.mlx, HUD2X, HUD2Y);
	ptr.hud2.width = HUD2X;
	ptr.hud2.lenght = HUD2Y;
	ptr.hud2.data = mlx_get_data_addr(ptr.hud2.img, &ptr.hud2.bpp, &ptr.hud2.sl,
			&ptr.hud2.endian);
	all.info.tour = 1;
	rect.x = 0;
	rect.y = 0;
	rect.width = GAMEX;
	rect.lenght = GAMEY;
	rect.col = 0xFF;
	ft_rect(&ptr.game, rect);
	all.ptr = ptr;
	mlx_loop_hook(ptr.mlx, ft_refresh, &all);
	mlx_hook(ptr.win, 2, (1L << 0), ft_keyboard, &all.info);
	mlx_loop(ptr.mlx);
}
