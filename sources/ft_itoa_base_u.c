/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:59:25 by gficara           #+#    #+#             */
/*   Updated: 2018/01/20 15:02:30 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		digit(unsigned long int num, int base, int caps)
{
	int					mod;

	if ((mod = num % base) < 10)
		return (mod + 48);
	else
		return ((caps == 0) ? ((mod - 10) + 'a') : ((mod - 10) + 'A'));
}

static	int			ft_lenn(unsigned long int num, int base)
{
	int					i;

	i = 0;
	while (num > 0)
	{
		i++;
		num = num / base;
	}
	return (i);
}

char				*ft_itoa_base_u(unsigned long int n, int base, int caps)
{
	char				*str;
	int					i;
	unsigned long int	num;

	if (base > 16)
		return (NULL);
	i = ft_lenn(n, base);
	str = (char*)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	num = n;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--i] = digit(num, base, caps);
		num = num / base;
	}
	return (str);
}
