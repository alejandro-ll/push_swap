/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:27:35 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/19 15:17:15 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(args, i);
	index_stack(stack);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
	{
		chunk_sort(stack_a, stack_b, 6);
		insert_back_to_a(stack_a, stack_b);
	}
}

static int	process_stacks(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (check_for_duplicates(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (check_for_non_numeric(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (process_stacks(argc, argv));
}
