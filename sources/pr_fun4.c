/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:32:13 by gficara           #+#    #+#             */
/*   Updated: 2018/01/23 15:07:50 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putuchar(unsigned int str)
{
	int		j;

	if (str < 4096)
		j = (str < 128) ? 1 : 2;
	else
		j = (str < 65536) ? 3 : 4;
	uniwrite(str, j);
}

static int	putnustr(unsigned int *str, int unsigned len, int usage)
{
	int		i;
	int		j;

	if (usage == 1)
	{
		i = 0;
		while(str[i] < len)
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
		return (i);
	}
}

static int	putuspecstr(unsigned int *tmp, t_flags flags)
{
	int		i;
	int		len;
	char	empty;

	i = 0;
	len = putnustr(tmp, 0, 0);
	empty = (flags.zer == 1) ? '0' : ' ';
	if (flags.min != 0)
		putnustr(tmp, len, 1);
	if (flags.wid != 0 && flags.wid > len)
	{
		while (i++ < flags.wid - len)
			ft_putchar(empty);
		i--;
	}
	if (flags.min == 0)
		putnustr(tmp, len, 1);
	return (i + len);
}

int		pr_ustr(va_list ap, t_flags flags)
{
	unsigned int		*tmp;

	tmp = va_arg(ap, unsigned int *);
	return (putuspecstr(tmp, flags));
}

int		pr_uchar(va_list ap, t_flags flags)
{
	unsigned int		tmp[2];

	tmp[0] = va_arg(ap, unsigned int);
	tmp[1] = '\0';
	return (putuspecstr(tmp, flags));
}
