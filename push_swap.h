/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:12:08 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/28 16:46:26 by kaheinz          ###   ########.fr       */
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
	int	pivot_a;
	int	min;
	int	med;
	int	max;
	t_list	*pivot_b;
}	t_ps;

//error checkers
int		checker_minmax(long int nbr);
int		numeric_checker(char *arg);
int		duplicates_checker(int argc, char **argv);

//handling list
t_list	*creating_list(t_ps *push_swap, char **argv);
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

//handling 5
void	pivot_division_five(t_ps *push_swap);
void	sorting_three(t_ps *push_swap);
void	sorting_five(t_ps *push_swap);
int find_min(t_list *stack);

//array
void	make_array(t_ps *push_swap);
void	bubblesorting(int *stack_array, int size, t_ps *push_swap);

//quicksort algorithm
void	pivot_division_mid(t_ps *push_swap, int half, int median);
void	bigger_than_median(t_ps *push_swap);
void	smaller_than_median(t_ps *push_swap);

void	partial_sorting(t_ps *push_swap, int half, int median);

//void	pivot_division_gran(t_ps *push_swap);
void	quicksort(t_ps *push_swap);
int	list_a_sorted(t_ps *push_swap, int lenlst);
int	list_b_sorted(t_ps *push_swap, int lenlst);

#endif
