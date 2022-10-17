/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:39:57 by afonso            #+#    #+#             */
/*   Updated: 2022/10/13 16:13:40 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **lst)
{
	t_stack	*node;
	t_stack	*aux;

	node = *lst;
	aux = (t_stack *)1;
	while (aux)
	{
		aux = node->next_node;
		free(node);
		node = aux;
	}
	return ;
}

int	find_average(t_stack *stack)
{
	int	average;

	average = 0;
	while (stack)
	{
		average += stack->content;
		stack = stack->next_node;
	}
	return (average);
}
