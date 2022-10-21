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

int	is_integer(void *x)
{
	if (sizeof(*x) == sizeof(int))
		return (1);
	else
		return (0);
}

void	checkif_number(char **argv, int *ret_address, int i, int *j)
{
	static int	ret;

	if (ft_isalpha(argv[i][*j]))
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (ft_isdigit(argv[i][*j]))
	{
		while (ft_isdigit(argv[i][*j]))
			(*j)++;
		ret++;
	}
	*ret_address = ret;
}
