/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:53:12 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/19 19:14:44 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_index(t_list *stack)
{
	int	max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

static int	get_position(t_list *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}

void	insert_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	position;
	int	size;

	while (*stack_b)
	{
		max_index = get_max_index(*stack_b);
		position = get_position(*stack_b, max_index);
		size = ft_lstsize(*stack_b);
		if (position <= size / 2)
		{
			while ((*stack_b)->index != max_index)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	process_chunk(t_list **stack_a, t_list **stack_b, t_chunk chunk)
{
	t_list	*temp;
	int		moved;

	moved = 0;
	temp = *stack_a;
	while (temp && moved < chunk.size)
	{
		if (temp->index >= chunk.start && temp->index <= chunk.end)
		{
			pb(stack_a, stack_b);
			moved++;
			temp = *stack_a;
		}
		else
		{
			ra(stack_a);
			temp = *stack_a;
		}
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b, int chunk_count)
{
	int		total_size;
	int		chunk_size;
	int		i;
	t_chunk	chunk;

	total_size = ft_lstsize(*stack_a);
	chunk_size = (total_size + chunk_count - 1) / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		chunk.start = i * chunk_size;
		chunk.end = (i + 1) * chunk_size - 1;
		if (chunk.end >= total_size)
			chunk.end = total_size - 1;
		chunk.size = chunk_size;
		process_chunk(stack_a, stack_b, chunk);
		i++;
	}
}
