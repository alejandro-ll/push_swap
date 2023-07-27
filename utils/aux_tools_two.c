/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_tools_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:07:50 by allera-m          #+#    #+#             */
/*   Updated: 2023/07/27 20:33:15 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
int	check_for_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	int		num1;
	int		num2;
	char	**args;

	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc = count_words(argv[1], ' ');
	}
	else
		args = argv;
	while (i < argc)
	{
		num1 = atoi(args[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = atoi(args[j]);
			if (num1 == num2)
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

int	count_words(const char *str, char delimiter)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;

	while (*str)
	{
		if (*str == delimiter)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}*/
