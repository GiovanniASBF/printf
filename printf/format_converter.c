/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:01:40 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/15 02:31:12 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexlen(unsigned long ptr);
char			*itohex(unsigned long ptr, char *base);
int				numsize(unsigned int n);

char	*ptr_to_str(void *ptr)
{
	char	*hex;
	char	*str;

	hex = itohex((unsigned long)ptr, "0123456789abcdef");
	if (!hex)
		return (NULL);
	str = ft_strjoin("0x", hex);
	free(hex);
	return (str);
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

char	*unsin_to_char(unsigned int n)
{
	int		len;
	char	*str;

	len = numsize(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = 0;
	if (n == 0 && len == 0)
	{
		str[len] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	numsize(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
