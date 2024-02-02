/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:41:24 by mlopez-i          #+#    #+#             */
/*   Updated: 2024/02/02 17:44:01 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_error(int error)
{
	if (error == ARGS_ERROR)
	{
		write(1, "Wrong arguments. Try: \n", 24);
		write(1, "- number_of_philosophers\n- time_to_die\n", 40);
		write(1, "- time_to_eat\n- time_to_sleep\n", 31);
		write(1, "- [number_of_times_each_philosopher_must_eat]\n", 47);
	}
	if (error == INIT_ERROR)
		write(1, "Initialization error\n", 22);
	if (error == THREAD_ERROR)
		write(1, "Error creating threads\n", 24);
	if (error == GET_TIME)
		write(1, "gettimeofday() FAILURE\n", 24);
}

void	ft_free(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->threads)
		free(data->threads);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->total_philos)
		pthread_join(data->threads[i], NULL);
	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_destroy(&data->philos[i].emutex);
		pthread_mutex_destroy(&data->philos[i].rfork);
		i++;
	}
	pthread_mutex_destroy(&data->mdata);
	pthread_mutex_destroy(&data->wmutex);
	pthread_mutex_destroy(&data->fmutex);
	ft_free(data);
}
