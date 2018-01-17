#include"includes/ft_printf.h"
#include<stdio.h>

int main()
{
	char	*line = "gabriele";

	ft_putnbr(printf("%zd\n",(unsigned long)-75807));
//	ft_putnbr(ft_printf("%-100zd\n", (unsigned long)-75807));
//	ft_putstr(ft_itoa_base_u(111, 10, 0));
	return 0;
}
