/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/07 22:35:19 by kaheinz          ###   ########.fr       */
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
		printing_list(stack_a);
		rotate(&stack_a);
		printing_list(stack_a);
	}		
	return (0);
}
