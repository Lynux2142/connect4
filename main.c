/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:23:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/02 14:03:37 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

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
	return (1);
}

//void	remplissage(int tab[6][7], int value)
//{}

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

void	check_line(int tab[6][7], t_coord i)
{
	if (tab[i.y][i.x] == tab[i.y][i.x + 1]
			&& tab[i.y][i.x + 1] == tab[i.y][i.x + 2]
			&& tab[i.y][i.x + 2] == tab[i.y][i.x + 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_column(int tab[6][7], t_coord i)
{
	if (tab[i.y][i.x] == tab[i.y + 1][i.x]
			&& tab[i.y + 1][i.x] == tab[i.y + 2][i.x]
			&& tab[i.y + 2][i.x] == tab[i.y + 3][i.x])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_diagonal_left(int tab[6][7], t_coord i)
{
	if (tab[i.y][i.x] == tab[i.y + 1][i.x - 1]
			&& tab[i.y + 1][i.x - 1] == tab[i.y + 2][i.x - 2]
			&& tab[i.y + 2][i.x - 2] == tab[i.y + 3][i.x - 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

void	check_diagonal_right(int tab[6][7], t_coord i)
{
	if (tab[i.y][i.x] == tab[i.y + 1][i.x + 1]
			&& tab[i.y + 1][i.x + 1] == tab[i.y + 2][i.x + 2]
			&& tab[i.y + 2][i.x + 2] == tab[i.y + 3][i.x + 3])
		print_win((tab[i.y][i.x] == 1) ? '1' : '2');
}

int		parse_win(int tab[6][7])
{
	t_coord	i;

	i.y = -1;
	while (++i.y < 6)
	{
		i.x = -1;
		while (++i.x < 7)
		{
			if (tab[i.y][i.x] != 0)
			{
				check_line(tab, i);
				check_column(tab, i);
				check_diagonal_left(tab, i);
				check_diagonal_right(tab, i);
			}
		}
	}
	return (0);
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
	ft_putchar('\n');
	return (choix);
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
			--i.y;
		tab[i.y][ft_atoi(choix) - 1] = i.x;
		free(choix);
		print(tab);
		i.x = (i.x % 2 == 0) ? 0 : i.x;
		++i.x;
	}
	return (0);
}
