/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:02:06 by afonso            #+#    #+#             */
/*   Updated: 2022/10/27 17:41:21 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_stack(t_stack **lst)
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
		if (is_stack_complete(lst, 0))
			return ;
		if (a_ptr->content > ft_lstlast(*lst)->content
			&& a_ptr->next_node->content < ft_lstlast(*lst)->content)
			rotate(lst, 'a');
		if (a_ptr->content > a_ptr->next_node->content)
			swap(lst, 'a');
		if (a_ptr->content > ft_lstlast(*lst)->content
			|| a_ptr->next_node->content > ft_lstlast(*lst)->content)
			reverse_rotate(lst, 'a');
	}
}
