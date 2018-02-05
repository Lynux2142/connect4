/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:02:36 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 15:11:41 by lguiller         ###   ########.fr       */
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
	ft_putendl("\n Egalite !");
	return (1);
}

char	*check_col_num(t_info *info, t_coord *i)
{
	char *choix;

	get_next_line(0, &choix);
	while (ft_atoi(choix) < 1 || ft_atoi(choix) > 7)
	{
		print(info->tab);
		ft_putstr("\nVeuillez entrer un chiffre entre 1 et 7");
		free(choix);
		print_player_line(info, i->x);
		get_next_line(0, &choix);
	}
	return (choix);
}

char	*check_col_choice(t_info *info, t_coord *i)
{
	if (--i->y < 0)
	{
		print(info->tab);
		ft_putstr("\nVeuillez choisir une autre colone");
		free(info->choix);
		print_player_line(info, i->x);
		info->choix = check_col_num(info, i);
		i->y = 5;
	}
	return (info->choix);
}
