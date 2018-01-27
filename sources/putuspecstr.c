/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuspecstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:13:26 by gficara           #+#    #+#             */
/*   Updated: 2018/01/27 19:12:52 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uniwrite(int let, int len)
{
	if (len == 1)
		return (ft_putchar(let));
	else
	{
		if (len > 2)
			ft_putchar((len != 4) ? 224 | (15 & (let >> 12)) :
				240 | (7 & (let >> 18)));
		else
			ft_putchar(192 | (63 & (let >> 6)));
		if (len > 3)
			ft_putchar(128 | (63 & (let >> 12)));
		if (len > 2)
			ft_putchar(128 | (63 & (let >> 6)));
		if (len > 1)
			ft_putchar(128 | (63 & let));
	}
}

int		hashdown(t_flags flags, int c)
{
	if (c == 1)
		return (putspecint("", flags));
	return (putspecint("0", flags));
}

char	*mincor(char *tmp, t_flags flags)
{
	int		i;

	i = 0;
	while (tmp[i] && tmp[i] != '-')
		i++;
	if (flags.pre == 0)
	{
		tmp[i] = '0';
		tmp[0] = '-';
	}
	else
	{
		tmp[i] = '0';
		tmp = ft_sfstrjoin("-", tmp, 2);
	}
	return (tmp);
}
