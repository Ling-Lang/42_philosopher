/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:50:48 by jkulka            #+#    #+#             */
/*   Updated: 2023/09/04 18:31:23 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H_
#define _PHILO_H_
#	define RED "\e[0;31m"
#	define YEL "\e[0;33m"
#	define WHT "\e[0;37m"
#	define BLU "\e[0;34m"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int ft_is_input_valid(int argc, char *argv[]);
#endif