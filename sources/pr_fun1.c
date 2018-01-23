/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:01:13 by gficara           #+#    #+#             */
/*   Updated: 2018/01/22 12:19:56 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_str(va_list ap, t_flags flags)
{
	char	*tmp;

	if (flags.l == 1)
		return (pr_ustr(ap, flags));
	tmp = va_arg(ap, char *);
	return (putspecstr(tmp, flags));
}

int		pr_char(va_list ap, t_flags flags)
{
	char	tmp[2];

	if (flags.l == 1)
		return (pr_uchar(ap, flags));
	tmp[0] = va_arg(ap, int);
	tmp[1] = '\0';
	return (putspecstr((char *)&tmp, flags));
}

char	*zero(char *tmp, t_flags flags, int u)
{
	int		i;

	i = ft_strlen(tmp);
	if (flags.pre > i)
		tmp = ft_sfstrjoin((char *)ft_memset((void *)ft_strnew(flags.pre - i),
					'0', flags.pre - i), tmp, 3);
	else if (flags.wid > i && flags.pre == 0 && flags.min == 0
			&& flags.zer == 1)
		tmp = ft_sfstrjoin((char *)ft_memset((void *)ft_strnew(flags.wid - i),
					'0', flags.wid - i), tmp, 3);
	if (i > 0 && u == 0)
		if (flags.plu == 1 || flags.spa == 1)
		{
			if (tmp[0] == '0' && flags.pre == 0)
				tmp[0] = (flags.plu == 0) ? ' ' : '+';
			else
				tmp = ft_sfstrjoin(((flags.plu == 1) ? "+" : " "), tmp, 2);
		}
	return (tmp);
}

int		pr_dec(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, long) : va_arg(ap, long long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (short)va_arg(ap, int) : (char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, intmax_t);
	else
		i = va_arg(ap, int);
	tmp = ft_itoa_base(i, 10, 0);
	tmp = zero(tmp, flags, 0);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}

int		pr_udec(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, long unsigned) :
			va_arg(ap, unsigned long long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (short unsigned)va_arg(ap, int) :
			(unsigned char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, uintmax_t);
	else
		i = va_arg(ap, unsigned int);
	tmp = ft_itoa_base_u(i, 10, 0);
	tmp = zero(tmp, flags, 1);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}
