/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:52:12 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/20 18:52:00 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

void	input_handler(va_list args, const char *format, int *count);
void	itohex(unsigned long ptr, char *base, int *count);
int		ft_printf(const char *format, ...);
void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	ptr_to_str(void *ptr, int *count);
void	put_count_nbr(int n, int *count);
void	put_count_unbr(unsigned int n, int *count);

#endif