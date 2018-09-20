/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:19 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 11:58:06 by lguiller         ###   ########.fr       */
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
	ft_putstr("Pseudo player 1: ");
	get_next_line(0, &info->j1);
	ft_putstr("Pseudo player 2: ");
	get_next_line(0, &info->j2);
}

int			ft_puissance4(t_info *info, int first)
{
	t_coord	i;

	info->round = -1;
	i.x = first;
	creation(info->tab);
	print(info->tab);
	while (!check_map(info->tab))
	{
		if (++info->round > 6)
			if (parse_win(info))
				break ;
		i.y = 5;
		print_player_line(info, i.x);
		info->choix = check_col_num(info, &i);
		while (info->tab[i.y][ft_atoi(info->choix) - 1] != 0)
			info->choix = check_col_choice(info, &i);
		info->tab[i.y][ft_atoi(info->choix) - 1] = i.x;
		free(info->choix);
		print(info->tab);
		i.x = (i.x++ % 2 == 0) ? 1 : i.x;
	}
	return (ft_restart(info));
}

int			ft_draw(t_info info)
{
	t_mlx	ptr;

	(void)info;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WINX, WINY, "connect 4");
	ptr.game.img = mlx_xpm_file_to_image(ptr.mlx, BOARD, GAMEX, GAMEY);
	ptr.game.data = mlx_get_data_addr(ptr.game.img, &ptr.game.bpp, &ptr.game.sl,
			&ptr.game.endian);
	ptr.hud1.img = mlx_new_image(ptr.mlx, HUD1X, HUD1Y);
	ptr.hud1.data = mlx_get_data_addr(ptr.hud1.img, &ptr.hud1.bpp, &ptr.hud1.sl,
			&ptr.hud1.endian);
	ptr.hud2.img = mlx_new_image(ptr.mlx, HUD2X, HUD2Y);
	ptr.hud2.data = mlx_get_data_addr(ptr.hud2.img, &ptr.hud2.bpp, &ptr.hud2.sl,
			&ptr.hud2.endian);
	mlx_loop(ptr.mlx);
	return (0);
}

int			main(void)
{
	t_info	info;
	int		restart;
	int		first;

	first = 1;
	player_creation(&info);
	ft_draw(info);
	restart = ft_puissance4(&info, first);
	while (restart == 0)
	{
		first = (first == 1) ? 2 : 1;
		restart = ft_puissance4(&info, first);
	}
	ft_memdel((void **)&info.j1);
	ft_memdel((void **)&info.j2);
	return (0);
}
