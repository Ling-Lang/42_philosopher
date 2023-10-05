/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:54:29 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 12:48:09 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_init(t_data *data)
{
    size_t i;
    
    i = 0;
    data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
    data->forks = malloc(sizeof(int) * data->num_of_philo);
    if(!data->philo || !data->forks)
        ft_exit(4);
    while(i < data->num_of_philo)
    {
        data->forks[i] = 0;
        data->philo[i].num = i;
        data->philo[i].lfork = i;
        data->philo[i].rfork = (i + 1) % data->num_of_philo;
        data->philo[i].already_eaten = 0;
        data->philo[i].is_eating = 0;
        data->philo[i].data = data;
        i++;
    }
}

void ft_init_mutex(t_data *data)
{
    size_t i;
    
    i = 0;
    data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
    if(!data->fork_mutex)
        ft_exit(4);
    while(i < data->num_of_philo)
    {
        pthread_mutex_init(&data->fork_mutex[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->death_mutex, NULL);
}
