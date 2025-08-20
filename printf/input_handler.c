/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:55:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/20 18:22:52 by gaguiar-         ###   ########.fr       */
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
			format ++;
		}
		else
			print_char(*format, count);
		format++;
	}
}

void	specifier_handler(const char *str, va_list args, int *count)
{
	if (!ft_strncmp(str, "%c", 2))
		print_char((char)va_arg(args, int), count);
	else if (!ft_strncmp(str, "%s", 2))
		print_str(va_arg(args, char *), count);
	else if (!ft_strncmp(str, "%p", 2))
		ptr_to_str(va_arg(args, void *), count);
	else if (!ft_strncmp(str, "%d", 2) || !ft_strncmp(str, "%i", 2))
		put_count_nbr(va_arg(args, int), count);
	else if (!ft_strncmp(str, "%u", 2))
		put_count_unbr(va_arg(args, unsigned int), count);
	else if (!ft_strncmp(str, "%x", 2))
		itohex(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (!ft_strncmp(str, "%X", 2))
		itohex(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (!ft_strncmp(str, "%%", 2))
		print_char('%', count);
	else
	{
		print_char(*str, count);
		print_char(*(str + 1), count);
	}
}
