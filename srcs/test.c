/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:46:01 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/05 18:35:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_rand(int a)
{
	int			reslut;
	static int	i;
	int			tab[7] = {1, 2, 3, 4, 5, 6, 7};

	if (i == 1)
		reslut = tab[7 - a];
	else if (i == 0)
	{
		if ((reslut = a + 3) > 7)
			reslut -= 7;
	}
	else
		reslut = a;
	if (++i == 3)
		i = 0;
	return (reslut);
}

int		main(void)
{
	char	*a;
	int		i;

	while (get_next_line(0, &a))
	{
		i = ft_atoi(a);
		ft_putnbr(ft_rand(i));
		ft_putchar('\n');
	}
	return (0);
}
