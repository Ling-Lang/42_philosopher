/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:12:50 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/21 12:21:20 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
static void *ft_exit(int flag);

int ft_is_input_valid(int argc, char *argv[])
{
	if(argc != 5)
		ft_exit(1);
	if(!argv)
		ft_exit(2);
}

static void *ft_exit(int flag)
{
	if(1 == flag)
	{
		printf(RED"ERROR:\n"WHT "usage:"YEL"./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n"WHT);
		exit(EXIT_FAILURE);
	}
	if(2 == flag)
	{
		printf(RED"ERROR:\n"WHT"Arguments cannot be NULL");
		exit(EXIT_FAILURE);
	}
}