/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:32:13 by gficara           #+#    #+#             */
/*   Updated: 2018/01/27 19:38:02 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putuchar(int str)
{
	int		j;

	if (str < 4096)
		j = (str < 128) ? 1 : 2;
	else
		j = (str < 65536) ? 3 : 4;
	uniwrite(str, j);
}

static int	putnustr(int *str, int usage)
{
	int		i;
	int		j;

	if (usage == 1)
	{
		i = 0;
		while (str[i] != '\0')
			putuchar(str[i++]);
		return (0);
	}
	else
	{
		i = 0;
		j = 0;
		while (str[i] != '\0')
		{
			if (str[i] < 4096)
				j += (str[i] < 128) ? 1 : 2;
			else
				j += (str[i] < 65536) ? 3 : 4;
			i++;
		}
		return (j);
	}
}

static int	putuspecstr(int *tmp, t_flags flags)
{
	int		i;
	int		len;
	char	empty;

	i = 0;
	len = putnustr(tmp, 0);
	empty = (flags.zer == 1) ? '0' : ' ';
	if (flags.min != 0)
		putnustr(tmp, 1);
	if (flags.wid != 0 && flags.wid > len)
	{
		while (i++ < flags.wid - len)
			ft_putchar(empty);
		i--;
	}
	if (flags.min == 0)
		putnustr(tmp, 1);
	return (i + len);
}

int			pr_ustr(va_list ap, t_flags flags)
{
	int		*tmp;

	if (!(tmp = va_arg(ap, int *)))
			return (putspecstr("(null)", flags));
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
