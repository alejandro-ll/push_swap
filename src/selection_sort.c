/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:53:12 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/10 18:52:46 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	selection_sort(t_list **stack_a, t_list **stack_b)
{
    int		min_index;
    int		distance;

    while (ft_lstsize(*stack_a) > 0)
    {
        min_index = find_min_index(*stack_a);
        distance = get_distance(stack_a, min_index);
        make_top(stack_a, distance);
        pb(stack_a, stack_b);
    }
    while (ft_lstsize(*stack_b) > 0)
    {
        pa(stack_a, stack_b);
    }
}

int	find_min_index(t_list *stack)
{
    int		min_index;
    t_list	*current;

    min_index = stack->index;
    current = stack;
    while (current)
    {
        if (current->index < min_index)
            min_index = current->index;
        current = current->next;
    }
    return (min_index);
}
