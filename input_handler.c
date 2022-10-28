/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:36:09 by afonso            #+#    #+#             */
/*   Updated: 2022/10/28 11:15:29 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(int **numbers, int argc);
static int	count_complex_arg(char **argv);
static void	allocate_complex_arg(char **argv, int **numbers);

int	check_input(int argc, char **argv, int **numbers)
{
	int	alloc;

	if (argc < 2)
		exit(0);
	are_args_ints(argv);
	alloc = count_complex_arg(argv);
	*numbers = malloc((alloc) * sizeof(int) + 1);
	if (!(*numbers))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	allocate_complex_arg(argv, numbers);
	if (check_repeated_args(alloc, *numbers) == 0)
	{
		write(2, "Error\n", 6);
		free (*numbers);
		exit (0);
	}
	fill_array(numbers, alloc);
	return (alloc);
}

static void	fill_array(int **numbers, int argc)
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
	while (i < argc)
	{
		(*numbers)[i] += -lowest_num;
		i++;
	}
}

int	set_astack(t_stack **lst, int **numbers, int argc)
{
	int		i;

	i = 0;
	while (i < argc)
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

static int	count_complex_arg(char **argv)
{
	int			i;
	int			j;
	int			ret;

	ret = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			checkif_number(argv, &ret, i, &j);
			if (argv[i][j])
				j++;
		}
		i++;
	}
	return (ret);
}

static void	allocate_complex_arg(char **argv, int **numbers)
{
	int		j;
	int		aux;
	int		arg_num;
	char	**temp;

	arg_num = 1;
	aux = 0;
	while (argv[arg_num])
	{
		j = 0;
		temp = ft_split(argv[arg_num], ' ');
		while (temp[j])
		{
			(*numbers)[aux++] = ft_atoi(temp[j]);
			j++;
		}
		j = 0;
		while (temp[j])
			free(temp[j++]);
		free(temp);
		arg_num++;
	}
}
