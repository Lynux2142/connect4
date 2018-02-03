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

void	print_win(char joueur)
{
	ft_putstr("\n Bravo ! le joueur ");
	ft_putchar(joueur);
	ft_putendl(" gagne !");
	exit(0);
}

void	print(int tab[6][7])
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		ft_putchar('|');
		i.x = -1;
		while (++i.x < 7)
		{
			if (tab[i.y][i.x] == 0)
				ft_putchar(' ');
			else if (tab[i.y][i.x] == 1)
				ft_putchar('x');
			else if (tab[i.y][i.x] == 2)
				ft_putchar('o');
			ft_putchar('|');
		}
		ft_putchar('\n');
	}
	ft_putendl(" 1 2 3 4 5 6 7 ");
}

void	print_player_line(int i)
{
	ft_putstr("\njoueur ");
	ft_putnbr(i);
	ft_putchar(' ');
	if (i == 1)
		ft_putstr("(x)");
	else if (i == 2)
		ft_putstr("(o)");
	ft_putstr(": ");
}
