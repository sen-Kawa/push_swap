/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/12 21:36:40 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing_list(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a != NULL)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
}

void	init_push_swap(t_ps *push_swap)
{
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
}

void	quicksort(t_ps *push_swap)
{
	pivot_division(push_swap);
	printf("a %i\n", push_swap->stack_a->content);
	printf("b %i\n", push_swap->stack_b->content);
	printing_list_a(push_swap->stack_a);
	printing_list_b(push_swap->stack_b);
	if ((push_swap->stack_a->content > push_swap->stack_a->next->content) && (push_swap->stack_b->content < push_swap->stack_b->next->content))
	{
//		write(1, "he\n", 3);
		ss(push_swap);
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
	}
	else if ((push_swap->stack_a->content > push_swap->pivot_a->content) && (push_swap->stack_b->content < push_swap->pivot_b->content))
	{
//		write(1, "he\n", 3);
		rr(push_swap);
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
	}
}

void	pivot_division(t_ps *push_swap)
{
//	t_list	*pivot_a;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(push_swap->stack_a) / 2;
	ft_printf("size %i", size);
	push_swap->pivot_a = ft_lstlast(push_swap->stack_a);
	push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
	while (push_swap->stack_a->next != NULL && i <= size)
	{
		if (push_swap->stack_a->content < push_swap->pivot_a->content)
		{
			push_a_b(push_swap);
//			printing_list_a(push_swap->stack_a);
//			printing_list_b(push_swap->stack_b);
		}
/*		else if(push_swap->stack_a->content > push_swap->pivot_a->content 
			&& push_swap->stack_b->content < push_swap->pivot_b->content)
		{
			write(1, "test2\n", 5);
			rr(push_swap);
			push_swap->pivot_a = ft_lstlast(push_swap->stack_a);
//			push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
			ft_printf("Pivot a is %i\n", *push_swap->pivot_a);
		}*/
		else if(push_swap->stack_a->content > push_swap->pivot_a->content)
		{
			rotate_a(&push_swap->stack_a);
			push_swap->pivot_a = ft_lstlast(push_swap->stack_a);
			push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
	//		ft_printf("Pivot a is %i\n", *push_swap->pivot_a);
		}
		i++;
	}
//	printf("%i", push_swap->stack_a->content);
	push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
//	printing_list_a(push_swap->stack_a);
//	ft_printf("Pivot a is %i\n", *push_swap->pivot_a);
//	ft_printf("Pivot b is %i\n", *push_swap->pivot_b);
//	printing_list_b(push_swap->stack_b);
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
		if (numeric_checker(argv[i]) && checker_minmax(atol(argv[i])))
			i++;
	}
	if (duplicates_checker(argc, argv))
	{
		creating_list(&push_swap->stack_a, argv);
		ft_printf("List is:\n");
		printing_list_a(push_swap->stack_a);
		quicksort(push_swap);
/*		rotate_a(&push_swap->stack_a);
		ft_printf("Rotated list is:\n");
		printing_list_a(push_swap->stack_a);
		reverse_rotate_a(&push_swap->stack_a);
		ft_printf("Reverse rotated list is:\n");
		printing_list_a(push_swap->stack_a);
		swap_nodes_a(push_swap->stack_a);
		ft_printf("Swapped list is:\n");
		printing_list_a(push_swap->stack_a);
		push_a_b(push_swap);
		push_a_b(push_swap);
		ft_printf("Pushed 2 from a to b is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		rr(push_swap);
		ft_printf("RR is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		rrr(push_swap);
		ft_printf("RRR is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		ss(push_swap);
		ft_printf("Swapped both lists is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		rotate_b(&push_swap->stack_b);
		ft_printf("Rotated b list is:\n");
		printing_list_b(push_swap->stack_b);
		reverse_rotate_b(&push_swap->stack_b);
		ft_printf("Reverse rotated list is:\n");
		printing_list_b(push_swap->stack_b);
		swap_nodes_b(push_swap->stack_b);
		ft_printf("Swapped list is:\n");
		printing_list_b(push_swap->stack_b);
		push_b_a(push_swap);
		ft_printf("Pushed b to a is:\n");
		printing_list_a(push_swap->stack_a);
		printing_list_b(push_swap->stack_b);
		swap_nodes_b(push_swap->stack_b);
		ft_printf("Swapped list is:\n");
		printing_list_b(push_swap->stack_b);*/
	}
	freeing_list(push_swap->stack_a);
	free(push_swap);
	return (0);
}
