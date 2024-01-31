/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:48 by codespace         #+#    #+#             */
/*   Updated: 2024/01/31 21:05:43 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	has_ended(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&data->mdata);
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&data->fmutex);
		if (data->philos[i].last_meal >= data->t_die)
		{
			pthread_mutex_unlock(&data->fmutex);
			ft_print("has died", &data->philos[i]);
			pthread_mutex_lock(&data->fmutex);
			data->end = 1;
			pthread_mutex_unlock(&data->fmutex);
			break;
		}
		pthread_mutex_unlock(&data->fmutex);
		pthread_mutex_lock(&data->fmutex);
		if (data->philo_full == data->total_philos)
		{
			data->end = 1;
			pthread_mutex_unlock(&data->fmutex);
			break;
		}
		pthread_mutex_unlock(&data->fmutex);
		i ++;
		if(i == data->total_philos)
			i = 0;
	}
}

void	routine_thread(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork);
	ft_print("has taken a fork (right)", philo);
	pthread_mutex_lock(philo->lfork);
	ft_print("has taken a fork(left)", philo);
	pthread_mutex_lock(&philo->emutex);
	ft_print("is eating", philo);
	philo->meals++;
	philo->last_meal = get_time(philo->data->t_start);
	if (philo->meals == philo->data->max_meals)
	{
		pthread_mutex_lock(&philo->data->fmutex);
		philo->data->philo_full++;
		pthread_mutex_unlock(&philo->data->fmutex);
	}
	pthread_mutex_unlock(&philo->emutex);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
	ft_print("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		end;

	philo = arg;
	end = 0;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10);
	while (!end)
	{
		routine_thread(philo);
		pthread_mutex_lock(&philo->data->fmutex);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->fmutex);
	}
	return ((void *)NULL);
}