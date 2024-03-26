/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:48 by codespace         #+#    #+#             */
/*   Updated: 2024/03/23 18:16:33 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_full(t_data *data)
{
	if (data->philo_full == data->total_philos)
	{
		data->end = 1;
		pthread_mutex_unlock(&data->fmutex);
		return (1);
	}
	return (0);
}

void	has_ended(t_data *data)
{
	int	i;
	int	last_meal;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&data->philos[i].emutex);
		last_meal = data->philos[i].last_meal;
		pthread_mutex_unlock(&data->philos[i].emutex);
		if (get_time(data->t_start) - last_meal >= data->t_die)
		{
			pthread_mutex_lock(&data->fmutex);
			data->end = 1;
			pthread_mutex_unlock(&data->fmutex);
			ft_print("has died", &data->philos[i]);
			break ;
		}
		pthread_mutex_lock(&data->fmutex);
		if (is_full(data))
			break ;
		pthread_mutex_unlock(&data->fmutex);
		i ++;
		if (i == data->total_philos)
			i = 0;
	}
}

void	routine_thread(t_philo *philo, long t_start)
{
	pthread_mutex_lock(&philo->rfork);
	ft_print("has taken a fork (right)", philo);
	pthread_mutex_lock(philo->lfork);
	ft_print("has taken a fork(left)", philo);
	pthread_mutex_lock(&philo->emutex);
	ft_print("is eating", philo);
	philo->meals++;
	philo->last_meal = get_time(t_start);
	if (philo->meals == philo->data->max_meals)
	{
		pthread_mutex_lock(&philo->data->fmutex);
		philo->data->philo_full++;
		pthread_mutex_unlock(&philo->data->fmutex);
	}
	pthread_mutex_unlock(&philo->emutex);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->rfork);
	ft_print("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
	ft_print("is thinking", philo);
}

void	routine_one(t_philo *philo)
{
	ft_print("has taken a fork (right)", philo);
	ft_usleep(philo->data->t_die);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		end;
	long	t_start;

	philo = arg;
	end = 0;
	pthread_mutex_lock(&philo->data->mdata);
	t_start = philo->data->t_start;
	pthread_mutex_unlock(&philo->data->mdata);
	if (philo->data->total_philos == 1)
	{
		routine_one(philo);
		return ((void *) NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10);
	while (!end)
	{
		routine_thread(philo, t_start);
		pthread_mutex_lock(&philo->data->fmutex);
		end = philo->data->end;
		pthread_mutex_unlock(&philo->data->fmutex);
	}
	return ((void *) NULL);
}
