/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:10:52 by gficara           #+#    #+#             */
/*   Updated: 2018/01/29 18:48:19 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_bin(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.dot == 1 && flags.pre == 0)
		return (putspecint("", flags));
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
	tmp = ft_itoa_base_u(i, 2, 0);
	tmp = zero(tmp, flags, 1);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}

int		pr_pnt(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	flags.has = 1;
	i = va_arg(ap, unsigned long);
	tmp = ft_itoa_base_u(i, 16, 0);
	if (i == 0 && flags.pre == 0)
	{
		ft_strdel(&tmp);
		flags.min = (flags.zer == 1) ? 1 : flags.min;
		return (putspecstr((flags.dot && !flags.pre) ? "0x" : "0x0", flags));
	}
	tmp = zerobase(tmp, flags, 1);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}

int		pr_mdec(va_list ap, t_flags flags)
{
	flags.l = 1;
	return (pr_dec(ap, flags));
}

int		pr_mudec(va_list ap, t_flags flags)
{
	flags.l = 1;
	return (pr_udec(ap, flags));
}

int		pr_moct(va_list ap, t_flags flags)
{
	flags.l = 1;
	return (pr_oct(ap, flags));
}
