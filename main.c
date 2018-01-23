#include"includes/ft_printf.h"
#include<stdio.h>
#include<locale.h>

int main()
{
	char	*line = "gabriele";
	int		i;

	setlocale(LC_ALL, "");
	ft_putnbr(printf("%C\n", L'😊'));
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(ft_printf("%C\n", L'😊'));
//	ft_putstr(ft_itoa_base_u(111, 10, 0));
	return 0;
}
