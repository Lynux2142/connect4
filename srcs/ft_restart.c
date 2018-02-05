/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:41:57 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 14:45:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_restart(t_info *info)
{
	ft_putstr(" Rejouer (yes/no) ? ");
	get_next_line(0, &info->choix);
	if (ft_strcmp("yes", info->choix) == 0)
		return (0);
	return (1);
}
