/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:41:57 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 16:07:47 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_restart(t_info *info)
{
	int	value;

	ft_putstr(" Rejouer (yes/no) ? ");
	get_next_line(0, &info->choix);
	value = (ft_strcmp("yes", info->choix) == 0) ? 0 : 1;
	ft_memdel((void **)&info->choix);
	return (value);
}
