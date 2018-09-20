/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:34:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 20:06:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

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
	return (1);
}
