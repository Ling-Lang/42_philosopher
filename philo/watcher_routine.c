/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:16:01 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:22:21 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_die(t_data *data)
{
	int	i;
	int	time_of_death;
	int	philo_is_dead;

	i = 0;
	i = -1;
	while (++i < data->num_of_philo)
	{
		pthread_mutex_lock(&data[i].meal_time_mutex);
		time_of_death = ft_get_time(*(data[i].start_time)) - data[i].last_meal;
		pthread_mutex_unlock(&data[i].meal_time_mutex);
		philo_is_dead = 0;
		pthread_mutex_lock(&data[i].num_of_meals_mutex);
		philo_is_dead = data[i].num_of_meals == -1;
		pthread_mutex_unlock(&data[i].num_of_meals_mutex);
		if (!philo_is_dead && time_of_death > (int)data[i].ttd)
		{
			pthread_mutex_lock(data[i].death_mutex);
			*(data[i].is_dead) = 1;
			pthread_mutex_unlock(data[i].death_mutex);
			ft_print("died", &data[i]);
			return (1);
		}
	}
	return (0);
}

static int	ft_stop(t_data *data)
{
	int	i;

	if (!data->limited_meals)
		return (0);
	while (++i < data->num_of_philo)
	{
		pthread_mutex_lock(&data[i].num_of_meals_mutex);
		if (data[i].num_of_meals != -1)
		{
			pthread_mutex_unlock(&data[i].num_of_meals_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data[i].num_of_meals_mutex);
	}
	return (1);
}

void	*watcher_routine(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	while (!ft_die(data) && !ft_stop(data))
		usleep(1000);
	return (NULL);
}
