/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:04:12 by lguiller          #+#    #+#             */
/*   Updated: 2018/06/20 11:56:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc(void *str, size_t size)
{
	void	*tmp;

	if (size == 0 && str)
	{
		ft_memdel(&str);
		if (!(str = ft_memalloc(1)))
			return (NULL);
	}
	else if (size > 0)
	{
		tmp = str;
		if (!(str = ft_memalloc(size)))
			return (NULL);
		if (tmp)
		{
			ft_strncpy(str, tmp, size);
			ft_memdel((void **)&tmp);
		}
	}
	return (str);
}
