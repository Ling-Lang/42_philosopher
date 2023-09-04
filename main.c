/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:37:43 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:35 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int main(int argc, char *argv[])
// {
// 	if(argc != 6)
// 	{
// 		printf("Error\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	printf("Yaaaaay");
// }
void* thread_function(void* arg) 
{
	// if(*(int*)arg == 0)
		// return 0;
    // Code executed by the new thread goes here
    printf("Hello from thread: %i\n", (int)arg);
    return NULL;
}

int main(int argc, char *argv[]) {
	int thread_num = atoi(argv[1]);
    pthread_t thread_id[thread_num];
	int i =1;
	while(i < thread_num)
	{
		printf("Started thread %i\n",i);
    	pthread_create(&thread_id[i], NULL, thread_function, i);
		i++;
	}
	i = 1;
    // Code executed by the main thread goes here
    printf("Hello from the main thread!\n");
    
    // Wait for the new thread to complete
	while(i < thread_num)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
    
    return 0;
}
