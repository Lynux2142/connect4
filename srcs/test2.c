/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 10:57:15 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/10 11:27:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int		main(void)
{
	int		i;
	int		x;
	int		average;

	srand(time(NULL));
	x = 1;
	average = 0;
	while (x <= (6 * 7))
	{
		i = rand() % 7 + 1;
		average += i;
		printf("chiffre: %d  -  moyenne: %lf\n", i, (double)average / (double)x);
		++x;
	}
	return (0);
}
