#include "libftprintf.h"

void	count_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		count_putchar('-', count);
		count_putnbr(-n, count);
	}
	else
	{
		if (n > 9)
			count_putnbr(n / 10, count);
		count_putchar((n % 10) + '0', count);
	}
}
