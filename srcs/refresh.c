/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:34:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 14:54:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_refresh(t_all *all)
{
	int	x;
	int	y;

	all->circle.x = 140;
	all->circle.r = 40;
	y = -1;
	while (++y < 7)
	{
		x = -1;
		all->circle.y = 75;
		while (++x < 6)
		{
			all->circle.col = all->info.tab[y][x];
			ft_round(&all->ptr.game, all->circle);
			all->circle.y += (3 * all->circle.r);
		}
		all->circle.x += (3 * all->circle.r);
	}
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->ptr.game.img, 0, 0);
	return (1);
}
