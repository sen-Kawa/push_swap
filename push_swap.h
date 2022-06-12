/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:12:08 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/12 16:10:20 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*pivot_a;
	t_list	*pivot_b;
}	t_ps;

//error checkers
int		checker_minmax(long int nbr);
int		numeric_checker(char *arg);
int		duplicates_checker(int argc, char **argv);

//handling list
t_list	*creating_list(t_list **stack_a, char **argv);
void	printing_list_a(t_list *stack_a);
void	printing_list_b(t_list *stack_b);

//rotating
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rr(t_ps *push_swap);

//reverse rotating
void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	rrr(t_ps *push_swap);

//swapping
void	swap_data(int *a, int *b);
void	swap_nodes_a(t_list *stack);
void	swap_nodes_b(t_list *stack);
void	ss(t_ps *push_swap);

//utilities
void	init_push_swap(t_ps *push_swap);
void	freeing_list(t_list *stack_a);

//pushing
void	push_a_b(t_ps *push_swap);
void	push_b_a(t_ps *push_swap);

//quicksort algorithm
void	pivot_division(t_ps *push_swap);
void	quicksort(t_ps *push_swap);

#endif
