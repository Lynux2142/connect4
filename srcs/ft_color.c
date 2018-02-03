/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:23:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/02 14:21:36 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_croix()
{
	ft_putstr("\033[33m");
	ft_putchar('x');
	ft_putstr("\033[0m");
}

void	print_rond()
{
	ft_putstr("\033[31m");
	ft_putchar('o');
	ft_putstr("\033[0m");
}

void	print_map()
{
	ft_putstr("\033[34m");
	ft_putchar('|');
	ft_putstr("\033[0m");
}

void	print_top()
{
	ft_putstr("\033[34m");
	ft_putendl(" _ _ _ _ _ _ _");
	ft_putstr("\033[0m");
}
