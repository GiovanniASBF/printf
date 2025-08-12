/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:01 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 15:56:44 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	count_putunsnbr(unsigned int n, int *count)
{
	while (n > 9)
		count_putunsnbr((n / 10), count);
	count_putchar((n % 10) + '0', count);
}
