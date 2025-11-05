/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:55:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/21 15:19:37 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	ft_pntf_get_format_info(const char *str);

void	ft_pntf_input_handler(va_list args, const char *format, int *count)
{
	int	consumed_len;
	
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				break ;
			consumed_len = specifier_handler(format, args, count);
			format += consumed_len;
		}
		else
			print_char(*format, count);
		format++;
	}
}

int	ft_pntf_specifier_handler(const char *str, va_list args, int *count)
{
	t_format	info;

	info = ft_pntf_get_format_info(str);
	if (info.conversion_type == 'c')
		print_char((char)va_arg(args, int), count);
	else if (info.conversion_type == 's')
		print_str(va_arg(args, char *), count);
	else if (info.conversion_type == 'p')
		printptr(va_arg(args, void *), count);
	else if (info.conversion_type == 'd' || info.conversion_type == 'i')
		printnbr(va_arg(args, int), count);
	else if (info.conversion_type == 'u')
		printunbr(va_arg(args, unsigned int), count);
	else if (info.conversion_type == 'x')
		printhex(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (info.conversion_type == 'X')
		printhex(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (info.conversion_type == '%')
		print_char('%', count);
	else
	{
		print_char(str, count);
		print_char(str[2], count);
	}
	return (2);
}

static t_format	ft_pntf_get_format_info(const char *str)
{
	t_format	info;
	char		specifier;

	specifier = str[2];
	info.conversion_type = '\0';
	if (ft_strchr("cspdiuxX%", specifier))
		info.conversion_type = specifier;
	return (info);
}
