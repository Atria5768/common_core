/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:21 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/02 15:13:06 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

int	ft_atoi_safe(const char *str, int *err_flag)
{
	size_t		i;
	int			sign;
	long long	number;

	*err_flag = 0;
	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if ('+' == str[i] || '-' == str[i])
	{
		if ('-' == str[i])
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i++] - '0';
		if (number * sign < (-INT_MAX - 1) || INT_MAX < number * sign)
			*err_flag = -1;
	}
	if (0 == i || '\0' != str[i])
		*err_flag = -1;
	return ((int)(number * sign));
}

int	stack_add_bottom(t_stack *stack_a, int n)
{
	t_node	*new_node;

	new_node = make_node(n);
	if (new_node == NULL)
		return (-1);
	if (NULL == stack_a->bottom)
	{
		stack_a->top = new_node;
		stack_a->bottom = new_node;
	}
	else
	{
		new_node->upper = stack_a->bottom;
		stack_a->bottom->lower = new_node;
		stack_a->bottom = new_node;
	}
	(stack_a->size)++;
	return (0);
}

t_node	*make_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(*new_node));
	if (NULL == new_node)
		return (NULL);
	*new_node = (t_node){};
	new_node->value = n;
	return (new_node);
}
