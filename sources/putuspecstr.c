#include "ft_printf.h"

void	uniwrite(int let, int len)
{
	int		i;
	int		tmp[4];

	i = 0;
	if (len == 1)
		return (ft_putchar(let));
	else
	{
		if (let > 2)
			tmp[i++] = (let == 4) ? (4143972352 | let) >> 24 :
				(15663104 & let) >> 16;
		else
			tmp[i++] = (57088 & let) >> 8;
		if (len > 3)
			tmp[i++] = (12517376 & let) >> 16;
		if (len > 2)
			tmp[i++] = (57088 & let) >> 8;
		if (len > 1)
			tmp[i++] = 191 & let;
		write(1, tmp, i);
	}
}
