/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 08:21:57 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 13:19:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void		ft_fill_pixel(t_img *img, int x, int y, int col)
{
	if ((y >= 0 && y < img->lenght) && (x >= 0 && x < img->width))
		if (img->endian == 0 && img->bpp == 32)
		{
			((char *)(img->data))[((x * 4) + (y * img->sl))] =
				(char)col;
			((char *)(img->data))[((x * 4) + (y * img->sl)) + 1] =
				(char)(col >> 8);
			((char *)(img->data))[((x * 4) + (y * img->sl)) + 2] =
				(char)(col >> 16);
			((char *)(img->data))[((x * 4) + (y * img->sl)) + 3] =
				(char)(col >> 24);
		}
}
