/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:56:16 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 12:56:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//We must assign the value of the index ordered by data value traversing the list
//Example: we have 13 42 7, the index values should be 2 3 1

#include "../includes/push_swap.h"

static t_list  *get_next_min(t_list **stack)
{
    t_list  *min;
    t_list  *head;
    int min_exist;

    min = NULL;
    head = *stack;
    min_exist = 0;
    if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!min_exist || head->value < min->value))
			{
				min = head;
				min_exist = 1;
			}
			head = head->next;
		}
	}
    return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}