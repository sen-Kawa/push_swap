/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/08 17:33:08 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printing_list(t_ps *push_swap)
// {
// 	while (push_swap->stack_a || push_swap->stack_b)
// 	{
// 		if (!push_swap->stack_b)
// 		{
// 			while (push_swap->stack_a)
// 			{
// 			ft_printf("Node: %i\n", push_swap->stack_a->content);
// 			push_swap->stack_a = push_swap->stack_a->next;
// 			}
// 		}
// 		if (push_swap->stack_b)
// 		{
// 		ft_printf("Node: %i     %i\n", push_swap->stack_a->content, push_swap->stack_b->content);
// 		push_swap->stack_a = push_swap->stack_a->next;
// 		push_swap->stack_b = push_swap->stack_b->next;
// 		}
// 	}
	
// 	ft_printf("_______________\n");
// 	ft_printf("   A        B\n");
// 			ft_printf("lst size %i", ft_lstsize(push_swap->stack_a));

// }

void	printing_list_a(t_list *stack_a)
{
	while (stack_a)
	{
		ft_printf("Node: %i\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("___\n");
	ft_printf(" A \n");
}

void	printing_list_b(t_list *stack_b)
{
	while (stack_b)
	{
		ft_printf("Node: %i\n", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("___\n");
	ft_printf(" B \n");
}

t_list	*creating_list(t_ps *push_swap, char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	push_swap->min = ft_atoi(argv[i]);
	push_swap->max = ft_atoi(argv[i]);
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&push_swap->stack_a, new);
		if (new->content < push_swap->min)
				push_swap->min = new->content;
		else if (new->content > push_swap->max)
			push_swap->max = new->content;
		i++;
	}
	return (push_swap->stack_a);
}