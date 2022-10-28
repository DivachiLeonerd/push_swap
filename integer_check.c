/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:07:39 by afonso            #+#    #+#             */
/*   Updated: 2022/10/28 11:48:05 by afonso           ###   ########.fr       */
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

static void	int_check(int how_big)
{
	long int	num;
	long int	*array;
	int			temp;

	num = 0;
	while (how_big)
	{
		
	}
	ft_printf("num:%d\n", num);
	if (num > INT_MAX)
		error();
}

void	are_args_ints(char **argv)
{
	int			i;
	int			j;
	int			how_big;

	how_big = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && how_big < 11)
		{
			if (ft_isdigit(argv[i][j]))
				how_big++;
			j++;
			ft_printf("Check:%c\n", argv[i][j]);
		}
		if (how_big > 10)
			error();
		int_check(how_big);
		pause();
		i++;
	}
	return ;
}
