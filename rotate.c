/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/07 23:28:08 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	//if linked list is empty oe it contains only one node, return
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack; //initialize first and last pointers
	last = *stack;
	while (last->next != NULL) //this loop makes last contains addres of last node
		last = last->next;
	*stack = first->next; //change head pointer to point to 2nd node
	first->next = NULL; //set the next of first as null
	last->next = first; //set the next of last as first
}

void	reverse_rotate(t_list **stack)
{
	t_list *secLast;
	t_list *last;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	secLast = NULL;
	last = *stack;
	while (last->next != NULL) //after this loop secLast contains address of second last node and last contains address of last node 
	{
		secLast = last;
		last = last->next;
	}
	secLast->next = NULL; //set the next of second last as NULL
	last->next = *stack; //set next of last as head of node
	*stack = last;
}
