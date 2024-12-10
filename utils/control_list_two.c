/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:52:02 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/10 19:53:19 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
