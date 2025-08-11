/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:35:42 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 16:01:16 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	printvalue(int specifier, va_list args);
static	int	validate_format_specifier(char *str);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = validate_format_specifier(*format);
			if (i != 0)
				printvalue(i, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
}

static	int	validate_format_specifier(char *str)
{
	if (str[1] == 'c')
		return (1);
	else if (str[1] == 's')
		return (2);
	else if (str[1] == 'p')
		return (3);
	else if (str[1] == 'd')
		return (4);
	else if (str[1] == 'i')
		return (4);
	else if (str[1] == 'u')
		return (5);
	else if (str[1] == 'x')
		return (6);
	else if (str[1] == 'X')
		return (7);
	else if (str[1] == '%')
		return (1);
	else
		return (0);
}

static	void	printvalue(int specifier, va_list args)
{
	if (specifier == 1)
		ft_putchar_fd(va_arg(args, char), 1);
	else if (specifier == 2)
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 4)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 5)
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 6)
		ft_puthex_fd(va_arg(args, int), 0, 1);
	else if (specifier == 7)
		ft_puthex_fd(va_arg(args, int), 1, 1);
}
