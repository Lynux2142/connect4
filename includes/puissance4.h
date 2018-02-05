/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:36 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 14:45:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "libft.h"
# include <stdlib.h>

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
void			print_croix(void);
void			print_rond(void);
void			print_map(void);
void			print_top(void);

#endif
