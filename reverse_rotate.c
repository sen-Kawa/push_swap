/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/23 00:03:26 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack)
{
	t_list	*sec_last;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	sec_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack)
{
	t_list	*sec_last;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	sec_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_ps *push_swap)
{
	if (push_swap->stack_a == NULL || push_swap->stack_a->next == NULL
		|| push_swap->stack_b == NULL || push_swap->stack_b->next == NULL)
		return ;
	else
	{
		reverse_rotate_a(&push_swap->stack_a);
		reverse_rotate_b(&push_swap->stack_b);
		ft_printf("rrr\n");
	}
}
