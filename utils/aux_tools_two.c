/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_tools_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:07:50 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/03 12:14:13 by user             ###   ########.fr       */
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
        args = argv;
        *new_argc = argc;
    }
    return (args);
}

int	check_for_duplicates(int argc, char **argv)
{
    int		i;
    int		j;
    int		num1;
    int		num2;
    char	**args;

    args = process_args(argc, argv, &argc);
    i = 0;
    while (args[i])
    {
        num1 = ft_atoi(args[i]);
        j = i + 1;
        while (args[j])
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

/*
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
