/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:19:15 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:01:11 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	threads_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		data->threads[i] = i;
		if (pthread_create(&data->threads[i], NULL, &routine, &(data)->philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	philos_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->total_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals = 0;
		data->philos[i].full = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].rfork, NULL);
		pthread_mutex_init(&data->philos[i].emutex, NULL);
		i++;
	}
	data->philos[0].lfork = &data->philos[data->total_philos - 1].rfork;
	i = 1;
	while (i < data->total_philos)
	{
		data->philos[i].lfork = &data->philos[i - 1].rfork;
		i++;
	}
}

int	data_init(t_data *data)
{
	data->end = 0;
	data->start = 0;
	pthread_mutex_init(&data->mdata, NULL);
	pthread_mutex_init(&data->wmutex, NULL);
	pthread_mutex_init(&data->dmutex, NULL);
	pthread_mutex_lock(&data->mdata);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
		return (0);
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->total_philos);
	if (!data->threads)
		return (0);
	philos_init(data);
	return (1);
}