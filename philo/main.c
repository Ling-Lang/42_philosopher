/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:37:43 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/05 13:47:30 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int main(int argc, char *argv[])
{
	t_data data;
	ft_is_input_valid(argc, argv, &data);
	ft_init(&data);
	ft_init_mutex(&data);
	if(ft_begin(&data))
		ft_exit(5);
	pthread_mutex_lock(&data.death_mutex);
	pthread_mutex_unlock(&data.death_mutex);
	ft_clean(&data);
    return (0);
}
