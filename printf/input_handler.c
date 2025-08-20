/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:55:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/20 16:24:53 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_handler(const char *str, va_list args, int *count);

void	input_handler(va_list args, const char *format, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			specifier_handler(format, args, count);
			format += 2;
		}
		print_char(*format, count);
		format++;
	}
}

void	specifier_handler(const char *str, va_list args, int *count)
{
	int		identifier;
	char	*arg_verified;

	identifier = specifier_identifier(str);
	if (identifier > 0)
	{
		arg_verified = argument_validator(args, identifier);
		print_str(arg_verified, count);
		free(arg_verified);
	}
	else
	{
		print_char(*str, count);
		print_char(*(str + 1), count);
	}
}
