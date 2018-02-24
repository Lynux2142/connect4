/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:36 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/14 17:56:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "libft.h"
# include <stdlib.h>

# define YELLOW "\033[33m"
# define RED "\033[31m"
# define BLUE "\033[34m"
# define END "\033[0m"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_info
{
	char		*choix;
	int			tab[6][7];
	int			round;
	char		*j1;
	char		*j2;
}				t_info;

int				parse_win(t_info *info);
void			print_win(t_info *info, int joueur);
void			print(int tab[6][7]);
void			print_player_line(t_info *info, int i);
int				check_map(int tab[6][7]);
char			*check_col_num(t_info *info, t_coord *i);
char			*check_col_choice(t_info *info, t_coord *i);
int				ft_restart(t_info *info);
void			print_yellow(void);
void			print_red(void);
void			print_map(void);
void			print_top(void);

#endif
