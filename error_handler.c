/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/13 17:24:54 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if ((ft_atoi(argv[i]) == ft_atoi(argv[j])))
			{
				write(2, "Error\n", 6);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checker_minmax(long int nbr)
{
	if (nbr > MAX_INT)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (nbr < MIN_INT)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}

int	numeric_checker(char *arg)
{
	int	c;

	c = 0;
	while (arg[c])
	{
		if (arg[c] == '-' || arg[c] == '+')
			c++;
		if (arg[c] > '9' || arg[c] < '0')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			c++;
	}
	return (1);
}
