/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:24:44 by afonso            #+#    #+#             */
/*   Updated: 2022/10/11 14:29:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 1 if i > j : returns 0 if i < j : returns -1  if i == j
int	compare_int(int i, int j)
{
	if (i == j)
		return (-1);
	else
		return (i > j);
}

int	check_repeated_args(int argc, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 2)
	{
		while (j < argc - 1)
		{
			if (i == j)
				j++;
			if (compare_int(numbers[i], numbers[j]) == -1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
