/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:12:29 by gficara           #+#    #+#             */
/*   Updated: 2018/01/18 14:17:08 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	defflg(t_flags flags, char c)
{
	if (c == '-' && flags.min == 0)
		flags.min++;
	else if (c == '+' && flags.plu == 0)
		flags.plu++;
	else if (c == ' ' && flags.spa == 0)
		flags.spa++;
	else if (c == '0' && flags.zer == 0)
		flags.zer++;
	else if (c == '#' && flags.plu == 0)
		flags.has++;
	else if (c == 'h' && flags.plu < 2)
		flags.h++;
	else if (c == 'l' && flags.plu < 2)
		flags.l++;
	else if (c == 'z' && flags.plu == 0)
		flags.z++;
	else if (c == 'j' && flags.plu == 0)
		flags.j++;
	else if (c == '.' && flags.dot == 0)
		flags.dot++;
	return (flags);
}

static int		widpre(t_flags *flags, char *pnt)
{
	int		i;

	i = 0;
	if (flags->dot == 0)
		flags->wid = ft_atoi(pnt);
	else if (flags->dot == 1)
		flags->pre = ft_atoi(pnt);
	while (pnt[i] >= '0' && pnt[i] <= '9')
		i++;
	return (i);
}

int				findspec(char *pnt, va_list ap, t_flags flags, int *count)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (pnt[++i])
	{
		if (ft_strchr("hljz#0-+. ", pnt[i]))
			flags = defflg(flags, pnt[i]);
		if (ft_strchr("sSpdDioOuUxXcC", pnt[i]))
		{
			while (pnt[i] != (g_print[++j]).spec && j < 4)
				;
			if (pnt[i] == (g_print[j]).spec)
				*count = *count + (g_print[j]).fun(ap, flags);
			return (++i);
		}
		if (pnt[i] > '0' && pnt[i] <= '9')
			i += widpre(&flags, pnt + i) - 1;
	}
	return (0);
}

int				putspecstr(char *tmp, t_flags flags)
{
	int		i;
	int		len;
	char	empty;

	i = 0;
	len = ft_strlen(tmp);
	len = (flags.pre != 0 && flags.pre < len) ? flags.pre : len;
	empty = ((flags.zer == 1) ? '0' : ' ');
	if (flags.min != 0)
		ft_putnstr(tmp, len);
	if (flags.wid != 0 && flags.wid > len)
		while (i++ < flags.wid - len)
			ft_putchar(empty);
	if (flags.min == 0)
		ft_putnstr(tmp, len);
	return (i + len);
}

int				putspecint(char *tmp, t_flags flags)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(tmp);
	if (flags.min == 0)
		while (flags.wid - len > j++)
			ft_putchar(' ');
	i += j;
	ft_putstr(tmp);
	if (j == 0 && flags.min == 1)
	{
		while (flags.wid - len > j++)
			ft_putchar(' ');
		i += j;
	}
	i += len;
	return (i - 1);
}
