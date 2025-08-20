/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:01:40 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/20 18:24:05 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexlen(unsigned long ptr);
void			itohex(unsigned long ptr, char *base, int *count);

void	ptr_to_str(void *ptr, int *count)
{
	if (!ptr)
		print_str("nil", count);
	else
	{
		print_str("0x", count);
		itohex((unsigned long)ptr, "0123456789abcdef", count);
	}
}

void	itohex(unsigned long ptr, char *base, int *count)
{
	char	*hex;
	size_t	i;
	size_t	len;

	if (ptr == 0)
		len = 1;
	else
		len = hexlen(ptr);
	hex = malloc((len + 1) * sizeof(char));
	if (!hex)
		return ;
	i = len;
	hex[i--] = 0;
	while (ptr != 0)
	{
		hex[i--] = base[ptr % 16];
		ptr = ptr / 16;
	}
	print_str(hex, count);
	free(hex);
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

void	put_count_nbr(int n, int *count)
{
	if (n == -2147483648)
	{
		print_str("-2147483648", count);
		return ;
	}
	else if (n < 0)
	{
		print_char('-', count);
		put_count_nbr(-n, count);
	}
	else
	{
		if (n > 9)
			put_count_nbr(n / 10, count);
		print_char((n % 10) + '0', count);
	}
}

void	put_count_unbr(unsigned int n, int *count)
{
	if (n > 9)
		put_count_unbr(n / 10, count);
	print_char((n % 10) + '0', count);
}
