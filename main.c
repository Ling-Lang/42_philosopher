/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:37:43 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/04 21:47:09 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
size_t	get_time(void);
pthread_mutex_t mutex;
void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Hello from thread: %i\n", (int)arg);
	printf("%d", get_time());
    pthread_mutex_unlock(&mutex);
    return NULL;
}

size_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t ms)
{
	size_t	end;

	end = get_time() + ms;
	while (get_time() < end)
		usleep(ms / 1000);
}
int main(int argc, char *argv[])
{
	// ft_is_input_valid(argc, argv);
	int thread_num = atoi(argv[1]);
    pthread_t *thread_id = malloc(thread_num * sizeof(pthread_t));
	int i = 1;
	pthread_mutex_init(&mutex, NULL);
	while(i <= thread_num)
	{
		printf("Started thread %i\n",i);
    	pthread_create(&thread_id[i], NULL, thread_function, i);
		ft_usleep(100);
		i++;
	}
	i = 1;
    // Wait for the new thread to complete
	while(i <= thread_num)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
    printf("asd");
    return 0;
}
