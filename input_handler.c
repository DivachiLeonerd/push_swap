/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:36:09 by afonso            #+#    #+#             */
/*   Updated: 2022/10/17 15:46:35 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int **numbers, int argc);

int	*check_input(int argc, char **argv, int **numbers)
{
	int		i;

	i = 1;
	if (argc < 2)
		exit(0);
	*numbers = malloc((argc - 1) * sizeof(int));
	if (!(*numbers))
	{
		error_print("bad allocation\n");
		return (0);
	}
	while (i < argc)
	{
		(*numbers)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_repeated_args(argc, *numbers) == 0)
	{
		error_print("bad arguments\n");
		free (*numbers);
		exit (0);
	}
	sort_array(numbers, argc);
	return (*numbers);
}

static void	sort_array(int **numbers, int argc)
{
	int		i;
	int		lowest_num;

	lowest_num = 0;
	i = 0;
	while (i < argc - 1)
	{
		if ((*numbers)[i] < 0)
			if ((*numbers)[i] < lowest_num)
				lowest_num = (*numbers)[i];
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		(*numbers)[i] += -lowest_num;
		// ft_printf("%d\n", (*numbers)[i]);
		i++;
	}
	i = 0;
}

int	set_astack(t_stack **lst, int **numbers, int argc)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(lst, ft_lstnew((*numbers)[i]));
		i++;
	}
	(*(lst + 1)) = 0;
	if (is_stack_complete(lst, 0))
	{
		free_stack(lst);
		free(*numbers);
		return (0);
	}
	return (1);
}
