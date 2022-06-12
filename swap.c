/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:28:18 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/12 17:34:58 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_data(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_nodes_a(t_list *stack)
{
	t_list	*temp;

	if (ft_lstsize(stack) >= 2)
	{
		temp = stack;
		swap_data(&temp->content, &temp->next->content);
		ft_printf("sa\n");
	}
	else
		return ;
}

void	swap_nodes_b(t_list *stack)
{
	t_list	*temp;

	if (ft_lstsize(stack) >= 2)
	{
		temp = stack;
		swap_data(&temp->content, &temp->next->content);
		ft_printf("sb\n");
	}
	else
		return ;
}

void	ss(t_ps *push_swap)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(push_swap->stack_a);
	len_b = ft_lstsize(push_swap->stack_b);
	if ((len_a >= 2) && (len_b >= 2))
	{
		swap_nodes_a(push_swap->stack_a);
		swap_nodes_b(push_swap->stack_b);
		ft_printf("ss\n");
	}	
	else
		return ;
}
