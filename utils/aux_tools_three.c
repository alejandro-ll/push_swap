/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_tools_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:50 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/10 19:43:09 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_non_numeric(char *arg)
{
	int	j;

	j = 0;
	if ((arg[j] == '-' || arg[j] == '+') && arg[j + 1] != '\0')
		j++;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			return (1);
		j++;
	}
	return (0);
}

int	has_duplicate(char **args, int new_argc, int num1, int i)
{
	int	j;

	j = i + 1;
	while (j < new_argc)
	{
		if (num1 == ft_atoi(args[j]))
			return (1);
		j++;
	}
	return (0);
}
