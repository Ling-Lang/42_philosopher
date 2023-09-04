/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:37:43 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/04 18:44:54 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

void* thread_function(void* arg) 
{
	// if(*(int*)arg == 0)
		// return 0;
    // Code executed by the new thread goes here
	// usleep(200);
	// write(1, "thread\n", 7);
  	struct timeval current_time;
  	gettimeofday(&current_time, NULL);
  	printf("Thread %i, seconds : %ld\nmicro seconds : %ld\n",arg,
    current_time.tv_sec, current_time.tv_usec);
    // printf("Hello from thread: %i\n", (int)arg);
    return NULL;
}

int main(int argc, char *argv[])
{
	ft_is_input_valid(argc, argv);
	int thread_num = atoi(argv[1]);
    pthread_t thread_id[thread_num];
	int i = 1;
	while(i <= thread_num)
	{
		printf("Started thread %i\n",i);
    	pthread_create(&thread_id[i], NULL, thread_function, i);
		i++;
	}
	i = 1;
    // Wait for the new thread to complete
	while(i <= thread_num)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
    printf("asd");
    return 0;
}
