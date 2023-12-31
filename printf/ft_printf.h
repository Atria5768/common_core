/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:14:21 by macbookair        #+#    #+#             */
/*   Updated: 2024/01/05 18:35:02 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_format_string(const char *format, va_list args, size_t *i, size_t *printbyte);
int		ft_print_plain_string(const char *format, size_t *i, size_t *printbyte);
size_t	ft_printf_strlen(const char *s);

int		ft_print_c(char c, size_t *printbyte);
int		ft_print_s(char *s, size_t *printbyte);
int		ft_print_p(void *p, size_t *printbyte);
int		ft_print_d(long long n, size_t *printbyte);
int		ft_print_i(long long n, size_t *printbyte);
int		ft_print_u(unsigned long long n, size_t *printbyte);
int		ft_print_x(long long n, size_t *printbyte);
int		ft_print_xx(long long n, size_t *printbyte)
int		ft_print_percent(size_t *printbyte);
#endif