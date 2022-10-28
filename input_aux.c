/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:25:45 by afonso            #+#    #+#             */
/*   Updated: 2022/10/18 12:26:00 by afonso           ###   ########.fr       */
/*                                                                       */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static int	is_signal(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

void	checkif_number(char **argv, int *ret_address, int i, int *j)
{
	static int	ret;

	if (ft_isalpha(argv[i][*j]))
		error();
	if (is_signal(argv[i][*j]))
	{
		(*j)++;
		if (!ft_isdigit(argv[i][*j]))
			error();
	}
	if (ft_isdigit(argv[i][*j]))
	{
		while (ft_isdigit(argv[i][*j]))
			(*j)++;
		if (is_signal(argv[i][*j]))
			error();
		ret++;
	}
	*ret_address = ret;
}

