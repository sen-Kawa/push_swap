/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/29 15:42:47 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_division_five(t_ps *push_swap)
{
	int	size;

	size = ft_lstsize(push_swap->stack_a);
	if (!list_a_sorted(push_swap, size))
	{
		if (size == 2)
			swap_nodes_a(push_swap->stack_a);
		else if (size == 3)
			sorting_three(push_swap);
		else if (size == 4)
			sorting_five(push_swap);
		else if (size == 5)
			sorting_five(push_swap);
	}
}

void	sorting_three(t_ps *push_swap)
{
	int	first;
	int	second;
	int	last;

	first = push_swap->stack_a->content;
	second = push_swap->stack_a->next->content;
	last = ft_lstlast(push_swap->stack_a)->content;
	if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
		return ;
	if (first > second && second > last)
	{
		swap_nodes_a(push_swap->stack_a);
		rotate_a(&push_swap->stack_a);
		rotate_a(&push_swap->stack_a);
	}
	else if (first < second && second > last && first < last)
	{
		reverse_rotate_a(&push_swap->stack_a);
		swap_nodes_a(push_swap->stack_a);
	}
	else if (first < second && second > last && first > last)
		reverse_rotate_a(&push_swap->stack_a);
	else if (last > first && last > second)
		swap_nodes_a(push_swap->stack_a);
	else if (first > second && second < last)
		rotate_a(&push_swap->stack_a);
}

void	sorting_five(t_ps *push_swap)
{
	int lstsize;

	lstsize = ft_lstsize(push_swap->stack_a);
	
	while (!list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
	{
		while (ft_lstsize(push_swap->stack_a) > 3)
		{
			if (push_swap->stack_a->content == find_min(push_swap->stack_a))
				push_a_b(push_swap);
			else
				rotate_a(&push_swap->stack_a);
	// 			printing_list_a(push_swap->stack_a);
	// printing_list_b(push_swap->stack_b);
		}
		sorting_three(push_swap);
		push_b_a(push_swap);
		push_b_a(push_swap);
	}
}

int find_min(t_list *stack)
{
	int		min;

	min = MAX_INT;
	while (stack != NULL)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}