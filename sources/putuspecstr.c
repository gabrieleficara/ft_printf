/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuspecstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:13:26 by gficara           #+#    #+#             */
/*   Updated: 2018/01/31 15:12:33 by gficara          ###   ########.fr       */
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
	int		len;

	len = ft_strlen(tmp);
	i = 0;
	while (tmp[i] && tmp[i] != '-')
		i++;
	if (flags.pre == 0)
	{
		tmp[i] = '0';
		tmp[0] = '-';
	}
	else if (flags.pre >= len)
	{
		tmp[i] = '0';
		tmp = ft_sfstrjoin("-", tmp, 2);
	}
	return (tmp);
}

void	letfound(char *pnt, va_list ap, t_flags flags, int *count)
{
	int		j;

	j = -1;
	while (*pnt != (g_print[++j]).spec && j < 15)
		;
	if (*pnt == (g_print[j]).spec)
		*count = *count + (g_print[j]).fun(ap, flags);
}

int		nfound(char *pnt, int i, int *count, t_flags flags)
{
	char	tmp[2];

	tmp[0] = pnt[i];
	tmp[1] = '\0';
	*count += putspecstr(tmp, flags);
	return (++i);
}
