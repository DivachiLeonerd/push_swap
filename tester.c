/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:02:40 by afonso            #+#    #+#             */
/*   Updated: 2022/10/13 16:26:47 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*lst[2];
	t_stack	*node;
	int		*numbers;

	if (!check_input(argc, argv, &numbers))
		return (0);
	if (!numbers)
		return (0);
	if (!set_astack(lst, &numbers, argc))
		return (0);
	node = *lst;
	(lst)[1] = NULL;
	sort_stacks(lst, argc);
	node = *lst;
	ft_printf("printing the whole thing:\n");
	while (node)
	{
		ft_printf("%d\n", node->content);
		node = node->next_node;
	}
	free_stack(lst);
	return (0);
}
