/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:12:08 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/07 23:39:08 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

int		checker(long int nbr);
int		numeric_checker(char *arg);
int		duplicates_checker(int argc, char **argv);
t_list	*creating_list(t_list **stack_a, char **argv);
void	printing_list(t_list *stack_a);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	swap_data(int *a, int *b);
void	swap_nodes(t_list *stack);

#endif
