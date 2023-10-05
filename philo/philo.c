/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:46:58 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 13:43:22 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *routine(void *void_philo);
int ft_begin(t_data *data)
{
    size_t      i;
    pthread_t   t_id;
    
    i = 0;
    pthread_mutex_lock(&data->death_mutex);
    while(i < data->num_of_philo)
    {
        if(pthread_create(&t_id, NULL, &routine, (void *)&data->philo[i]))
            return (1);
        pthread_detach(t_id);
        if(data->num_of_philo % 2)
            ft_usleep(250);
        i++;
    }
    return (0);
}

void *routine(void *void_philo)
{
    t_philo *philo;
    
    philo = (t_philo *)void_philo;
    philo->last_meal = get_time();
    philo->limit = philo->last_meal + philo->data->time_to_die;
    while(1)
    {
        if(yoink_forks(philo) || eat(philo) || free_forks(philo))
            break;
    }
    return NULL;
}