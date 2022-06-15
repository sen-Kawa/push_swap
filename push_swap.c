/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/15 13:47:00 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
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

void	quicksort(t_ps *push_swap)
{
	// printing_list_a(push_swap->stack_a);
	// printing_list_b(push_swap->stack_b);
	pivot_division(push_swap);
	printing_list_a(push_swap->stack_a);
	printing_list_b(push_swap->stack_b);
}

void	pivot_division(t_ps *push_swap)
{
	int	len_a;
	int	len_b;
	
	len_a = ft_lstsize(push_swap->stack_a);
	len_b = ft_lstsize(push_swap->stack_b);
	//while (push_swap->stack_a && push_swap->stack_a->content != push_swap->pivot_a->content)
	while (!list_a_sorted(push_swap, len_a) || !list_b_sorted(push_swap, len_b))
	{
		if (push_swap->pivot_a < push_swap->stack_a->content && push_swap->stack_a->content < push_swap->stack_a->next->content)
		{					
			reverse_rotate_a(&push_swap->stack_a);
			write(1, "rra\n", 4);
			if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
				break ;
		}
		if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
		{
			rotate_a(&push_swap->stack_a);
			write(1, "ra\n", 3);
			if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
				break ;
		}
		if (push_swap->stack_a->content > push_swap->stack_a->next->content)
			{
				swap_nodes_a(push_swap->stack_a);
				write(1, "sa\n", 3);
				if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
					break ;
			}
		if (push_swap->stack_a->content < push_swap->pivot_a)
		{
			if (push_swap->stack_a->content < push_swap->stack_a->next->content)
				{
					push_a_b(push_swap);
					push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
				}
			if (push_swap->stack_a->content > push_swap->stack_a->next->content)
				{
					swap_nodes_a(push_swap->stack_a);
					write(1, "sa\n", 3);
				}
			// if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->pivot_b->content)
			// {
			// 	reverse_rotate_b(&push_swap->stack_b);
			// 	write(1, "rrb\n", 3);
			// }
		}
		if (push_swap->stack_a->content > push_swap->pivot_a)
		{
			if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
			{
				rotate_a(&push_swap->stack_a);
				write(1, "ra\n", 3);
			}
			// if((push_swap->pivot_b) && push_swap->stack_b->content < push_swap->pivot_b->content)
			// 	rr(push_swap);
		}

//		printf("PIVOT B %i\n", push_swap->pivot_b->content);
		if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
			ss(push_swap);
		else if (push_swap->stack_a->next && push_swap->stack_a->content > push_swap->stack_a->next->content)
		{
			swap_nodes_a(push_swap->stack_a);
			write(1, "sa\n", 3);
		}
		else if (push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
		{
			swap_nodes_b(push_swap->stack_b);
			write(1, "sb\n", 3);
		}
		if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
			break ;
		else
			push_swap->pivot_a = ft_lstlast(push_swap->stack_a)->content;
		len_a = ft_lstsize(push_swap->stack_a);
		len_b = ft_lstsize(push_swap->stack_b);
//	printing_list_a(push_swap->stack_a);
//	printing_list_b(push_swap->stack_b);
//	sleep(1);
	}

	len_a = ft_lstsize(push_swap->stack_a);
	len_b = ft_lstsize(push_swap->stack_b);
	if (list_a_sorted(push_swap, len_a) && list_b_sorted(push_swap, len_b))
		while (push_swap->stack_b)
			push_b_a(push_swap);
	else
	{
		while (push_swap->stack_b)
		{
			if (push_swap->stack_b->next && push_swap->stack_b->content > push_swap->stack_b->next->content)
			{
				push_b_a(push_swap);
				if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
					ss(push_swap);
				else if (push_swap->stack_a->next && push_swap->stack_a->content > push_swap->stack_a->next->content)
				{
					swap_nodes_a(push_swap->stack_a);
					write(1, "sa\n", 3);
				}
				else if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
				{
					swap_nodes_b(push_swap->stack_b);
					write(1, "sb\n", 3);
				}
			}
			else if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
				swap_nodes_b(push_swap->stack_b);
			if (!list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
			{
				//write(1, "here", 4);
				pivot_division(push_swap);
			}
			push_b_a(push_swap);
		}
	}
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
		if (numeric_checker(argv[i]) && checker_minmax(atol(argv[i])))
			i++;
	}
	if (duplicates_checker(argc, argv))
	{
		creating_list(&push_swap->stack_a, argv);
		lenlst = ft_lstsize(push_swap->stack_a);
		push_swap->pivot_a = ft_lstlast(push_swap->stack_a)->content;
		// ft_printf("List is:\n");
		// printing_list_a(push_swap->stack_a);
		if (!list_a_sorted(push_swap, lenlst))
			quicksort(push_swap);
//			write(1, "not sorted", 9);
//		else
//			write(1, "sorted", 6);
//			return (0);
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
