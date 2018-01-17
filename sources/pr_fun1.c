/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fun1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:01:13 by gficara           #+#    #+#             */
/*   Updated: 2018/01/17 18:06:12 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pr_str(va_list ap, t_flags flags)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	return (putspecstr(tmp, flags));
}

int		pr_char(va_list ap, t_flags flags)
{
	char	tmp[2];

	tmp[0] = va_arg(ap, int);
	tmp[1] = '\0';
	return (putspecstr((char *)&tmp, flags));
}

int		pr_dec(va_list ap, t_flags flags)
{
	char		*tmp;
	int			ret;
	intmax_t	i;

	if (flags.l != 0)
		i = (flags.l == 1) ? va_arg(ap, long) : va_arg(ap, long);
	else if (flags.h != 0)
		i = (flags.h == 1) ? (short)va_arg(ap, int) : (char)va_arg(ap, int);
	else if (flags.z == 1 || flags.j == 1)
		i = (flags.z == 1) ? va_arg(ap, size_t) : va_arg(ap, intmax_t);
	else
		i = va_arg(ap, int);
	tmp = ft_itoa_base(i, 10, 0);
	if (i > 0)
		if (flags.plu == 1 || flags.spa == 1)
			tmp = ft_sfstrjoin(((flags.plu == 1) ? "+" : " "), tmp, 2);
	ret = putspecint(tmp, flags);
	ft_strdel(&tmp);
	return (ret);
}
