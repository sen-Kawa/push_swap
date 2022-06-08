/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/07 23:47:08 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;

	t_ps	*push_swap->stack_a;
	t_ps	*push_swap->stack_b;

	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
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
		printing_list(push_swap->stack_a);
//		rotate(&stack_a);
//		ft_printf("Rotated list is:\n");
//		printing_list(stack_a);
//		reverse_rotate(&stack_a);
//		ft_printf("Reverse rotated list is:\n");
//		printing_list(stack_a);
//		swap_nodes(stack_a);
//		ft_printf("Swapped list is:\n");
//		printing_list(stack_a);
	}		
	return (0);
}
