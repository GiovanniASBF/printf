/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:33:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 15:01:50 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

void	count_puthex(int n, int upper, int *count)
{
	int	remainder;
	int	ui_n;

	ui_n = (unsigned int)n;
	if (ui_n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if ((ui_n / 16) != 0)
		count_puthex((ui_n / 16), upper, count);
	remainder = ui_n % 16;
	if (remainder < 10)
		count_putchar(remainder + '0', count);
	else
	{
		if (upper)
			count_putchar(remainder - 10 + 'A', count);
		else
			count_putchar(remainder - 10 + 'a', count);
	}
}
