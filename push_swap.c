/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:33:24 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/06 15:56:06 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(long int nbr)
{
	if (nbr > MAX_INT)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (nbr < MIN_INT)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Your integer is: %i", nbr);
		return(0);
	}

}


int	numeric_checker(char *arg)
{
	int	c;
//	int	sign;

	c = 0;
//	sign = 1;
	while (arg[c])
	{
		if (arg[c] > '9' || arg[c] < '0')
		//	printf("Iteration %c\n", arg[c]);
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		else
//			printf("Numeric value");
			c++;
	}
//	printf("all numerics");
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
//	long int	nbr;

	i = 1;
	if (argc == 1)
		return(0);
	while(argv[i])
	{
	//	nbr = atoi(argv[1]);
	//	checker(atol(argv[i]));	
		if (numeric_checker(argv[i]))
			checker(atol(argv[i]));	
//		printf("Iteration %s\n", argv[i]);
		i++;
	}
	return (0);
}
