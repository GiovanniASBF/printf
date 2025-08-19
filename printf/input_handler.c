/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:55:05 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/15 02:21:15 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argument_validator(va_list args, int identifier);
void	specifier_handler(const char *str, va_list args, int *count);
int		specifier_identifier(const char *str);

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
	if (!ft_strncmp(str, "%c", 2))
		print_char((char)va_arg(args, int), count);
	else if (!ft_strncmp(str, "%s", 2))
		print_str(va_arg(args, char *), count);
	else if (!ft_strncmp(str, "%p", 2))
		print_str(ptr_to_str(va_arg(args, void *)), count);
	else if (!ft_strncmp(str, "%d", 2) || !ft_strncmp(str, "%i", 2))
		put_count_nbr(va_arg(args, int), count);
	else if (!ft_strncmp(str, "%u", 2))
		put_count_unbr(va_arg(args, unsigned int), count);
	else if (!ft_strncmp(str, "%x", 2))
		print_str(itohex(va_arg(args, unsigned int), "0123456789abcdef"),
			count);
	else if (!ft_strncmp(str, "%X", 2))
		print_str(itohex(va_arg(args, unsigned int), "0123456789ABCDEF"),
			count);
	else if (!ft_strncmp(str, "%%", 2))
		print_char('%', count);
	else
	{
		print_char(*str, count);
		str++;
		print_char(*str, count);
	}
}

char	*argument_validator(va_list args, int identifier)
{
	char	*str;

	if (identifier == 1 && (char)va_arg(args, int))
		return (ft_strdup((char)va_arg(args, int)));
	else if (identifier == 2 && va_arg(args, char *))
		return (ft_strdup(va_arg(args, char *)));
	else if (identifier == 3 && va_arg(args, void *))
		return (ptr_to_str(va_arg(args, void *)));
	else if (identifier == 4 && va_arg(args, int))
		return (ft_itoa(va_arg(args, int)));
	else if (identifier == 5 && va_arg(args, unsigned int))
		return (unsin_to_char(va_arg(args, unsigned int)));
	else if ((identifier == 6 || identifier == 7) && va_arg(args, unsigned int))
	{
		if (identifier == 6)
			return (itohex(va_arg(args, unsigned int), "0123456789abcdef"));
		else
			return (itohex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	}
	else if (identifier == 8)
		return (ft_strdup("%"));
	else
		return (ft_strdup(""));
}

int	specifier_identifier(const char *str)
{
	if (!ft_strncmp(str, "%c", 2))
		return (1);
	else if (!ft_strncmp(str, "%s", 2))
		return (2);
	else if (!ft_strncmp(str, "%p", 2))
		return (3);
	else if (!ft_strncmp(str, "%d", 2) || !ft_strncmp(str, "%i", 2))
		return (4);
	else if (!ft_strncmp(str, "%u", 2))
		return (5);
	else if (!ft_strncmp(str, "%x", 2))
		return (6);
	else if (!ft_strncmp(str, "%X", 2))
		return (7);
	else if (!ft_strncmp(str, "%%", 2))
		return (8);
	else
		return (0);
}
