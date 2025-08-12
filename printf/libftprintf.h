/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:50:52 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/11 15:58:23 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

void	count_puthex(int n, int upper, int *count);
void	count_putptr(void *ptr, int *count);
void	count_putnbr(int n, int *count);
void	count_putunsnbr(unsigned int n, int *count);
void	count_putchar(char c, int *count);
void	count_putstr(char *str, int *count);

#endif