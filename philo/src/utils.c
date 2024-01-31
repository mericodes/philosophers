/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:56:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 19:55:55 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(long t_start)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000) - t_start);
}

void	ft_usleep(long time)
{
	time += ft_get_time();
	while (ft_get_time() <= time)
		usleep(200);
}

void	ft_print(char *str, t_philo *philo)
{
	int	dead;
	int	time;
	
	pthread_mutex_lock(&philo->data->wmutex);
	pthread_mutex_lock(&philo->data->dmutex);
	dead = philo->data->end;
	pthread_mutex_unlock(&philo->data->dmutex);
	if (!dead)
		printf("%lu %i %s\n", get_time(philo->data->t_start), philo->id, str);
	pthread_mutex_unlock(&philo->data->wmutex);
}

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

	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_destroy(&data->philos[i].emutex);
		pthread_mutex_destroy(&data->philos[i].rfork);
		i++;
	}
	pthread_mutex_destroy(&data->mdata);
	pthread_mutex_destroy(&data->wmutex);
	pthread_mutex_destroy(&data->dmutex);
	ft_free(data);
}
