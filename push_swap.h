/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:12:08 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/08 17:52:35 by kaheinz          ###   ########.fr       */
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
}	t_ps;

int		checker(long int nbr);
int		numeric_checker(char *arg);
int		duplicates_checker(int argc, char **argv);
t_list	*creating_list(t_list **stack_a, char **argv);
void	printing_list_a(t_list *stack_a);
void	printing_list_b(t_list *stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	swap_data(int *a, int *b);
void	swap_nodes(t_list *stack);
void	init_push_swap(t_ps *push_swap);
void	push_a_b(t_ps *push_swap);
void	push_b_a(t_ps *push_swap);
void	freeing_list(t_list *stack_a);

#endif
