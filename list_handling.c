/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/28 16:39:16 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&push_swap->stack_a, new);
		i++;
	}
	return (push_swap->stack_a);
}
