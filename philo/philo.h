/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:50:48 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 13:42:45 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#	define RED "\e[0;31m"
#	define YEL "\e[0;33m"
#	define WHT "\e[0;37m"
#	define BLU "\e[0;34m"
#   define EATING 1
#   define SLEEPING 2
#   define THINKING 3
#   define DYING 4
#   define FORK 5
// #   define LAST_MEAL 6
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
struct s_data;
typedef struct s_philo
{
    size_t num;
    size_t last_meal;
    size_t already_eaten;
    size_t is_eating;
    size_t limit;
    size_t lfork;
    size_t rfork;
    struct s_data *data;
} t_philo;
typedef struct s_data 
{
    size_t time_to_eat;
    size_t time_to_die;
    size_t time_to_sleep;
    size_t ammount_of_food;
    size_t completed;
    size_t num_of_philo;
    t_philo *philo;
    int *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t *fork_mutex;
    pthread_mutex_t death_mutex;
} t_data;

void ft_log(int msg, size_t time, t_philo *philo);
void ft_is_input_valid(int argc, char *argv[], t_data *data);
void	ft_usleep(size_t ms);
size_t	get_time(void);
int ft_atoi(char *str, size_t *dst);
void ft_exit(int flag);
void ft_init(t_data *data);
void ft_init_mutex(t_data *data);
void ft_clean(t_data *data);
int is_dead(t_philo *philo);
int ft_begin(t_data *data);
int yoink_forks(t_philo *philo);
int free_forks(t_philo *philo);
int eat(t_philo *philo);
#endif