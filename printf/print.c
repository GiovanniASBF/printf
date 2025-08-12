#include "libftprintf.h"

void	count_putchar(char c, int *count)
{
	write(1, &c, 1);
	count++;
}

void	count_putstr(char *str, int *count)
{
	if (!str)
		return ;
	while (*str)
	{
		count_putchar(*str, count);
		str++;
	}
}
