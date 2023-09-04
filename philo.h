/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:50:48 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/04 21:36:15 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H_
#define _PHILO_H_
#	define RED "\e[0;31m"
#	define YEL "\e[0;33m"
#	define WHT "\e[0;37m"
#	define BLU "\e[0;34m"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data 
{
    size_t time_to_eat;
    size_t time_to_die;
    size_t time_to_sleep;
    size_t food;
    size_t completed;
    pthread_mutex_t prints;
    pthread_mutex_t forks;
    pthread_mutex_t death;
} t_data;

int ft_is_input_valid(int argc, char *argv[]);
#endif