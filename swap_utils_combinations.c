/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_combinations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:00:50 by afonso            #+#    #+#             */
/*   Updated: 2022/10/13 16:06:49 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_rotate(t_stack **lst)
{
	rotate(lst, 'a');
	rotate(lst + 1, 'b');
	write(1, "sr\n", 14);
}

int	is_next_bigger(t_stack **lst)
{
	t_stack	*current;	
	t_stack	*next;

	current = *lst;
	next = current->next_node;
	if (next == NULL)
		return (1);
	return (current->content < next->content);
}

int	is_stack_complete(t_stack **lst, int flag)
{
	t_stack	*current;
	int		isnextbigger;

	isnextbigger = 1;
	current = *lst;
	if (flag == 1)
		if (*(lst + 1))
			return (0);
	while (isnextbigger && current)
	{
		isnextbigger = is_next_bigger(&current);
		current = current->next_node;
	}
	return (isnextbigger);
}
