/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/05 15:13:46 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_array(t_ps *push_swap)
{
	int		size;
	int		*stack_array;
	int		i;
	t_list	*temp;

	temp = push_swap->stack_a;
	i = 0;
	size = ft_lstsize(push_swap->stack_a);
	stack_array = ft_calloc(size + 1, sizeof(int));
	if (!stack_array)
		return (0);
	while (i < size)
	{
		stack_array[i] = temp->content;
		temp = temp->next;
		i++;
	}
	bubblesorting(stack_array, size, push_swap);
	return (stack_array);
}

void	bubblesorting(int *stack_array, int size, t_ps *push_swap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_array[i] > stack_array[j])
				swap_data(&stack_array[i], &stack_array[j]);
			j++;
		}
		i++;
	}
	push_swap->min = stack_array[0];
	push_swap->med = stack_array[size / 2];
	push_swap->max = stack_array[size - 1];
}
