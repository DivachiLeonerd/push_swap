/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:33:16 by afonso            #+#    #+#             */
/*   Updated: 2022/10/24 17:29:01 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function sorts stack A with bitwise operations
//first, it checks if the stack is sorted
//if not, it begins the sorting process
//starts with the one's then the ten's and the hundred's
//by comparing the numbers with 1, 10 and 100, etc... in binary

//this function checks how many numbers there are in stack A

int	count_stack(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next_node;
		i++;
	}
	return (i);
}

int	compare_bits(int number, int binary)
{
	int	compare;

	compare = number & binary;
	if (compare == 0)
		return (0);
	return (1);
}

//this function compares the numbers in stack with binary and pushes to stack b

void	compare_n_push(t_stack **lst, int binary)
{
	int		i;
	int		temp;

	i = count_stack(*lst);
	temp = i;
	while (1)
	{
		if (!compare_bits((*lst)->content, binary))
		{
			push(lst + 1, lst, 'b');
			i--;
		}
		else
			rotate(lst, 'a');
		temp--;
		if (temp == 0)
			break ;
	}
}

//Ideally, this function should compare_n_push() for each binary number
//and then push them back to stack A
void	sort_radix(t_stack **lst)
{
	int		i;
	int		binary;

	binary = 1;
	while (!is_stack_complete(lst, 1))
	{
		compare_n_push(lst, binary);
		i = count_stack(*(lst + 1));
		while (i != 0)
		{
			push(lst, lst + 1, 'a');
			i--;
		}
		binary *= 2;
	}
	return ;
}
