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

void	creation(int tab[6][7])
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
			tab[i.y][i.x] = 0;
	}
}

int		main(void)
{
	char	*choix;
	int		tab[6][7];
	t_coord	i;
	int		round;

	round = -1;
	i.x = 1;
	creation(tab);
	print(tab);
	while (!check_map(tab))
	{
		if (++round > 6)
			parse_win(tab);
		i.y = 5;
		print_player_line(i.x);
		choix = check_col_num(tab, i.x);
		while (tab[i.y][ft_atoi(choix) - 1] != 0)
				choix = check_col_choice(tab, choix, &i);
		tab[i.y][ft_atoi(choix) - 1] = i.x;
		free(choix);
		print(tab);
		i.x = (i.x++ % 2 == 0) ? 1 : i.x;
	}
	return (0);
}
