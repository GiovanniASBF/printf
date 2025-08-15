/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:01:40 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/15 02:01:50 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexlen(unsigned long ptr);
char			*itohex(unsigned long ptr, char *base);

char	*ptr_to_str(void *ptr)
{
	char	*hex;

	hex = itohex((unsigned long)ptr, "0123456789abcdef");
	return (ft_strjoin("0x", hex));
}

char	*itohex(unsigned long ptr, char *base)
{
	char	*hex;
	size_t	i;
	size_t	len;

	len = hexlen(ptr) + 1;
	i = len;
	hex = malloc(len * sizeof(char));
	if (!hex)
		return (NULL);
	hex[i--] = 0;
	while (i >= 0)
	{
		hex[i--] = base[ptr % 16];
		ptr = ptr / 16;
	}
	return (hex);
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
