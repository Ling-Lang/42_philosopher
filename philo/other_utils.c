/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:49 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 13:45:09 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_log(int msg, size_t time, t_philo *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if(msg == EATING)
        printf("%zu %zu is eating\n", time, philo->num);
    else if(msg == SLEEPING)
        printf("%zu %zu is sleeping\n", time, philo->num);
    else if(msg == THINKING)
        printf("%zu %zu is thinking\n", time, philo->num);
    else if(msg == DYING)
        printf("%zu %zu died\n", time, philo->num);
    else if(msg == FORK)
        printf("%zu %zu has taken a fork\n", time, philo->num);
    // else if(msg == LAST_MEAL)
    //     printf("")
    pthread_mutex_unlock(&philo->data->print_mutex);
}

int ft_atoi(char *str, size_t *dst)
{
    int i;

    i = 0;
    if(str[i] == '\0')
        return (1);
    *dst = 0;
    while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        *dst = *dst * 10;
        *dst = *dst + str[i] - '0';
        i++;
    }
    if(str[i] != '\0')
        return (1);
    return (0);
}

void ft_clean(t_data *data)
{
    size_t i;
    
    i = 0;
    while(i < data->num_of_philo)
    {
        pthread_mutex_destroy(&data->fork_mutex[i]);
        i++;
    }
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->death_mutex);
    free(data->fork_mutex);
    free(data->philo);
    free(data->forks);
}
