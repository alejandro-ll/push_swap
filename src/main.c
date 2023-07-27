#include "../includes/push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
    t_list  *new;
    char    **args;
    int     i;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
	else
    {
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
        printf("Se creó un nuevo nodo con el valor: %d\n", new->value);
		i++;
	}
    index_stack(stack);
    printf("Tamaño de la pila: %d\n", ft_lstsize(*stack));
	//if (argc == 2)
	//	ft_free(args);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
		radix_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;

    if (argc < 2)
        return (-1);
    /*if (check_for_duplicates(argc, argv))
        return (-1);*/
    stack_a = NULL;
    stack_b = NULL;
    init_stack(&stack_a, argc, argv);
    if (is_sorted(stack_a))
	{
        //printf("LISTA YA ORDENADA! BIEN QUE BIEN\n");
		free_stack(&stack_a);
		return (0);
	}
    printList(stack_a);
    sort_stack(&stack_a, &stack_b);
    printList(stack_a);
}
