/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/28 17:42:11 by kaheinz          ###   ########.fr       */
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
			sorting_four(push_swap);
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

void	sorting_four(t_ps *push_swap)
{
/*	int	first;
	int	second;
	int	last;*/
	int	count_pushedb;
	
	count_pushedb = 0;
	make_array(push_swap);
	ft_printf("min %i, med %i, max %i\n", push_swap->min, push_swap->med, push_swap->max);
	while (push_swap->stack_a->content <)
/*	while (ft_lstsize(push_swap->stack_a) > 2)
	{
		first = push_swap->stack_a->content;
		second = push_swap->stack_a->next->content;
		last = ft_lstlast(push_swap->stack_a)->content;
		if (first > second && first < last)
			swap_nodes_a(push_swap->stack_a);
		if (first < second && first < last)
		{
			push_a_b(push_swap);
			if (ft_lstsize(push_swap->stack_b) >= 2 && push_swap->stack_b->content < push_swap->stack_b->next->content)
				swap_nodes_b(push_swap->stack_b);
		}
	}*/
}

void	sorting_five(t_ps *push_swap)
{
	ft_printf("size of list in sortin five is %i\n", ft_lstsize(push_swap->stack_a));
}
