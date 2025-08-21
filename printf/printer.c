/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:58:48 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/21 15:23:26 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	print_str(char *str, int *count)
{
	if (str == NULL)
	{
		print_str("(null)", count);
		return ;
	}
	while (*str)
	{
		print_char(*str, count);
		str++;
	}
}
