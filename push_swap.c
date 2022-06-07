/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/07 23:12:32 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
//	t_list	*stack_b;

	stack_a = NULL;
//	stack_b = NULL;
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
		creating_list(&stack_a, argv);
		ft_printf("List is:\n");
		printing_list(stack_a);
//		rotate(&stack_a);
//		ft_printf("Rotated list is:\n");
//		printing_list(stack_a);
		reverse_rotate(&stack_a);
		ft_printf("Reverse rotated list is:\n");
		printing_list(stack_a);
	}		
	return (0);
}
