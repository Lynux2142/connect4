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

int		check_map(int tab[6][7])
{
	t_coord i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
			if (tab[i.y][i.x] == 0)
				return (0);
	}
	ft_putendl("\nEgalite !");
	return (1);
}

char	*check_col_num(int tab[6][7], int i)
{
	char *choix;

	get_next_line(0, &choix);
	while (ft_atoi(choix) < 1 || ft_atoi(choix) > 7)
	{
		print(tab);
		ft_putstr("\nVeuillez entrer un chiffre entre 1 et 7");
		free(choix);
		print_player_line(i);
		get_next_line(0, &choix);
	}
	return (choix);
}

char	*check_col_choice(int tab[6][7], char *choix, t_coord *i)
{
	if (--i->y < 0)
	{
		print(tab);
		ft_putstr("\nVeuillez choisir une autre colone");
		free(choix);
		print_player_line(i->x);
		choix = check_col_num(tab, i->x);
		i->y = 5;
	}
	return (choix);
}
