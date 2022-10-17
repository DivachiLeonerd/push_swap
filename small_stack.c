/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:26:38 by afonso            #+#    #+#             */
/*   Updated: 2022/10/17 15:44:01 by afonso           ###   ########.fr       */
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

static void	five_stack_aux(t_stack **lst)
{
	t_stack		**a_ptr;
	t_stack		**b_ptr;
	int			push_num;

	push_num = 2;
	a_ptr = lst;
	b_ptr = lst + 1;
	if ((*b_ptr)->content > (*b_ptr)->next_node->content)
		swap(lst + 1, 'b');
	while (!is_stack_complete(lst, 1))
	{
		if (push_num && (*b_ptr)->content < (*a_ptr)->content)
		{
			push(a_ptr, b_ptr, 'a');
			rotate(a_ptr, 'a');
			push_num--;
		}
		else
			rotate(a_ptr, 'a');
	}
}

static void	five_stack(t_stack **lst)
{

	if (!is_stack_complete(lst, 1))
	{
		push(lst + 1, lst, 'b');
		push(lst + 1, lst, 'b');
		three_stack(lst);
	}
	five_stack_aux(lst);
}

void	sort_stacks(t_stack **lst, int argc)
{
	if (argc > 4 && argc <= 6)
		return (five_stack(lst));
	else if (argc <= 4)
		return (three_stack(lst));
	else
		sort_radix(lst);
}
