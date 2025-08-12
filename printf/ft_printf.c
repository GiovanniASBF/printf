/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:35:42 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 16:12:05 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	printvalue(int specifier, va_list args, int *ptrcount);
static	int	validate_format_specifier(char *str);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		*ptrcount;

	count = 0;
	ptrcount = &count;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			i = validate_format_specifier(*format);
			if (i != 0)
				printvalue(i, args, ptrcount);
		}
		else
			count_putchar(*format, ptrcount);
		format++;
	}
	return (count);
}

static	int	validate_format_specifier(char *str)
{
	if (!ft_strncmp("%c", *str, 2))
		return (1);
	else if (!ft_strncmp("%s", *str, 2))
		return (2);
	else if (!ft_strncmp("%p", *str, 2))
		return (3);
	else if (!ft_strncmp("%d", *str, 2))
		return (4);
	else if (!ft_strncmp("%i", *str, 2))
		return (4);
	else if (!ft_strncmp("%u", *str, 2))
		return (5);
	else if (!ft_strncmp("%x", *str, 2))
		return (6);
	else if (!ft_strncmp("%X", *str, 2))
		return (7);
	else if (!ft_strncmp("%%", *str, 2))
		return (1);
	else
		return (0);
}

static	void	printvalue(int specifier, va_list args, int *ptrcount)
{
	if (specifier == 1)
		count_putchar(va_arg(args, char), ptrcount);
	else if (specifier == 2)
		count_putstr(va_arg(args, char *), ptrcount);
	else if (specifier == 3)
		count_putptr(va_arg(args, void *), ptrcount);
	else if (specifier == 4)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 5)
		count_putunsnbr(va_arg(args, unsigned int), ptrcount);
	else if (specifier == 6)
		count_puthex(va_arg(args, int), 0, ptrcount);
	else if (specifier == 7)
		count_puthex(va_arg(args, int), 1, ptrcount);
}
