/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/05 15:54:25 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *push_swap)
{
	if (ft_lstsize(push_swap->stack_a) <= 5)
		division_five(push_swap);
	else if (ft_lstsize(push_swap->stack_a) > 5)
	{
		indexing(push_swap);
		sorting_plusfive(push_swap);
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

void	sorting_plusfive(t_ps *push_swap)
{
	printing_list_a(push_swap->stack_a);
}
