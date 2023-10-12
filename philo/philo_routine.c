/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:54:28 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:14:59 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_should_die(t_data *data)
{
	pthread_mutex_lock(data->death_mutex);
	if (*data->is_dead)
	{
		pthread_mutex_unlock(data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->death_mutex);
	return (0);
}

static int	ft_last_meal(t_data *data, int i)
{
	if (data->limited_meals)
	{
		pthread_mutex_lock(&data->num_of_meals_mutex);
		if (i == data->num_of_meals - 1)
		{
			data->num_of_meals = -1;
			pthread_mutex_unlock(&data->num_of_meals_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->num_of_meals_mutex);
	}
	return (0);
}

static void	ft_think(t_data *data)
{
	data->state = THINKING;
	ft_print("is thinking", data);
}

static void	ft_eat(t_data *data)
{
	pthread_mutex_lock(&data->fork_mutex);
	ft_print("has taken a fork", data);
	if (data->num_of_philo != 1)
		pthread_mutex_lock(&data->next->fork_mutex);
	else
	{
		pthread_mutex_unlock(&data->fork_mutex);
		while (!ft_should_die(data))
			;
		return ;
	}
	ft_print("has taken a fork", data);
	data->state = EATING;
	pthread_mutex_lock(&data->meal_time_mutex);
	data->last_meal = ft_get_time(*(data->start_time));
	pthread_mutex_unlock(&data->meal_time_mutex);
	ft_print("is eating", data);
	usleep(data->tte);
	pthread_mutex_unlock(&data->next->fork_mutex);
	pthread_mutex_unlock(&data->fork_mutex);
}

void	*philo_routine(void *v_data)
{
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *)v_data;
	if (ft_last_meal(data, i))
		return (NULL);
	while (++i != -1)
	{
		if (i != 0)
			ft_think(data);
		if (ft_should_die(data))
			break ;
		ft_eat(data);
		if (ft_last_meal(data, i))
			break ;
		if (ft_should_die(data))
			break ;
		data->state = SLEEPING;
		ft_print("is sleeping", data);
		usleep(data->tts);
		if (ft_should_die(data))
			break ;
	}
	return (NULL);
}
