/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/14 22:23:05 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_b(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_ps *push_swap)
{
	if (push_swap->stack_a == NULL || push_swap->stack_a->next == NULL
		|| push_swap->stack_b == NULL || push_swap->stack_b->next == NULL)
		return ;
	else
	{
		rotate_a(&push_swap->stack_a);
		rotate_b(&push_swap->stack_b);
		ft_printf("rr\n");
	}
}
