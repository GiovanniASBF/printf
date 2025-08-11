/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:33:35 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 14:18:37 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libftprintf.h"

void	ft_puthex_fd(int n, int fd)
{
	int	remainder;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_puthex_fd(-n, fd);
	}
	if ((n / 16) != 0)
		ft_puthex_fd((n / 16), fd);
	remainder = n % 16;
	if (remainder < 10)
		ft_putchar_fd(remainder + '0', fd);
	else
		ft_putchar_fd(remainder - 10 + 'A', fd);
}
