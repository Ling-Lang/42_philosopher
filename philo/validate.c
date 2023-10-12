/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:04:06 by jkulka            #+#    #+#             */
/*   Updated: 2023/10/12 20:21:20 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		ft_exit(1);
		return (0);
	}
	if (!(ft_is_num(argv[1]) && ft_atoi(argv[1]) > 0))
	{
		ft_exit(2);
		return (0);
	}
	while (++i < argc)
	{
		if (!(ft_is_num(argv[i]) && ft_atoi(argv[i]) >= 0))
		{
			ft_exit(2);
			return (0);
		}
	}
	return (1);
}
