/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:15:39 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/24 14:30:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void		ft_rect(t_img *img, t_rect rect)
{
	int	x;
	int	y;

	y = -1;
	while (++y < rect.lenght)
	{
		x = -1;
		while (++x < rect.width)
			ft_fill_pixel(img, x + rect.x, y + rect.y, rect.col);
	}
}

void		ft_round(t_img *img, t_circle round)
{
	int	tmp;

	tmp = round.r;
	while (round.r >= 0)
	{
		ft_circle(img, round);
		--round.r;
	}
	round.r = tmp;
}

void		ft_circle(t_img *img, t_circle circle)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = circle.r;
	d = circle.r - 1;
	while (y >= x)
	{
		ft_fill_pixel(img, circle.x + x, circle.y + y, circle.col);
		ft_fill_pixel(img, circle.x + y, circle.y + x, circle.col);
		ft_fill_pixel(img, circle.x - x, circle.y + y, circle.col);
		ft_fill_pixel(img, circle.x - y, circle.y + x, circle.col);
		ft_fill_pixel(img, circle.x + x, circle.y - y, circle.col);
		ft_fill_pixel(img, circle.x + y, circle.y - x, circle.col);
		ft_fill_pixel(img, circle.x - x, circle.y - y, circle.col);
		ft_fill_pixel(img, circle.x - y, circle.y - x, circle.col);
		if (d >= 2 * x)
		{
			d = d - 2 * x - 1;
			++x;
		}
		else if (d < 2 * (circle.r - y))
		{
			d = d + 2 * y - 1;
			--y;
		}
		else
		{
			d = d + 2 * (y - x - 1);
			--y;
			++x;
		}
	}
}
