/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:28:18 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/08 17:39:14 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_b(t_ps *push_swap)
{
	t_list	*temp;

	if (push_swap->stack_a == NULL)
		return ;
	temp = push_swap->stack_a;
	push_swap->stack_a = push_swap->stack_a->next;
	ft_lstadd_front(&push_swap->stack_b, temp);
}

void	push_b_a(t_ps *push_swap)
{
	t_list	*temp;

	if (push_swap->stack_b == NULL)
		return ;
	temp = push_swap->stack_b;
	push_swap->stack_b = push_swap->stack_b->next;
	ft_lstadd_front(&push_swap->stack_a, temp);
}
