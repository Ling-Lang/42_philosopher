/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:50:48 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:16:11 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define RED "\e[0;31m"
# define YEL "\e[0;33m"
# define WHT "\e[0;37m"
# define BLU "\e[0;34m"
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DYING 4
# define FORK 5
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	struct timeval	*start_time;
	unsigned int	num_of_philo;
	bool			limited_meals;
	int				num_of_meals;
	size_t			tte;
	size_t			tts;
	size_t			ttd;
	size_t			last_meal;
	size_t			philo_id;
	int				state;
	int				*is_dead;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	meal_time_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	num_of_meals_mutex;
	struct s_data	*next;
}					t_data;
int					ft_atoi(const char *str);
int					ft_validate_input(int argc, char **argv);
int					ft_init(t_data *data, int argc, char **argv);
unsigned int		ft_get_time(struct timeval start_time);
void				ft_print(char *str, t_data *data);
void				*philo_routine(void *v_data);
void				*watcher_routine(void *v_data);
void				ft_clean(pthread_t *t_id, t_data *data);
void				ft_exit(int flag);
int					ft_fill_data_1(int argc, char **argv, t_data *data,
						struct timeval *start);
#endif