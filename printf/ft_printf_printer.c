/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:30:54 by seonseo           #+#    #+#             */
/*   Updated: 2024/01/10 01:29:38 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(char c, size_t *printbyte)
{
	if (-1 == write(1, &c, 1))
		return (-1);
	(*printbyte)++;
	return (0);
}

int		ft_print_s(char *s, size_t *printbyte)
{
	size_t	len;

	len = ft_strlen(s);
	if (-1 == write(1, s, len))
		return (-1);
	*printbyte += len;
	return (0);
}

int		ft_print_hex(void *p, char *base, t_bool is_p, size_t *printbyte)
{
	unsigned long long	p_llu;
	char				p_str[18];
	int					i;
	size_t				len;

	p_llu = (unsigned long long)p;
	len = 0;
	i = 17;
	while (1)
	{
		p_str[i--] = base[p_llu % 16];
		p_llu /= 16;
		len++;
		if (0 == p_llu)
			break;
	}
	if (TRUE == is_p)
	{
		p_str[i--] = 'x';
		p_str[i--] = '0';
		len += 2;
	}
	*printbyte += len;
	if (-1 == write(1, &p_str[++i], len))
		return (-1);
	return (len);
}

#include <limits.h>

int		ft_print_d(long long lld, size_t *printbyte)
{
	long long	lld_cpy;
	char		lld_str[20];
	int			i;
	int			len;

	len = 0;
	i = 19;
	while (1)
	{
		lld_str[i--] = "0123456789"[lld_cpy % 10];
		lld_cpy /= 10;
		len++;
		if (0 == lld_cpy)
			break;
	}
	if (lld < 0)
	{
		lld_str[i--] = '-';
		len++;
	}
	if (-1 == write(1, &lld_str[++i], len))
		return (-1);
	return (len);
}

int		ft_print_u(unsigned long long llu, size_t *printbyte)
{
	char		llu_str[19];
	int			i;
	int			len;

	len = 0;
	i = 18;
	while (1)
	{
		llu_str[i--] = "0123456789"[llu % 10];
		llu /= 10;
		len++;
		if (0 == llu)
			break;
	}
	if (-1 == write(1, &llu_str[++i], len))
		return (-1);
	return (len);
}
