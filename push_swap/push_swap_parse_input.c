/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonseo <seonseo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:37:25 by seonseo           #+#    #+#             */
/*   Updated: 2024/03/02 15:18:16 by seonseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_arr *args, t_stack *stack_a)
{
	char	**strings;
	int		err_flag;

	err_flag = get_strs(argc, argv, &strings);
	if (-1 != err_flag)
		err_flag = malloc_args(args, strings);
	if (-1 != err_flag)
		err_flag = fill_arr(args, strings);
	if (-1 != err_flag)
		err_flag = check_dup_arr(args);
	if (-1 != err_flag)
		err_flag = rank_based_indexing(args);
	if (-1 != err_flag)
		err_flag = init_stack_with_args(args, stack_a);
	if (2 == argc)
		free_strs(&strings);
	return (err_flag);
}

int	get_strs(int argc, char **argv, char ***strings)
{
	if (2 == argc)
	{
		*strings = ft_split(argv[1], ' ');
		if (NULL == *strings)
			return (-1);
	}
	else
		*strings = argv + 1;
	return (0);
}

int	malloc_args(t_arr *args, char **strings)
{
	args->size = ft_strslen(strings);
	args->arr = (int *)malloc(sizeof(*(args->arr)) * args->size);
	if (NULL == args->arr)
		return (-1);
	return (0);
}

void	free_strs(char ***strings)
{
	int	i;

	i = 0;
	while ((*strings)[i])
	{
		free((*strings)[i]);
		(*strings)[i] = NULL;
		i++;
	}
	free(*strings);
	*strings = NULL;
	strings = NULL;
}
