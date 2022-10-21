/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:02:21 by afonso            #+#    #+#             */
/*   Updated: 2022/10/21 17:04:10 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack[2];
	int		*numbers;
	int		arg_c;

	stack[0] = NULL;
	(stack)[1] = NULL;
	arg_c = check_input(argc, argv, &numbers);
	if (!arg_c)
		return (0);
	if (!set_astack(stack, &numbers, arg_c))
		return (0);
	sort_stacks(stack, arg_c, numbers);
	free_stack(stack);
	return (0);
}
