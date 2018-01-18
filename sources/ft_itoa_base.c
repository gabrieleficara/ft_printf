/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:59:25 by gficara           #+#    #+#             */
/*   Updated: 2018/01/18 13:46:20 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		digit(intmax_t num, int base, int caps)
{
	int				mod;

	if ((mod = num % base) < 10)
		return (mod + 48);
	else
		return ((caps == 0) ? ((mod - 10) + 'a') : ((mod - 10) + 'A'));
}

static	int			ft_lenn(intmax_t num, int base)
{
	int				i;

	i = 0;
	if (num <= 0)
	{
		i++;
		num = ft_abs_base(num);
	}
	while (num > 0)
	{
		i++;
		num = num / base;
	}
	return (i);
}

char				*ft_itoa_base(intmax_t n, int base, int caps)
{
	char		*str;
	int			i;
	intmax_t	num;

	if (base > 16)
		return (NULL);
	i = ft_lenn(n, base);
	str = (char*)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	num = ft_abs_base(n);
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--i] = digit(num, base, caps);
		num = num / base;
	}
	if (n < 0)
		str[--i] = '-';
	return (str);
}
