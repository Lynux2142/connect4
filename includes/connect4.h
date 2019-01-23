/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:03:36 by lguiller          #+#    #+#             */
/*   Updated: 2019/01/23 15:21:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>

# define YELLOW		"\033[33m"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define END		"\033[0m"
# define WINX		1000
# define WINY		850
# define HUD1X		WINX / 2
# define HUD1Y		100
# define HUD2X		WINX / 2
# define HUD2Y		HUD1Y
# define GAMEX		WINX
# define GAMEY		WINY - HUD1Y
# define MENUX		400
# define MENUY		200
# define MENU_POSX	300
# define MENU_POSY	275

# ifdef __linux__
#  define KEY_1		49
#  define KEY_2		50
#  define KEY_3		51
#  define KEY_4		52
#  define KEY_5		53
#  define KEY_6		54
#  define KEY_7		55
#  define ESC		65307
# else
#  define KEY_1		18
#  define KEY_2		19
#  define KEY_3		20
#  define KEY_4		21
#  define KEY_5		23
#  define KEY_6		22
#  define KEY_7		26
#  define ESC		53
# endif

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
	t_img		menu;
}				t_mlx;

typedef struct	s_menu
{
	t_rect		back;
	t_rect		button1;
	t_rect		button2;
}				t_menu;

typedef struct	s_info
{
	t_menu		menu;
	char		*choix;
	int			tab[6][7];
	int			round;
	int			tour;
	int			active_menu;
	int			first;
}				t_info;

typedef struct	s_all
{
	t_info		info;
	t_mlx		ptr;
	t_circle	circle;
}				t_all;

void			print_win(t_info *info, int joueur);
int				ft_restart(t_info *info);
void			ft_circle(t_img *img, t_circle circle);
void			ft_round(t_img *img, t_circle circle);
void			ft_rect(t_img *img, t_rect rect);
void			ft_fill_pixel(t_img *img, int x, int y, int col);
int				ft_keyboard(int key, t_info *info);
int				ft_mouse(int x, int y, int button, t_info *info);
int				ft_refresh(t_all *all);
int				ft_parse_win(t_info *info);
void			ft_make_menu(t_mlx *ptr, t_info *info, t_img *menu);
void			ft_creation(int tab[6][7]);

#endif
