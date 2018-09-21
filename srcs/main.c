/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:19 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/21 13:04:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int			ft_quit(void)
{
	exit(0);
}

void		ft_creation(int tab[6][7])
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

static void	ft_init_images(t_mlx *ptr)
{
	ptr->game.img = mlx_new_image(ptr->mlx, GAMEX, GAMEY);
	ptr->game.width = GAMEX;
	ptr->game.lenght = GAMEY;
	ptr->game.data = mlx_get_data_addr(ptr->game.img, &ptr->game.bpp,
			&ptr->game.sl, &ptr->game.endian);
	ptr->hud1.img = mlx_new_image(ptr->mlx, HUD1X, HUD1Y);
	ptr->hud1.width = HUD1X;
	ptr->hud1.lenght = HUD1Y;
	ptr->hud1.data = mlx_get_data_addr(ptr->hud1.img, &ptr->hud1.bpp,
			&ptr->hud1.sl, &ptr->hud1.endian);
	ptr->hud2.img = mlx_new_image(ptr->mlx, HUD2X, HUD2Y);
	ptr->hud2.width = HUD2X;
	ptr->hud2.lenght = HUD2Y;
	ptr->hud2.data = mlx_get_data_addr(ptr->hud2.img, &ptr->hud2.bpp,
			&ptr->hud2.sl, &ptr->hud2.endian);
	ptr->menu.img = mlx_new_image(ptr->mlx, MENUX, MENUY);
	ptr->menu.width = MENUX;
	ptr->menu.lenght = MENUY;
	ptr->menu.data = mlx_get_data_addr(ptr->menu.img, &ptr->menu.bpp,
			&ptr->menu.sl, &ptr->menu.endian);
}

int			main(void)
{
	t_all		all;
	t_rect		game;

	ft_creation(all.info.tab);
	player_creation(&all.info);
	all.ptr.mlx = mlx_init();
	all.ptr.win = mlx_new_window(all.ptr.mlx, WINX, WINY, "connect 4");
	ft_init_images(&all.ptr);
	all.info.tour = 1;
	game.x = 0;
	game.y = 0;
	game.width = GAMEX;
	game.lenght = GAMEY;
	game.col = 0xFF;
	ft_rect(&all.ptr.game, game);
	mlx_loop_hook(all.ptr.mlx, ft_refresh, &all);
	mlx_hook(all.ptr.win, 17, 0L, ft_quit, 0);
	mlx_hook(all.ptr.win, 2, (1L << 0), ft_keyboard, &all.info);
	mlx_hook(all.ptr.win, 4, (1L << 2), ft_mouse, &all.info);
	mlx_loop(all.ptr.mlx);
}
