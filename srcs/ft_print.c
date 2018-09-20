/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:03 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 20:16:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_win(t_info *info, int joueur)
{
	ft_putstr("\n Well ! Player ");
	if (joueur == 1)
	{
		ft_putstr(YELLOW);
		ft_putstr(info->j1);
		ft_putstr(END);
	}
	else if (joueur == 2)
	{
		ft_putstr(RED);
		ft_putstr(info->j2);
		ft_putstr(END);
	}
	ft_putendl(" win !");
}
