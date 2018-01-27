/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:16:10 by gficara           #+#    #+#             */
/*   Updated: 2018/01/26 11:54:49 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	initflags(void)
{
	t_flags	new;

	new.min = 0;
	new.plu = 0;
	new.spa = 0;
	new.zer = 0;
	new.has = 0;
	new.h = 0;
	new.l = 0;
	new.z = 0;
	new.j = 0;
	new.wid = 0;
	new.pre = 0;
	new.dot = 0;
	new.per = 0;
	return (new);
}

int				flagcheck(char *pnt, int *count, va_list ap)
{
	t_flags	flags;
	size_t	i;

	flags = initflags();
	i = 0;
	i += findspec(pnt, ap, flags, count);
	return (i);
}

static char		*init(int *i, int *last, int *count,
		const char *restrict format)
{
	*i = 0;
	*count = 0;
	*last = 0;
	return ((char *)format);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		last;
	int		count;
	char	*pnt;

	va_start(ap, format);
	pnt = init(&i, &last, &count, format);
	while (pnt[i])
		if (pnt[i++] == '%')
		{
			ft_putnstr(pnt + last, (i - last) - 1);
			i += flagcheck(pnt + i, &count, ap);
			last = i;
		}
		else
			count++;
	ft_putnstr(pnt + last, i - last);
	va_end(ap);
	return (count);
}
