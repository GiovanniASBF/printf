/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 01:52:12 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/21 15:04:30 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	char	conversion_type;
}			t_format;

void	ft_pntf_input_handler(va_list args, const char *format, int *count);
void	ft_pntf_printhex(unsigned long ptr, char *base, int *count);
int		ft_printf(const char *format, ...);
void	ft_pntf_print_char(char c, int *count);
void	ft_pntf_print_str(char *str, int *count);
void	ft_pntf_printptr(void *ptr, int *count);
void	ft_pntf_printnbr(int n, int *count);
void	ft_pntf_printunbr(unsigned int n, int *count);
int		ft_pntf_specifier_handler(const char *str, va_list args, int *count);

#endif