/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/22 17:39:25 by kaheinz          ###   ########.fr       */
/*   Updated: 2022/06/15 12:50:57 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_ps *push_swap)
{
	int	half;
	int	median;

	median = (push_swap->min + push_swap->max) / 2;
	half = ft_lstsize(push_swap->stack_a) / 2;
	printing_list_a(push_swap->stack_a);
	if (ft_lstsize(push_swap->stack_a) <= 5)
		pivot_division_five(push_swap);
	else if (ft_lstsize(push_swap->stack_a) <= 100)
	{
		pivot_division_mid(push_swap, half, median);
		printing_list_a(push_swap->stack_a);
	printing_list_b(push_swap->stack_b);
	// ft_printf("%i", median);
		partial_sorting(push_swap, half, median);
	}
	printing_list_a(push_swap->stack_a);
	printing_list_b(push_swap->stack_b);
}

void	pivot_division_mid(t_ps *push_swap, int half, int median)
{
	if (ft_lstsize(push_swap->stack_a) == half)
		return ;
	if (push_swap->stack_a->content < median)
		push_a_b(push_swap);
	if (push_swap->stack_a->content > median)
	{
		rotate_a(&push_swap->stack_a);
		write(1, "ra\n", 3);
	}
	pivot_division_mid(push_swap, half, median);
}

void	partial_sorting(t_ps *push_swap, int half, int median)
{
	int counter;

	counter = 0;
	half = half / 2;
	median = median / 2;
	while(counter <= half)
	{
		if (push_swap->stack_b->content > median)
			push_b_a(push_swap);
		else if (push_swap->stack_b->content < median)
		{
			rotate_b(&push_swap->stack_b);
			write(1, "rb\n", 3);
		}
		counter++;
	}
	if (push_swap->stack_b)
		partial_sorting(push_swap, half, median);
	else if (!push_swap->stack_b || list_b_sorted(push_swap, ft_lstsize(push_swap->stack_b)))
		return ;
}



// if (ft_lstlast(push_swap->stack_a)->content < median)
	// 		{
	// 			reverse_rotate_a(&push_swap->stack_a);
	// 			write(1, "rra\n", 4);
	// 			push_a_b(push_swap);
	// 			if (push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
	// 			{
	// 					swap_nodes_b(push_swap->stack_b);
	// 					write(1, "sb\n", 3);
	// 			}
	// 		}

		// if (ft_lstsize(push_swap->stack_a) == half - 1)
		// 	break ;
	
		
	// while (ft_lstlast(push_swap->stack_a)->content != push_swap->max)
	// {
	// 	if (push_swap->stack_a->content < median)
	// 		push_a_b(push_swap);
	// 	if (push_swap->stack_a->content > push_swap->stack_a->next->content)
	// 	{
	// 		swap_nodes_a(push_swap->stack_a);
	// 		write(1, "sa\n", 3);
	// 	}
	// 	if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
	// 	{
	// 		rotate_a(&push_swap->stack_a);
	// 		write(1, "ra\n", 3);
	// 	}
	// 	else 
	// 	{
	// 		push_a_b(push_swap);
	// 	}
	// }
	// 	printing_list_a(push_swap->stack_a);
	// 	printing_list_b(push_swap->stack_b);
// void	check_combined(t_ps *push_swap)
// {
// 	if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 		ss(push_swap);
// 	if (ft_lstlast(push_swap->stack_b)->content > push_swap->stack_b->content && ft_lstlast(push_swap->stack_a)->content < push_swap->stack_a->content)
// 		rrr(push_swap);
// 	if (push_swap->stack_a->content  > ft_lstlast(push_swap->stack_a)->content && push_swap->stack_b->content  < ft_lstlast(push_swap->stack_a)->content)
// 		rrr(push_swap);
// }

// void	bigger_than_median(t_ps *push_swap)
// {
// 	if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
// 		{
// 			rotate_a(&push_swap->stack_a);
// 			write(1, "ra\n", 3);
// 		}
// 	else if (push_swap->stack_a->content > push_swap->stack_a->next->content)
// 		{
// 			rotate_a(&push_swap->stack_a);
// 			write(1, "ra\n", 3);
// 		}
// 	else 
// 		{
// 			swap_nodes_a(push_swap->stack_a);
// 			write(1, "sa\n", 3);
// 			sleep(1);
// 		}
// 	rotate_a(&push_swap->stack_a);
// 	write(1, "ra\n", 3);
// }

// void	smaller_than_median(t_ps *push_swap)
// {
	// if (push_swap->stack_b && push_swap->stack_b->next && ft_lstlast(push_swap->stack_b)->content < push_swap->stack_b->content)
	// {
	// 	reverse_rotate_b(&push_swap->stack_b);
	// 	write(1, "rrb\n", 4);
	// }
	// if (push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content > ft_lstlast(push_swap->stack_b)->content)
	// {
	// 	rotate_b(&push_swap->stack_b);
	// 	write(1, "rb\n", 3);
	// }
	// if (push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content > push_swap->stack_b->next->content)
	// {
	// 	swap_nodes_b(push_swap->stack_b);
	// 	write(1, "sb\n", 3);
	// }
	// push_a_b(push_swap);
			
		// if (ft_lstlast(push_swap->stack_a)->content < push_swap->stack_a->content)
	// 		{
	// 			reverse_rotate_a(&push_swap->stack_a);
	// 			write(1, "rra\n", 4);
	// 			push_a_b(push_swap);
	// 		}
	// if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
			
	// 		{
	// 			rotate_a(&push_swap->stack_a);
	// 			write(1, "ra\n", 3);
	// 		} 
	// else
// }

// void	pivot_division_gran(t_ps *push_swap)
// {
// 	int	len_a;
// 	int	len_b;
	
// 	len_a = ft_lstsize(push_swap->stack_a);
// 	len_b = ft_lstsize(push_swap->stack_b);
// 	//while (push_swap->stack_a && push_swap->stack_a->content != push_swap->pivot_a->content)
// 	while (!list_a_sorted(push_swap, len_a) || !list_b_sorted(push_swap, len_b))
// 	{
// 		if (push_swap->pivot_a < push_swap->stack_a->content && push_swap->stack_a->content < push_swap->stack_a->next->content)
// 		{					
// 			reverse_rotate_a(&push_swap->stack_a);
// 			write(1, "rra\n", 4);
// 			if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
// 				break ;
// 		}
// 		if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
// 		{
// 			rotate_a(&push_swap->stack_a);
// 			write(1, "ra\n", 3);
// 			if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
// 				break ;
// 		}
// 		if (push_swap->stack_a->content > push_swap->stack_a->next->content && !push_swap->stack_b)
// 			{
// 				swap_nodes_a(push_swap->stack_a);
// 				write(1, "sa\n", 3);
// 				if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
// 					break ;
// 			}
// 		if (push_swap->stack_a->content < push_swap->pivot_a)
// 		{
// 			if (push_swap->stack_a->content < push_swap->stack_a->next->content)
// 				{
// 					push_a_b(push_swap);
// 					push_swap->pivot_b = ft_lstlast(push_swap->stack_b);
// 				}
// 			if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_a->content < ft_lstlast(push_swap->stack_a)->content)
// 				{
// 					swap_nodes_a(push_swap->stack_a);
// 					write(1, "sa\n", 3);
// 				}
// 			if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
// 				{
// 					rotate_a(&push_swap->stack_a);
// 					write(1, "ra\n", 3);
// 				}
// 			// if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->pivot_b->content)
// 			// {
// 			// 	reverse_rotate_b(&push_swap->stack_b);
// 			// 	write(1, "rrb\n", 3);
// 			// }
// 		}
// 		if (push_swap->stack_a->content > push_swap->pivot_a)
// 		{
// 			if (push_swap->stack_a->content > ft_lstlast(push_swap->stack_a)->content)
// 			{
// 				rotate_a(&push_swap->stack_a);
// 				write(1, "ra\n", 3);
// 			}
// 			// if((push_swap->pivot_b) && push_swap->stack_b->content < push_swap->pivot_b->content)
// 			// 	rr(push_swap);
// 		}

// //		printf("PIVOT B %i\n", push_swap->pivot_b->content);
// 		if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 			ss(push_swap);
// 		else if (push_swap->stack_a->next && push_swap->stack_a->content > push_swap->stack_a->next->content)
// 		{
// 			swap_nodes_a(push_swap->stack_a);
// 			write(1, "sa\n", 3);
// 		}
// 		else if (push_swap->stack_b && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 		{
// 			swap_nodes_b(push_swap->stack_b);
// 			write(1, "sb\n", 3);
// 		}
// 		if (list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
// 			break ;
// 		else
// 			push_swap->pivot_a = ft_lstlast(push_swap->stack_a)->content;
// 		len_a = ft_lstsize(push_swap->stack_a);
// 		len_b = ft_lstsize(push_swap->stack_b);
// //	printing_list_a(push_swap->stack_a);
// //	printing_list_b(push_swap->stack_b);
// //	sleep(1);
// 	}

// 	len_a = ft_lstsize(push_swap->stack_a);
// 	len_b = ft_lstsize(push_swap->stack_b);
// 	if (list_a_sorted(push_swap, len_a) && list_b_sorted(push_swap, len_b) && push_swap->stack_a->content > push_swap->stack_b->content)
// 		while (push_swap->stack_b)
// 			push_b_a(push_swap);
// 	else
// 	{
// 		while (push_swap->stack_b)
// 		{
// 			if (push_swap->stack_b->next && push_swap->stack_b->content > push_swap->stack_b->next->content)
// 			{
// 				push_b_a(push_swap);
// 				if (push_swap->stack_a->content > push_swap->stack_a->next->content && push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 					ss(push_swap);
// 				else if (push_swap->stack_a->next && push_swap->stack_a->content > push_swap->stack_a->next->content)
// 				{
// 					swap_nodes_a(push_swap->stack_a);
// 					write(1, "sa\n", 3);
// 				}
// 				else if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 				{
// 					swap_nodes_b(push_swap->stack_b);
// 					write(1, "sb\n", 3);
// 				}
// 			}
// 			else if (push_swap->stack_b->next && push_swap->stack_b->content < push_swap->stack_b->next->content)
// 				swap_nodes_b(push_swap->stack_b);
// 			if (!list_a_sorted(push_swap, ft_lstsize(push_swap->stack_a)))
// 			{
// 				pivot_division(push_swap);
// 			}
// 			push_b_a(push_swap);
// 			if (push_swap->stack_a->next && push_swap->stack_a->content > push_swap->stack_a->next->content)
// 				{
// 					swap_nodes_a(push_swap->stack_a);
// 					write(1, "sa\n", 3);
// 				}
// 		}
// 	}
// }
