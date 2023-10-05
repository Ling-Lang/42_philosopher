/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:49 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 11:41:58 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_log(int msg, int philo, t_data *data)
{
    pthread_mutex_lock(&data->prints);
    if(msg == EATING)
        printf("%zu %d is eating", get_time(), philo);
    else if(msg == SLEEPING)
        printf("%zu %d is sleeping", get_time(), philo);
    else if(msg == THINKING)
        printf("%zu %d is thinking", get_time(), philo);
    else if(msg == DYING)
        printf("%zu %d died", get_time(), philo);
    else if(msg == FORK)
        printf("%zu %d has taken a fork", get_time(), philo);
    pthread_mutex_unlock(&data->prints);
}

int ft_atoi(char *str, size_t *dst)
{
    int i = 0;
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