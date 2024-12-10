/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_tools_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:07:50 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/10 18:26:04 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**process_args(int argc, char **argv, int *new_argc)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*new_argc = 0;
		while (args[*new_argc])
			(*new_argc)++;
	}
	else
	{
		args = argv + 1;
		*new_argc = argc - 1;
	}
	return (args);
}

int	is_number_within_limits(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_duplicates(int argc, char **argv)
{
	int		i;
	int		j;
	int		num1;
	int		num2;
	char	**args;
	int		new_argc;

	args = process_args(argc, argv, &new_argc);
	i = 0;
	while (i < new_argc)
	{
		num1 = ft_atoi(args[i]);
		j = i + 1;
		while (j < new_argc)
		{
			num2 = ft_atoi(args[j]);
			if (num1 == num2)
			{
				if (argc == 2)
					free(args);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (argc == 2)
		free(args);
	return (0);
}

int	check_for_non_numeric(int argc, char **argv)
{
	int i;
	int j;
	char **args;
	int new_argc;

	args = process_args(argc, argv, &new_argc);
	i = 0;
	while (i < new_argc)
	{
		j = 0;
		if ((args[i][j] == '-' || args[i][j] == '+') && args[i][j + 1] != '\0')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				if (argc == 2)
					free(args);
				return (1);
			}
			j++;
		}
		if (!is_number_within_limits(args[i]))
		{
			if (argc == 2)
				free(args);
			return (1);
		}
		i++;
	}
	if (argc == 2)
		free(args);
	return (0);
}
