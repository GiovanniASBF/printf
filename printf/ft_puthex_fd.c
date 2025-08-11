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

void	ft_puthex_fd(int n, int upper, int fd)
{
	int	remainder;
	int	ui_n;

	ui_n = (unsigned int)n;
	if (ui_n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if ((ui_n / 16) != 0)
		ft_puthex_fd((ui_n / 16), upper, fd);
	remainder = ui_n % 16;
	if (remainder < 10)
		ft_putchar_fd(remainder + '0', fd);
	else
	{
		if (upper)
			ft_putchar_fd(remainder - 10 + 'A', fd);
		else
			ft_putchar_fd(remainder - 10 + 'a', fd);
	}
}
