/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:34:16 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 15:42:06 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	count_putptr(void *ptr, int *count)
{
	count_putstr("0x", count);
	count_puthex((unsigned long)ptr, 0, count);
}
