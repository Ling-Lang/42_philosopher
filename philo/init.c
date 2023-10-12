/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:21:04 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:13:40 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_fill_data_2(t_data *data, int argc, char **argv, int i)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]) * 1000;
	data->tts = ft_atoi(argv[4]) * 1000;
	data->last_meal = 0;
	data->limited_meals = false;
	if (argc == 6)
	{
		data->limited_meals = true;
		data->num_of_meals = ft_atoi(argv[5]);
	}
	data->philo_id = i;
	data->state = THINKING;
	pthread_mutex_init(&data->fork_mutex, NULL);
	pthread_mutex_init(&data->meal_time_mutex, NULL);
	pthread_mutex_init(&data->num_of_meals_mutex, NULL);
}

int	ft_fill_data_1(int argc, char **argv, t_data *data, struct timeval *start)
{
	int				i;
	int				philo_num;
	int				*is_dead;
	pthread_mutex_t	*death_mutex;

	is_dead = malloc(sizeof(int));
	death_mutex = malloc(sizeof(pthread_mutex_t));
	if (!is_dead || !death_mutex)
		return (0);
	*is_dead = 0;
	philo_num = ft_atoi(argv[1]);
	gettimeofday(start, NULL);
	i = -1;
	while (++i < philo_num)
	{
		ft_fill_data_2(&data[i], argc, argv, i);
		data[i].start_time = start;
		data[i].is_dead = is_dead;
		data[i].death_mutex = death_mutex;
		if (i < philo_num - 1)
			(&data[i])->next = &data[i + 1];
		else
			(&data[i])->next = &data[0];
	}
	return (1);
}
