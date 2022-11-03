/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:09:53 by afonso            #+#    #+#             */
/*   Updated: 2022/11/03 12:14:49 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, char stack)
{
	int		second_content;
	t_stack	*node;

	node = *lst;
	if (!node || !node->next_node)
		return ;
	second_content = node->next_node->content;
	node->next_node->content = node->content;
	node->content = second_content;
	node = *lst;
	ft_printf("s%c\n", stack);
	return ;
}

void	rotate(t_stack **lst, char stack)
{
	t_stack	*tmp;
	t_stack	*node;

	node = *lst;
	tmp = ft_lstnew(node->content);
	ft_lstadd_back(lst, tmp);
	tmp->next_node = NULL;
	tmp = node->next_node;
	free(node);
	*lst = tmp;
	ft_printf("r%c\n", stack);
}

void	reverse_rotate(t_stack **lst, char stack)
{
	t_stack	*node;
	t_stack	*last;

	node = *lst;
	last = ft_lstlast(*lst);
	if (!node || !node->next_node)
		return ;
	while (node->next_node != last)
		node = node->next_node;
	node->next_node = NULL;
	ft_lstadd_front(lst, ft_lstnew(last->content));
	last->next_node = NULL;
	free(last);
	node = *lst;
	ft_printf("rr%c\n", stack);
	return ;
}

void	push(t_stack **stack_receiver, t_stack **stack_giver, char stack)
{
	t_stack	*temp;

	if (!*stack_giver)
		return ;
	temp = *stack_giver;
	*stack_giver = (*stack_giver)->next_node;
	if ((*stack_receiver) == NULL)
	{
		ft_lstadd_front(stack_receiver, ft_lstnew(temp->content));
		(*stack_receiver)->next_node = NULL;
	}
	else
		ft_lstadd_front(stack_receiver, ft_lstnew(temp->content));
	free(temp);
	ft_printf("p%c\n", stack);
}
