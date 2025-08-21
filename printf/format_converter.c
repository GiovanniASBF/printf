/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:01:40 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/21 15:18:14 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexlen(unsigned long ptr);
void			printhex(unsigned long ptr, char *base, int *count);

void	printptr(void *ptr, int *count)
{
	if (!ptr)
		print_str("(nil)", count);
	else
	{
		print_str("0x", count);
		printhex((unsigned long)ptr, "0123456789abcdef", count);
	}
}

void	printhex(unsigned long ptr, char *base, int *count)
{
	char	*hex;
	size_t	i;
	size_t	len;

	if (ptr == 0)
		print_char('0', count);
	else
	{
		len = hexlen(ptr);
		hex = ft_calloc((len + 1), sizeof(char));
		if (!hex)
			return ;
		i = len - 1;
		while (ptr != 0)
		{
			hex[i--] = base[ptr % 16];
			ptr = ptr / 16;
		}
		print_str(hex, count);
		free(hex);
	}
}

static size_t	hexlen(unsigned long ptr)
{
	size_t	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

void	printnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		print_str("-2147483648", count);
		return ;
	}
	else if (n < 0)
	{
		print_char('-', count);
		printnbr(-n, count);
	}
	else
	{
		if (n > 9)
			printnbr(n / 10, count);
		print_char((n % 10) + '0', count);
	}
}

void	printunbr(unsigned int n, int *count)
{
	if (n > 9)
		printunbr(n / 10, count);
	print_char((n % 10) + '0', count);
}
