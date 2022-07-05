/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/07/05 14:24:33 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_a_sorted(t_ps *push_swap, int lenlst)
{
	t_list	*temp;
	int	i;

	i = 0;
	temp = push_swap->stack_a;
	while (temp && temp->next && temp->content < temp->next->content)
	{
		temp = temp->next;
		i++;
	}
	i++;
	if (i == lenlst)
		return (1);
	else
		return (0);
}


int	list_b_sorted(t_ps *push_swap, int lenlst)
{
	t_list	*temp;
	int	i;

	i = 0;
	temp = push_swap->stack_b;
	while (temp && temp->next && temp->content > temp->next->content)
	{
		temp = temp->next;
		i++;
	}
	i++;
	if (i == lenlst)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		lenlst;
	t_ps	*push_swap;

	push_swap = malloc(sizeof(t_ps));
	if (!push_swap)
		exit(EXIT_FAILURE);
	init_push_swap(push_swap);
	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (numeric_checker(argv[i]) && checker_minmax(ft_atoi(argv[i])))
			i++;
	}
	if (duplicates_checker(argc, argv))
	{
		creating_list(push_swap, argv);
		lenlst = ft_lstsize(push_swap->stack_a);
		push_swap->pivot_a = ft_lstlast(push_swap->stack_a)->content;
		// ft_printf("List is:\n");
		// printing_list_a(push_swap->stack_a);
		if (!list_a_sorted(push_swap, lenlst))
			sort(push_swap);
	}
	freeing_list(push_swap->stack_a);
	free(push_swap);
	return (0);
}
