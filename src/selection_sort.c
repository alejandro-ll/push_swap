/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:53:12 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/12 11:37:50 by user             ###   ########.fr       */
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


void insert_back_to_a(t_list **stack_a, t_list **stack_b) {
    while (*stack_b) {
        int max_index = get_max_index(*stack_b);
        int position = get_position(*stack_b, max_index);
        int size = ft_lstsize(*stack_b);

        if (position <= size / 2) {
            while ((*stack_b)->index != max_index) rb(stack_b);
        } else {
            while ((*stack_b)->index != max_index) rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

void chunk_sort(t_list **stack_a, t_list **stack_b, int chunk_count) {
    int total_size = ft_lstsize(*stack_a);
    int chunk_size = (total_size + chunk_count - 1) / chunk_count;

    for (int i = 0; i < chunk_count; i++) {
        int chunk_start = i * chunk_size;
        int chunk_end = (i + 1) * chunk_size - 1;
        if (chunk_end >= total_size) chunk_end = total_size - 1;

        int moved = 0; // Control para verificar si se movió un elemento
        t_list *temp = *stack_a;
        while (temp && moved < chunk_size) {
            if (temp->index >= chunk_start && temp->index <= chunk_end) {
                pb(stack_a, stack_b);
                moved++;
                temp = *stack_a;
            } else {
                ra(stack_a);
                temp = *stack_a;
            }
        }
    }
}
