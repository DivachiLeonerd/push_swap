/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:07:39 by afonso            #+#    #+#             */
/*   Updated: 2022/11/03 11:37:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int x, int power)
{
	int	i;
	int	num;

	num = 1;
	i = power;
	if (!power)
		return (1);
	while (i)
	{
		num = num * x;
		i--;
	}
	return (num);
}

int	are_args_ints(char *arg)
{
	long int	num;

	num = 0;
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

void	fill_array_temp(int **numbers, int *temp, int argc)
{
	int	index;

	index = 0;
	while (index < argc)
	{
		(*numbers)[index] = temp[index];
		index ++;
	}
}

int	alloc_complex_arg_aux(char **temp, int j)
{
	if (are_args_ints(temp[j]))
		return (1);
	else
	{
		while (j)
			free(temp[j--]);
		free(temp);
		error();
	}
	return (0);
}
