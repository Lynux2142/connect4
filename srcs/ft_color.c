/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:02:52 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 14:04:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_yellow(void)
{
	ft_putstr(YELLOW);
	ft_putchar('O');
	ft_putstr(END);
}

void	print_red(void)
{
	ft_putstr(RED);
	ft_putchar('O');
	ft_putstr(END);
}

void	print_map(void)
{
	ft_putstr(BLUE);
	ft_putchar('|');
	ft_putstr(END);
}

void	print_top(void)
{
	ft_putstr(BLUE);
	ft_putendl(" _ _ _ _ _ _ _");
	ft_putstr(END);
}
