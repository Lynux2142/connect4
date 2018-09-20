/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:36 by lguiller          #+#    #+#             */
/*   Updated: 2018/09/20 18:38:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "libft.h"
#include "mlx.h"
# include <stdlib.h>

# define YELLOW		"\033[33m"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define END		"\033[0m"
# define WINX		1000
# define WINY		850
# define GAMEX		WINX
# define HUD1X		WINX / 2
# define HUD1Y		100
# define GAMEY		WINY - HUD1Y
# define HUD2X		WINX / 2
# define HUD2Y		HUD1Y
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_4		21
# define KEY_5		23
# define KEY_6		22
# define KEY_7		26

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			lenght;
	int			col;
}				t_rect;

typedef struct	s_circle
{
	int			x;
	int			y;
	int			r;
	int			col;
}				t_circle;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			width;
	int			lenght;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		game;
	t_img		hud1;
	t_img		hud2;
}				t_mlx;

typedef struct	s_info
{
	char		*choix;
	int			tab[6][7];
	int			round;
	char		*j1;
	char		*j2;
	int			tour;
}				t_info;

typedef struct	s_all
{
	t_info		info;
	t_mlx		ptr;
	t_circle	circle;
}				t_all;

void			print_win(t_info *info, int joueur);
void			print(int tab[6][7]);
void			print_player_line(t_info *info, int i);
int				ft_restart(t_info *info);
void			print_yellow(void);
void			print_red(void);
void			print_map(void);
void			print_top(void);
void			ft_circle(t_img *img, t_circle circle);
void			ft_round(t_img *img, t_circle circle);
void			ft_rect(t_img *img, t_rect rect);
void			ft_fill_pixel(t_img *img, int x, int y, int col);
int				ft_keyboard(int key, t_info *info);
int				ft_refresh(t_all *all);
int				ft_parse_win(t_info *info);

#endif
