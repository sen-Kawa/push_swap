/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/05 16:59:33 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *push_swap)
{
	int		size;

	size = ft_lstsize(push_swap->stack_a);
	if (size <= 5)
		division_five(push_swap);
	else if (size > 5)
	{
		indexing(push_swap);
		sorting_plusfive(push_swap, size);
	}
}

void	indexing(t_ps *push_swap)
{
	t_list	*temp;
	int		*array;
	int		max;
	int		i;

	temp = push_swap->stack_a;
	array = make_array(push_swap);
	max = ft_lstsize(push_swap->stack_a);
	while (temp)
	{
		i = 0;
		while (i < max)
		{
			if (temp->content == array[i])
				temp->index = i;
			i++;
		}
		temp = temp->next;
	}
	free(array);
}

void	sorting_plusfive(t_ps *push_swap, int size)
{
	int		max_bits;
	int		i;
	int		m;

	max_bits = 0;
	i = 0;
	while ((push_swap->max >> max_bits) != 0)
		++max_bits;
	while (i < max_bits
		&& !list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
	{
		m = 0;
		while (m < size)
		{
			if (((push_swap->stack_a->index >> i) & 1) == 1)
				rotate_a(&push_swap->stack_a);
			else
				push_a_b(push_swap);
			m++;
		}
		while (push_swap->stack_b != NULL)
			push_b_a(push_swap);
		i++;
	}
}
