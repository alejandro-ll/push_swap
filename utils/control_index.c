/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:11:41 by allera-m          #+#    #+#             */
/*   Updated: 2023/07/19 22:12:14 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_next_min(t_list *stack)
{
	t_list	*min;
	t_list	*head;
	int		min_exist;

	min = NULL;
	head = stack;
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
    //printf("Mínimo: %d\n", min ? min->value : -1);
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(*stack);
	while (head)
	{
		head->index = index++;
		//printf("Valor: %d, Índice: %d\n", head->value, head->index);
		head = get_next_min(*stack);
	}
}