/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:06:43 by gficara           #+#    #+#             */
/*   Updated: 2018/01/29 18:21:48 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zerox(char *tmp, t_flags flags, int u)
{
	if (tmp[0] == '0' && flags.pre == 0)
	{
		if (tmp[1] == '0')
			tmp[1] = (u == 1) ? 'x' : 'X';
		else
		{
			tmp[0] = (u == 1) ? 'x' : 'X';
			tmp = ft_sfstrjoin("0", tmp, 2);
		}
	}
	else
		tmp = ft_sfstrjoin((u == 1) ? "0x" : "0X", tmp, 2);
	return (tmp);
}

char		*zerobase(char *tmp, t_flags flags, int u)
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
	if (i > 0 && u == 0 && flags.has == 1)
		if (tmp[0] != '0' && flags.pre == 0)
			tmp = ft_sfstrjoin("0", tmp, 2);
	if (i > 0 && u != 0 && flags.has == 1)
		tmp = zerox(tmp, flags, u);
	return (tmp);
}

int			pr_oct(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, unsigned long) :
			va_arg(ap, unsigned long long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (unsigned short)va_arg(ap, int) :
			(unsigned char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, uintmax_t);
	else
		i = va_arg(ap, unsigned int);
	if (flags.dot == 1 && flags.pre == 0 && i == 0)
		return (hashdown(flags, (flags.has == 1) ? 0 : 1));
	if (i == 0)
		return (hashdown(flags, 0));
	tmp = ft_itoa_base_u(i, 8, 0);
	tmp = zerobase(tmp, flags, 0);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}

int			pr_hex(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.dot == 1 && flags.pre == 0)
		return (hashdown(flags, 1));
	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, unsigned long) :
			va_arg(ap, unsigned long long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (unsigned short)va_arg(ap, int) :
			(unsigned char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, uintmax_t);
	else
		i = va_arg(ap, unsigned int);
	if (i == 0)
		return (hashdown(flags, 0));
	tmp = ft_itoa_base_u(i, 16, 0);
	tmp = zerobase(tmp, flags, 1);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}

int			pr_mhex(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.dot == 1 && flags.pre == 0)
		return (hashdown(flags, 1));
	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, unsigned long) :
			va_arg(ap, unsigned long long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (unsigned short)va_arg(ap, int) :
			(unsigned char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, uintmax_t);
	else
		i = va_arg(ap, unsigned int);
	if (i == 0)
		return (hashdown(flags, 0));
	tmp = ft_itoa_base_u(i, 16, 1);
	tmp = zerobase(tmp, flags, 2);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}
