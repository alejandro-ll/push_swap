/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_instructions_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:04:59 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/19 19:30:06 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	reverserotate(t_list **_stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*_stack) < 2)
		return (-1);
	head = *_stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *_stack;
	*_stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverserotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

void	make_top(t_list **stack, int distance)
{
	if (distance <= ft_lstsize(*stack) / 2)
	{
		while (distance-- > 0)
		{
			ra(stack);
		}
	}
	else
	{
		distance = ft_lstsize(*stack) - distance;
		while (distance-- > 0)
		{
			rra(stack);
		}
	}
}
