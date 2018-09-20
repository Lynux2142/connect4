/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:14:47 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 14:53:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_keyboard(int key, t_info *info)
{
	int	y;

	y = 5;
	if (key == 18)
	{
		while (y >= 0 && info->tab[0][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[0][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 19)
	{
		while (y >= 0 && info->tab[1][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[1][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 20)
	{
		while (y >= 0 && info->tab[2][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[2][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 21)
	{
		while (y >= 0 && info->tab[3][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[3][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 23)
	{
		while (y >= 0 && info->tab[4][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[4][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 22)
	{
		while (y >= 0 && info->tab[5][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[5][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 26)
	{
		while (y >= 0 && info->tab[6][y] != 0xFFFFFF)
			--y;
		if (y != -1)
		{
			info->tab[6][y] = (info->tour == 1) ? 0xFFFF00 : 0xFF0000;
			info->tour = (info->tour == 1) ? 2 : 1;
		}
	}
	if (key == 53)
		exit(0);
	return (1);
}
