/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:26:38 by afonso            #+#    #+#             */
/*   Updated: 2022/10/21 17:18:32 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_stack(t_stack **lst)
{
	t_stack	*a_ptr;

	a_ptr = *lst;
	while (!is_stack_complete(lst, 0))
	{
		a_ptr = *lst;
		if (a_ptr->content > a_ptr->next_node->content
			&& ft_lstlast(*lst)->content < a_ptr->next_node->content)
		{
			rotate(lst, 'a');
			swap(lst, 'a');
		}
		else if (a_ptr->content > a_ptr->next_node->content)
			swap(lst, 'a');
		if (a_ptr->content > ft_lstlast(*lst)->content
			&& a_ptr->next_node->content < ft_lstlast(*lst)->content)
			rotate(lst, 'a');
		if (a_ptr->content > ft_lstlast(*lst)->content
			|| a_ptr->next_node->content > ft_lstlast(*lst)->content)
			reverse_rotate(lst, 'a');
	}
}
//pushes the 2 smallest numbers of stack A to stack B

static void	five_stack_aux(t_stack **lst, int *numbers)
{
	t_stack		*a_ptr;
	t_stack		*b_ptr;
	int			smallest_index;

	a_ptr = *lst;
	b_ptr = *(lst + 1);
	smallest_index = a_ptr->content;
	ft_printf("hello\n");
	ft_printf("SI:%d\n", smallest_index);
	while (a_ptr)
	{
		if (smallest_index > a_ptr->content)
			smallest_index = a_ptr->content;
		a_ptr = a_ptr->next_node;
	}
	ft_printf("world\n");
	while ((*lst)->content != smallest_index)
		rotate(lst, 'a');
	push(lst + 1, lst, 'b');
}

static void	five_stack(t_stack **lst, int *numbers)
{
	if (!is_stack_complete(lst, 1))
	{
		five_stack_aux(lst, numbers);
		five_stack_aux(lst, numbers);
		three_stack(lst);
	}
	if ((*(lst + 1))->content < (*(lst + 1))->next_node->content)
		swap(lst + 1, 'b');
	push(lst, lst + 1, 'a');
	push(lst, lst + 1, 'a');
}

void	sort_stacks(t_stack **lst, int arg_c, int *numbers)
{
	if (arg_c > 3 && arg_c <= 6)
		five_stack(lst, numbers);
	else if (arg_c <= 3)
		three_stack(lst);
	else
		sort_radix(lst);
	free(numbers);
}
