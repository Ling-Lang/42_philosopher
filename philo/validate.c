/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:12:50 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 12:45:12 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
void ft_exit(int flag);

void ft_is_input_valid(int argc, char *argv[], t_data *data)
{
	if(argc < 5 || argc > 6)
		ft_exit(1);
	if(ft_atoi(argv[1], &data->num_of_philo) || data->num_of_philo == 0|| ft_atoi(argv[2], &data->time_to_die) || data->time_to_die == 0 || ft_atoi(argv[3], &data->time_to_eat) || data->time_to_eat == 0 || ft_atoi(argv[4], &data->time_to_sleep) || data->time_to_sleep == 0)
		ft_exit(3);
	if(argc == 6 && (ft_atoi(argv[5], &data->ammount_of_food) || data->ammount_of_food == 0))
		ft_exit(1);
	else if(argc == 5)
		data->ammount_of_food = -1;
	if(!argv)
		ft_exit(2);
		data->completed = 0;
}

void ft_exit(int flag)
{
	if(1 == flag)
	{
		printf(RED"ERROR:\n"WHT "usage:"YEL"./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\n"WHT);
		exit(EXIT_FAILURE);
	}
	else if(2 == flag)
	{
		printf(RED"ERROR:\n"WHT"Arguments cannot be NULL");
		exit(EXIT_FAILURE);
	}
	else if(3 == flag)
	{
		printf(RED"ERROR:\n"WHT "usage:"YEL"./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>\n"WHT);
		exit(EXIT_FAILURE);
	}
	else if(4 == flag)
	{
		printf(RED"Malloc Error\n"WHT);
		exit(EXIT_FAILURE);
	}
	else if(5 == flag)
	{
		printf(RED"Thread Error\n"WHT);
		exit(EXIT_FAILURE);
	}
}