/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:35:42 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 13:13:26 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	printvalue(int specifier, va_list args);
static	int	validate_format_specifier(char *str);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = validate_format_specifier(*format);
			/* verify the next char
			make a function to verify wich function may be called based on the next char
			after execute the function, move the pointer forward
			*/
		}
		
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
		return (5);
	else if (str[1] == 'u')
		return (6);
	else if (str[1] == 'x')
		return (7);
	else if (str[1] == 'X')
		return (8);
	else if (str[1] == '%')
		return (9);
	else
		return (0);
}

static	void	printvalue(int specifier, va_list args)
{
	if (specifier == 1)
		ft_putchar_fd(va_arg(args, char), 1);
	else if (specifier == 2)
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 3)
	{
		/* code */
	}
	
}
