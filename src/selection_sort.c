/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:53:12 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/11 13:00:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static int get_max_bits(t_list *stack) {
    int max = stack->index;
    int max_bits = 0;

    while (stack) {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort(t_list **stack_a, t_list **stack_b) {
    int size = ft_lstsize(*stack_a);
    int max_bits = get_max_bits(*stack_a);
    int i = 0;

    while (i < max_bits) {
        int j = 0;

        // Dividir pila A entre los dos buckets de manera eficiente
        while (j < size) {
            if ((((*stack_a)->index >> i) & 1) == 1) {
                ra(stack_a);
            } else {
                pb(stack_a, stack_b);
            }
            j++;
        }

        // Reintegrar los elementos de pila B a pila A
        int b_size = ft_lstsize(*stack_b);
        while (b_size > 0) {
            pa(stack_a, stack_b);
            b_size--;
        }

        i++;
    }
}
*/

// Función optimizada para obtener el índice máximo de la pila

// Función optimizada para obtener el índice máximo de la pila

#include "../includes/push_swap.h"

static int get_max_index(t_list *stack) {
    int max_index = stack->index;
    while (stack) {
        if (stack->index > max_index)
            max_index = stack->index;
        stack = stack->next;
    }
    return max_index;
}

static int get_position(t_list *stack, int target_index) {
    int position = 0;
    while (stack) {
        if (stack->index == target_index)
            break;
        position++;
        stack = stack->next;
    }
    return position;
}

static void push_to_b_in_chunks(t_list **stack_a, t_list **stack_b, int chunk_start, int chunk_end) {
    int pushed = 0;
    int total_elements = chunk_end - chunk_start + 1;
    int current_index;

    while (pushed < total_elements && ft_lstsize(*stack_a) > 0) {
        current_index = (*stack_a)->index;
        if (current_index >= chunk_start && current_index <= chunk_end) {
            pb(stack_a, stack_b);
            pushed++;
        } else {
            ra(stack_a);
        }
    }
}

static void insert_back_to_a(t_list **stack_a, t_list **stack_b) {
    int max_index;
    int position;
    int size;

    while (ft_lstsize(*stack_b) > 0) {
        max_index = get_max_index(*stack_b);
        position = get_position(*stack_b, max_index);
        size = ft_lstsize(*stack_b);

        if (position <= size / 2) {
            while ((*stack_b)->index != max_index) {
                if ((*stack_a)->index != get_max_index(*stack_a) + 1) {
                    rr(stack_a, stack_b);
                } else {
                    rb(stack_b);
                }
            }
        } else {
            while ((*stack_b)->index != max_index) {
                if ((*stack_a)->index != get_max_index(*stack_a) + 1) {
                    rrr(stack_a, stack_b);
                } else {
                    rrb(stack_b);
                }
            }
        }
        pa(stack_a, stack_b);
    }
}

void chunk_sort(t_list **stack_a, t_list **stack_b) {
    int total_size = ft_lstsize(*stack_a);
    int chunk_count = 5; // Dividimos en 5 chunks para 100 elementos
    int chunk_size = (total_size + chunk_count - 1) / chunk_count;
    int i = 0;

    while (i < chunk_count) {
        int chunk_start = i * chunk_size;
        int next_chunk_end = (i + 1) * chunk_size - 1;
        int chunk_end = (next_chunk_end < total_size) ? next_chunk_end : total_size - 1;

        push_to_b_in_chunks(stack_a, stack_b, chunk_start, chunk_end);
        i++;
    }

    insert_back_to_a(stack_a, stack_b);
}