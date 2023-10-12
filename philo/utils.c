/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:09:47 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:20:39 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == '\f' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + *str - '0';
		str++;
		if (res > INT_MAX)
			break ;
	}
	if (res <= INT_MAX)
		return (sign * res);
	return (0);
}

unsigned int	ft_get_time(struct timeval start_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - start_time.tv_sec) * 1000 + (now.tv_usec
			- start_time.tv_usec) / 1000);
}

void	ft_print(char *str, t_data *data)
{
	int	is_dead;

	pthread_mutex_lock(data->death_mutex);
	is_dead = *data->is_dead;
	pthread_mutex_unlock(data->death_mutex);
	if (!is_dead || str[0] == 'd')
		printf("%u ms %zu %s\n", ft_get_time(*data->start_time), data->philo_id
			+ 1, str);
}

void	ft_clean(pthread_t *t_id, t_data *data)
{
	int	i;
	int	philo_num;

	i = -1;
	philo_num = data->num_of_philo;
	pthread_mutex_destroy(data[0].death_mutex);
	free(data[0].death_mutex);
	free(data->is_dead);
	while (++i < philo_num)
	{
		pthread_mutex_destroy(&data[i].fork_mutex);
		pthread_mutex_destroy(&data[i].meal_time_mutex);
		pthread_mutex_destroy(&data[i].num_of_meals_mutex);
	}
	free(t_id);
	free(data);
}

void	ft_exit(int flag)
{
	if (1 == flag)
	{
		printf(RED "ERROR:\n" WHT "usage:" YEL "./philo"
			"<number_of_philosophers> <time_to_die>"
			"<time_to_eat> <time_to_sleep>"
			"[<number_of_times_each_philosopher_must_eat>]\n" WHT);
		exit(EXIT_FAILURE);
	}
	else if (2 == flag)
	{
		printf(RED "ERROR:\n" WHT "Arguments cannot be NULL or not numbers");
		exit(EXIT_FAILURE);
	}
}
