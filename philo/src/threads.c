/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:16:00 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/01/15 16:16:46 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_routine(void *dat)
{
	t_data	*data;

	data = dat;
	printf("HOLI\n");
	return (NULL);
}

int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		data->philos[i].philo = i + 1;
		data->philos[i].eating = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].r_fork = &data->forks[i];
		if (i == 0 && data->total_philos > 1)
			data->philos[i].l_fork = &data->forks[data->total_philos - 1];
		else if (data->total_philos > 1)
			data->philos[i].l_fork = &data->forks[i - 1];
		else if (data->total_philos == 1)
			data->philos[i].l_fork = NULL;
		// printf("PHILO ID::::::::; %i  ", data->philos[i].philo);
		// printf("RIGHT FORK ID::::::::; %i  ", data->philos[i].r_fork->fork_id);
		// printf("LEFT FORK ID::::::::; %i\n", data->philos[i].l_fork->fork_id);
		if (pthread_create(&data->philos[i].thread,
				NULL, &ft_routine, data) != 0)
			return (0);
		i++;
	}
	return (1);
}