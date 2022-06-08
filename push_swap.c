/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/08 17:38:08 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_ps *push_swap)
{
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
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
		if (numeric_checker(argv[i]) && checker(atol(argv[i])))
			i++;
	}
	if (duplicates_checker(argc, argv))
	{
		creating_list(&push_swap->stack_a, argv);
		ft_printf("List is:\n");
		printing_list_a(push_swap->stack_a);
		rotate(&push_swap->stack_a);
		ft_printf("Rotated list is:\n");
		printing_list_a(push_swap->stack_a);
		reverse_rotate(&push_swap->stack_a);
		ft_printf("Reverse rotated list is:\n");
		printing_list_a(push_swap->stack_a);
		swap_nodes(push_swap->stack_a);
		ft_printf("Swapped list is:\n");
		printing_list_a(push_swap->stack_a);
		push_a_b(push_swap);
		ft_printf("Pushed a to b is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		push_b_a(push_swap);
		ft_printf("Pushed b to a is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
	}		
	free(push_swap);
	return (0);
}
