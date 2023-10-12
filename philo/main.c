/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:49:28 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:12:31 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(int n)
{
	char	*set;

	set = "0123456789";
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &set[n % 10], 1);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	pthread_t		*t_id;
	struct timeval	start;
	int				i;

	if (!ft_validate_input(argc, argv))
		return (1);
	t_id = malloc((ft_atoi(argv[1]) + 1) * sizeof(pthread_t));
	data = malloc(ft_atoi(argv[1]) * sizeof(t_data));
	if (!ft_fill_data_1(argc, argv, data, &start) || !data || !t_id)
		return (-1);
	pthread_mutex_init(data->death_mutex, NULL);
	pthread_create(&t_id[data->num_of_philo], NULL, watcher_routine, data);
	i = -1;
	while (++i <= data->num_of_philo / 2 && 2 * i < data->num_of_philo)
		pthread_create(&t_id[i * 2], NULL, philo_routine, &data[i * 2]);
	i = -1;
	usleep(250);
	while (++i < data->num_of_philo / 2)
		pthread_create(&t_id[i * 2 + 1], NULL, philo_routine, &data[i * 2 + 1]);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_join(t_id[i], NULL);
	pthread_join(t_id[data->num_of_philo], NULL);
	ft_clean(t_id, data);
}
