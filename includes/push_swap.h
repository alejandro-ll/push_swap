/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:45:09 by allera-m          #+#    #+#             */
/*   Updated: 2024/12/10 20:12:37 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Define the stack structure A & B
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

// Util functions
t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_front(t_list **stack, t_list *new);
void				ft_lstadd_back(t_list **stack, t_list *new);
void				printList(t_list *head);
int					ft_lstsize(t_list *head);

int					check_for_duplicates(int argc, char **argv);
int					check_for_non_numeric(int argc, char **argv);
int					has_duplicate(char **args, int new_argc, int num1, int i);
int					is_non_numeric(char *arg);

void				ft_error(char *msg);
void				ft_check_args(int argc, char **argv);
int					is_sorted(t_list *stack);
int					get_distance(t_list **stack, int index);
void				make_top(t_list **stack, int distance);
void				free_stack(t_list **stack);
void				ft_free(char **str);

// Algorithm utils
// void	radix_sort(t_list **stack_a, t_list **stack_b);
int					find_min_index(t_list *stack);
void				selection_sort(t_list **stack_a, t_list **stack_b);
void				simple_sort(t_list **stack_a, t_list **stack_b);
void				index_stack(t_list **stack);
void				sort_5(t_list **stack_a, t_list **stack_b);
void				sort_3_helper(t_list **stack_a, t_list *head,
						int min, int next_min);

// Instruction functions
int					swap(t_list **stack);
int					push(t_list **stack_to, t_list **stack_from);
int					rotate(t_list **stack);
int					reverseRotate(t_list **stack);

int					sa(t_list **stack_a);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_b, t_list **stack_a);
int					ra(t_list **stack_a);
int					rra(t_list **stack_a);

#endif
