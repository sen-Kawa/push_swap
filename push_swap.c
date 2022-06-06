/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/06 18:48:07 by kaheinz          ###   ########.fr       */
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
			if ((atoi(argv[i]) == atoi(argv[j])))
			{
				printf("Duplicate found!\n");
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checker(long int nbr)
{
	if (nbr > MAX_INT)
	{
		printf("Error max int\n");
		exit(EXIT_FAILURE);
	}
	else if (nbr < MIN_INT)
	{
		printf("Error min int\n");
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
			printf("Error non numeric\n");
			exit(EXIT_FAILURE);
		}
		else
			c++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		if (numeric_checker(argv[i]) && checker(atol(argv[i])))
			i++;
	}
	if (duplicates_checker(argc, argv))
		printf("numeric, min/max pass, no dups");
	return (0);
}
