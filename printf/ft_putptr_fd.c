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

void	ft_putptr_fd(void *ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_puthex_fd((unsigned long)ptr, 0, fd);
}
