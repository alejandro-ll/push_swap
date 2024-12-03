/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_tools_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:07:50 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/03 18:52:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**process_args(int argc, char **argv, int *new_argc)
{
    char	**args;

    if (argc == 2)
    {
        // Divide la cadena de entrada en un array de strings
        args = ft_split(argv[1], ' ');
        *new_argc = 0;
        // Cuenta el número de elementos en el array args
        while (args[*new_argc])
            (*new_argc)++;
    }
    else
    {
        // Si los argumentos no se pasaron como una sola cadena
        args = argv + 1; // Saltar el nombre del programa
        *new_argc = argc - 1;
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
    int		i;
    int		j;
    char	**args;
    int		new_argc;

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
        i++;
    }
    if (argc == 2)
        free(args);
    return (0);
}