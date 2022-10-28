/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:26:38 by afonso            #+#    #+#             */
/*   Updated: 2022/10/27 18:05:22 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_or_rr(int index, t_stack **lst)
{
	if (index >= 3)
	{
		while (index < ft_lstsize(*lst))
		{
			index++;
			reverse_rotate(lst, 'a');
		}
	}
	else
	{
		while (index--)
		{
			rotate(lst, 'a');
		}
	}
}

static int	get_index(t_stack **lst)
{
	t_stack		*a_ptr;
	int			i;
	int			index;
	int			smallest_number;

	index = 0;
	a_ptr = *lst;
	i = 0;
	smallest_number = a_ptr->content;
	while (a_ptr)
	{
		if (smallest_number > a_ptr->content)
		{
			smallest_number = a_ptr->content;
			index = i;
		}
		i++;
		a_ptr = a_ptr->next_node;
	}
	return (index);
}

//pushes the 2 smallest numbers of stack A to stack B

static void	five_stack_aux(t_stack **lst)
{
	int	i;

	while (ft_lstsize(*lst) != 3)
	{
		i = get_index(lst);
		rot_or_rr(i, lst);
		push(lst + 1, lst, 'b');
		i = 0;
	}
}

static void	five_stack(t_stack **lst)
{
	if (!is_stack_complete(lst, 1))
	{
		five_stack_aux(lst);
		three_stack(lst);
	}
	push(lst, lst + 1, 'a');
	push(lst, lst + 1, 'a');
}

void	sort_stacks(t_stack **lst, int arg_c, int *numbers)
{
	if (arg_c > 3 && arg_c <= 6)
		five_stack(lst);
	else if (arg_c <= 3)
		three_stack(lst);
	else
		sort_radix(lst);
	free(numbers);
}
