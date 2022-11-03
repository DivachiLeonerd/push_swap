/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:02:06 by afonso            #+#    #+#             */
/*   Updated: 2022/11/03 12:26:23 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_stack(t_stack **lst)
{
	while (!is_stack_complete(lst, 0))
	{
		if ((*lst)->content > (*lst)->next_node->content
			&& ft_lstlast(*lst)->content < (*lst)->next_node->content)
		{
			rotate(lst, 'a');
			swap(lst, 'a');
		}
		if (is_stack_complete(lst, 0))
			return ;
		if ((*lst)->content > ft_lstlast(*lst)->content
			&& (*lst)->next_node->content < ft_lstlast(*lst)->content)
			rotate(lst, 'a');
		if ((*lst)->content > (*lst)->next_node->content)
			swap(lst, 'a');
		if ((*lst)->content > ft_lstlast(*lst)->content
			|| (*lst)->next_node->content > ft_lstlast(*lst)->content)
			reverse_rotate(lst, 'a');
	}
}
