/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:02:21 by afonso            #+#    #+#             */
/*   Updated: 2022/10/13 16:12:09 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack[2];
	int		*numbers;

	if (!check_input(argc, argv, &numbers))
		return (0);
	if (!set_astack(stack, &numbers, argc))
		return (0);
	(stack)[1] = NULL;
	sort_stacks(stack, argc);
	free_stack(stack);
	return (0);
}
