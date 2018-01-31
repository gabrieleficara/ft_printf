/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:32:13 by gficara           #+#    #+#             */
/*   Updated: 2018/01/31 11:20:25 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putuchar(int str, int *i)
{
	int		j;

	if (str < 4096)
		j = (str < 128) ? 1 : 2;
	else
		j = (str < 65536) ? 3 : 4;
	if (j + i[1] <= i[2])
		uniwrite(str, j);
	return (j);
}

static int	putnustr(int *str, int usage, t_flags flags)
{
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	if (usage == 1)
	{
		i[2] = (flags.pre > 0) ? flags.pre : putnustr(str, 0, flags);
		while (str[i[0]] && i[1] < i[2])
			i[1] += putuchar(str[i[0]++], i);
		return (0);
	}
	while (str[i[0]])
	{
		if (str[i[0]] < 4096)
			i[2] = (str[i[0]++] < 128) ? 1 : 2;
		else
			i[2] = (str[i[0]++] < 65536) ? 3 : 4;
		if (flags.pre != 0 && i[1] + i[2] > flags.pre)
			return (i[1]);
		i[1] += i[2];
	}
	return (i[1]);
}

static int	putuspecstr(int *tmp, t_flags flags)
{
	int		i;
	int		len;
	char	empty;

	i = 0;
	len = putnustr(tmp, 0, flags);
	empty = (flags.zer == 1) ? '0' : ' ';
	if (flags.min != 0)
		putnustr(tmp, 1, flags);
	if (flags.wid != 0 && flags.wid > len)
	{
		while (i++ < flags.wid - len)
			ft_putchar(empty);
		i--;
	}
	if (flags.min == 0)
		putnustr(tmp, 1, flags);
	return (i + len);
}

int			pr_ustr(va_list ap, t_flags flags)
{
	int		*tmp;

	if (!(tmp = va_arg(ap, int *)))
		return (putspecstr("(null)", flags));
	if (flags.pre == 0 && flags.dot == 1)
		return (putspecstr("", flags));
	return (putuspecstr(tmp, flags));
}

int			pr_uchar(va_list ap, t_flags flags)
{
	int		tmp[2];
	int		i;

	tmp[0] = va_arg(ap, int);
	tmp[1] = '\0';
	if (!tmp[0])
	{
		i = 1;
		while (i++ < flags.wid)
			ft_putchar((flags.zer == 0) ? ' ' : '0');
		ft_putchar(0);
		return ((flags.wid == 0) ? 1 : flags.wid);
	}
	return (putuspecstr(tmp, flags));
}
