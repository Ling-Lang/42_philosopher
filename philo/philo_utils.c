/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:56:54 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 13:41:02 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philo *philo)
{
    if(!philo->is_eating && get_time() > philo->limit)
    {
        ft_log(DYING, philo->limit, philo);
        pthread_mutex_lock(&philo->data->print_mutex);
        pthread_mutex_unlock(&philo->data->death_mutex);
        return (1);
    }
    return (0);
}
int yoink_forks(t_philo *philo)
{
    int i;
    size_t fork;

    i = 0;
    if(is_dead(philo))
        return (1);
    while(i < 2)
    {
        if(i == 0)
            fork = philo->lfork;
        else
            fork = philo->rfork;
        pthread_mutex_lock(&philo->data->fork_mutex[fork]);
        if(!philo->data->forks[fork])
        {
            ft_log(FORK, get_time(), philo);
            philo->data->forks[fork] = 1;
            i++;
        }
        pthread_mutex_unlock(&philo->data->fork_mutex[fork]);
    }
    return (0);
}
int free_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->fork_mutex[philo->lfork]);
    philo->data->forks[philo->lfork] = 0;
    pthread_mutex_unlock(&philo->data->fork_mutex[philo->lfork]);
    pthread_mutex_lock(&philo->data->fork_mutex[philo->rfork]);
    philo->data->forks[philo->rfork] = 0;
    pthread_mutex_unlock(&philo->data->fork_mutex[philo->rfork]);
    ft_log(SLEEPING, philo->last_meal + philo->data->time_to_eat, philo);
    ft_usleep(philo->data->time_to_sleep);
    if(is_dead(philo))
        return (1);
    ft_log(THINKING, philo->last_meal + philo->data->time_to_eat + philo->data->time_to_sleep, philo);
    return(0);
}
int eat(t_philo *philo)
{
    philo->is_eating = 1;
    philo->last_meal = get_time();
    ft_log(EATING, philo->last_meal, philo);
    ft_usleep(philo->data->time_to_eat);
    philo->limit = philo->last_meal + philo->data->time_to_die;
    philo->is_eating = 0;
    philo->already_eaten += 1;
    if(philo->data->ammount_of_food > 0 && philo->already_eaten >= philo->data->ammount_of_food)
    {
        pthread_mutex_lock(&philo->data->fork_mutex[philo->lfork]);
        philo->data->forks[philo->lfork] = 0;
        pthread_mutex_unlock(&philo->data->fork_mutex[philo->lfork]);
        pthread_mutex_lock(&philo->data->fork_mutex[philo->rfork]);
        philo->data->forks[philo->rfork] = 0;
        pthread_mutex_unlock(&philo->data->fork_mutex[philo->rfork]);
        philo->data->completed++;
        if(philo->data->completed >= philo->data->num_of_philo)
        {
            pthread_mutex_lock(&philo->data->print_mutex);
            pthread_mutex_unlock(&philo->data->death_mutex);
        }
        return (1);
    }
    return (0);
}